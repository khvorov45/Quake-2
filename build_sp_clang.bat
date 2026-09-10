@echo off
rem ============================================================================
rem  build_sp_clang.bat
rem
rem  Builds everything needed to play the Quake 2 single-player campaign,
rem  using clang, in ONE compiler invocation: q2sp.c is a single translation
rem  unit that #includes every source file of the engine, the campaign game
rem  logic and the OpenGL renderer. The DLL boundaries (gamex86.dll,
rem  ref_gl.dll) are gone — game logic and renderer are statically linked
rem  via the GAME_HARD_LINKED / REF_HARD_LINKED paths id left in the code.
rem
rem  DEBUG BUILD ONLY: no optimisations, full debug info (.pdb next to
rem  the exe), debug CRT. There is deliberately no release config.
rem
rem  Output (relative to this repo):
rem    debug\quake2.exe          the whole game (engine+game+renderer)
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
rem  /DGAME_HARD_LINKED /DREF_HARD_LINKED
rem                        statically link game logic & renderer into the exe
rem                        (skips their DLL-only Sys_Error/Com_Printf shims)
rem  /Od                   debug build: no optimisations, so single-stepping
rem                        and variable inspection actually work
rem  /Z7                   debug info in the .obj; lld-link turns it into a
rem                        real .pdb via /DEBUG below
rem  /MTd                  static debug CRT to match the unoptimised code
rem  -fno-strict-aliasing  this codebase type-puns floats<->longs everywhere
rem  -fcommon + /w         forgive the duplicate tentative definitions and
rem                        the wall of 1997-style warnings
rem  -Wno-implicit-*       MSVC6-era code leans on implicit int returns and
rem                        undeclared functions (hard errors since C99)
rem  -Wno-incompatible-*  1997 void** / byte** loose pointer passing MSVC
rem  -Wno-int-conversion   accepted without a word

set "FLAGS=/nologo /w /Od /Z7 /MTd -m32 /D_DEBUG /DWIN32 /DC_ONLY /DGAME_HARD_LINKED /DREF_HARD_LINKED -fno-strict-aliasing -fcommon -Wno-implicit-int -Wno-implicit-function-declaration -Wno-incompatible-pointer-types -Wno-int-conversion"

rem  /DEBUG makes the linker emit a .pdb (full symbols) next to the exe
set "LINKDEBUG=/DEBUG"

if not exist debug mkdir debug
if not exist debug\baseq2 mkdir debug\baseq2
if not exist .sp_obj mkdir .sp_obj

rem ============================================================================
rem  One invocation — q2sp.c compiles engine + game + renderer as a single
rem  translation unit and links quake2.exe (dsound/opengl32 are pulled in
rem  dynamically at runtime by snd_win.c / qgl_win.c, so no import libs)
rem ============================================================================
"%CLANG%" %FLAGS% /Fo.sp_obj\ /Fedebug\quake2.exe q2sp.c ^
	/link %LINKDEBUG% /SUBSYSTEM:WINDOWS winmm.lib wsock32.lib kernel32.lib user32.lib gdi32.lib || goto fail

rmdir /s /q .sp_obj
echo.
echo ============ build OK (debug, unity) ============
echo   debug\quake2.exe  (+ quake2.pdb)
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
