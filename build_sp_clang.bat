@echo off
rem ============================================================================
rem  build_sp_clang.bat
rem
rem  Builds everything needed to play the Quake 2 single-player campaign,
rem  using clang, in the minimum number of compiler invocations: three
rem  (one output binary per invocation — a single clang-cl call compiles
rem  every source file of a target and links it).
rem
rem  DEBUG BUILD ONLY: no optimisations, full debug info (.pdb next to
rem  every binary), debug CRT. There is deliberately no release config.
rem
rem  Outputs (relative to this repo):
rem    debug\quake2.exe          engine (qcommon+server+client+win32 glue)
rem    debug\ref_gl.dll          OpenGL renderer
rem    debug\baseq2\gamex86.dll  game logic DLL (the campaign code)
rem
rem  Renderer note: quake2.exe loads a renderer DLL dynamically at runtime
rem  (vid_ref cvar). We build ref_gl only — the OpenGL renderer needs just
rem  gdi32/user32 (it LoadLibrary's opengl32.dll itself), whereas ref_soft
rem  needs legacy DirectDraw headers. ref_gl is also the default on
rem  Q2-era installs; copy your pak0.pak + maps into debug\baseq2 and run.
rem
rem  Toolchain: clang-cl from LLVM (C:\Programs\LLVM) + MSVC/Windows SDK
rem  environment via vcvarsall (Visual Studio 18 Community).
rem ============================================================================
setlocal

rem ---- toolchain -------------------------------------------------------------

set "CLANG=C:\Programs\LLVM\bin\clang-cl.exe"
if not exist "%CLANG%" set "CLANG=clang-cl"

if not defined VCINSTALLDIR (
	call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 || exit /b 1
)

pushd "%~dp0"

rem ---- shared flags ----------------------------------------------------------
rem  -m32                  the 1997 engine is only well-shaken-out as 32-bit
rem  /DC_ONLY              cuts every id386 asm path over to its C twin so no
rem                        30-year-old naked MMX asm has to be modernised
rem  /Od                   debug build: no optimisations, so single-stepping
rem                        and variable inspection actually work
rem  /Z7                   debug info in every .obj (no per-compiler .pdb to
rem                        collide in the shared .sp_obj dir); lld-link turns
rem                        it into a real .pdb via /DEBUG below
rem  /MTd                  static debug CRT to match the unoptimised code
rem  -fno-strict-aliasing  this codebase type-puns floats<->longs everywhere
rem  -fcommon + /w         forgive the duplicate tentative definitions and
rem                        the wall of 1997-style warnings
rem  -Wno-implicit-*       MSVC6-era code leans on implicit int returns and
rem                        undeclared functions (hard errors since C99)
rem  -Wno-incompatible-*  1997 void** / byte** loose pointer passing MSVC
rem  -Wno-int-conversion   accepted without a word

set "FLAGS=/nologo /w /Od /Z7 /MTd -m32 /D_DEBUG /DWIN32 /DC_ONLY -fno-strict-aliasing -fcommon -Wno-implicit-int -Wno-implicit-function-declaration -Wno-incompatible-pointer-types -Wno-int-conversion"

rem  /DEBUG makes the linker emit a .pdb (full symbols) next to each binary
set "LINKDEBUG=/DEBUG"

if not exist debug mkdir debug
if not exist debug\baseq2 mkdir debug\baseq2
if not exist .sp_obj mkdir .sp_obj

rem ============================================================================
rem  Invocation 1 of 3 — gamex86.dll : the single-player campaign itself
rem ============================================================================
"%CLANG%" %FLAGS% /LD /Fo.sp_obj\ /Fedebug\baseq2\gamex86.dll ^
	game\g_ai.c game\g_chase.c game\g_cmds.c game\g_combat.c game\g_func.c ^
	game\g_items.c game\g_main.c game\g_misc.c game\g_monster.c game\g_phys.c ^
	game\g_save.c game\g_spawn.c game\g_svcmds.c game\g_target.c game\g_trigger.c ^
	game\g_turret.c game\g_utils.c game\g_weapon.c game\m_actor.c game\m_berserk.c ^
	game\m_boss2.c game\m_boss3.c game\m_boss31.c game\m_boss32.c game\m_brain.c ^
	game\m_chick.c game\m_flash.c game\m_flipper.c game\m_float.c game\m_flyer.c ^
	game\m_gladiator.c game\m_gunner.c game\m_hover.c game\m_infantry.c ^
	game\m_insane.c game\m_medic.c game\m_move.c game\m_mutant.c game\m_parasite.c ^
	game\m_soldier.c game\m_supertank.c game\m_tank.c game\p_client.c game\p_hud.c ^
	game\p_trail.c game\p_view.c game\p_weapon.c game\q_shared.c ^
	/link %LINKDEBUG% /DEF:game\game.def kernel32.lib user32.lib winmm.lib || goto fail

rem ============================================================================
rem  Invocation 2 of 3 — ref_gl.dll : OpenGL renderer (loaded at runtime)
rem ============================================================================
"%CLANG%" %FLAGS% /LD /Fo.sp_obj\ /Fedebug\ref_gl.dll ^
	ref_gl\gl_draw.c ref_gl\gl_image.c ref_gl\gl_light.c ref_gl\gl_mesh.c ^
	ref_gl\gl_model.c ref_gl\gl_rmain.c ref_gl\gl_rmisc.c ref_gl\gl_rsurf.c ^
	ref_gl\gl_warp.c win32\glw_imp.c win32\qgl_win.c win32\q_shwin.c game\q_shared.c ^
	/link %LINKDEBUG% /DEF:ref_gl\ref_gl.def kernel32.lib user32.lib gdi32.lib winmm.lib || goto fail

rem ============================================================================
rem  Invocation 3 of 3 — quake2.exe : qcommon + server + client + win32 glue
rem ============================================================================
"%CLANG%" %FLAGS% /Fo.sp_obj\ /Fedebug\quake2.exe ^
	qcommon\cmd.c qcommon\cmodel.c qcommon\common.c qcommon\crc.c qcommon\cvar.c ^
	qcommon\files.c qcommon\md4.c qcommon\net_chan.c qcommon\pmove.c ^
	server\sv_ccmds.c server\sv_ents.c server\sv_game.c server\sv_init.c ^
	server\sv_main.c server\sv_send.c server\sv_user.c server\sv_world.c ^
	client\cl_cin.c client\cl_ents.c client\cl_fx.c client\cl_input.c client\cl_inv.c ^
	client\cl_main.c client\cl_newfx.c client\cl_parse.c client\cl_pred.c ^
	client\cl_scrn.c client\cl_tent.c client\cl_view.c client\console.c client\keys.c ^
	client\menu.c client\qmenu.c client\snd_dma.c client\snd_mem.c client\snd_mix.c ^
	client\x86.c game\m_flash.c game\q_shared.c ^
	win32\cd_win.c win32\conproc.c win32\in_win.c win32\net_wins.c win32\q_shwin.c ^
	win32\snd_win.c win32\sys_win.c win32\vid_dll.c win32\vid_menu.c ^
	/link %LINKDEBUG% /SUBSYSTEM:WINDOWS winmm.lib wsock32.lib kernel32.lib user32.lib gdi32.lib || goto fail

rmdir /s /q .sp_obj
echo.
echo ============ build OK (debug) ============
echo   debug\quake2.exe
echo   debug\ref_gl.dll
echo   debug\baseq2\gamex86.dll
echo   (+ .pdb next to each binary)
echo.
echo Copy your Quake 2 data files (pak0.pak, maps, ...) into debug\baseq2
echo then run debug\quake2.exe .
popd
endlocal
exit /b 0

:fail
echo BUILD FAILED (see errors above)
rmdir /s /q .sp_obj 2>nul
popd
endlocal
exit /b 1
