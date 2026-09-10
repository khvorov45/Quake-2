/*
============================================================================
 QUAK2SP

 Single translation unit for the Quake 2 single-player build.

 Every source file of the engine, campaign game logic, and GL renderer is
 #included below; build_sp_clang.bat feeds this one file to clang-cl and
 out pops debug\quake2.exe. The DLL boundaries (gamex86.dll, ref_gl.dll)
 are gone — game logic and renderer are statically linked.

 Order matters only for macros/statics that leak across inclusions; the
 sequence follows the layout of the original three binaries.
============================================================================
*/

/*
 * Order-sensitive pre-pass:
 * 1. qcommon.h first  — sets up q_shared.h and, critically, the svc_/clc_
 *    protocol constants AS AN ENUM, because g_local.h re-defines a subset of
 *    them as object-like macros (same values, by design).  Enum first,
 *    macros second, or qcommon.h's enum turns into preprocessor mush.
 * 2. g_local.h second — defines GAME_INCLUDE before game.h is ever reached,
 *    so the whole TU compiles against the FULL gclient_s/edict_s layouts
 *    (the engine-visible short structs in game.h are strict prefixes of
 *    them, so server code compiles identically against the full layout).
 *    Every later server.h/game.h inclusion is then a harmless no-op.
 */
#include "qcommon\qcommon.h"
#include "game\g_local.h"

/* shared types/math — compiled once here instead of into exe+2 dlls */
#include "game\q_shared.c"

/* engine core */
#include "qcommon\cmd.c"
#include "qcommon\cmodel.c"
#include "qcommon\common.c"
#include "qcommon\crc.c"
#include "qcommon\cvar.c"
#include "qcommon\files.c"
#include "qcommon\md4.c"
#include "qcommon\net_chan.c"
#include "qcommon\pmove.c"

/* server */
#include "server\sv_ccmds.c"
#include "server\sv_ents.c"
#include "server\sv_game.c"
#include "server\sv_init.c"
#include "server\sv_main.c"
#include "server\sv_send.c"
#include "server\sv_user.c"
#include "server\sv_world.c"

/* client */
#include "client\cl_cin.c"
#include "client\cl_ents.c"
#include "client\cl_fx.c"
#include "client\cl_input.c"
#include "client\cl_inv.c"
#include "client\cl_main.c"
#include "client\cl_newfx.c"
#include "client\cl_parse.c"
#include "client\cl_pred.c"
#include "client\cl_scrn.c"
#include "client\cl_tent.c"
#include "client\cl_view.c"
#include "client\console.c"
#include "client\keys.c"
#include "client\menu.c"
#include "client\qmenu.c"
#include "client\snd_dma.c"
#include "client\snd_mem.c"
#include "client\snd_mix.c"
#include "client\x86.c"

/* muzzle-flash tables shared by client fx and monsters */
#include "game\m_flash.c"

/* campaign game logic (formerly gamex86.dll) */
#include "game\g_ai.c"
#include "game\g_chase.c"
#include "game\g_cmds.c"
#include "game\g_combat.c"
#include "game\g_func.c"
#include "game\g_items.c"
#include "game\g_main.c"
#include "game\g_misc.c"
#include "game\g_monster.c"
#include "game\g_phys.c"
#include "game\g_save.c"
#include "game\g_spawn.c"
#include "game\g_svcmds.c"
#include "game\g_target.c"
#include "game\g_trigger.c"
#include "game\g_turret.c"
#include "game\g_utils.c"
#include "game\g_weapon.c"
#include "game\m_actor.c"
#include "game\m_berserk.c"
#include "game\m_boss2.c"
#include "game\m_boss3.c"
#include "game\m_boss31.c"
#include "game\m_boss32.c"
#include "game\m_brain.c"
#include "game\m_chick.c"
#include "game\m_flipper.c"
#include "game\m_float.c"
#include "game\m_flyer.c"
#include "game\m_gladiator.c"
#include "game\m_gunner.c"
#include "game\m_hover.c"
#include "game\m_infantry.c"
#include "game\m_insane.c"
#include "game\m_medic.c"
#include "game\m_move.c"
#include "game\m_mutant.c"
#include "game\m_parasite.c"
#include "game\m_soldier.c"
#include "game\m_supertank.c"
#include "game\m_tank.c"
#include "game\p_client.c"
#include "game\p_hud.c"
#include "game\p_trail.c"
#include "game\p_view.c"
#include "game\p_weapon.c"

/* OpenGL renderer (formerly ref_gl.dll) */
#include "ref_gl\gl_draw.c"
#include "ref_gl\gl_image.c"
#include "ref_gl\gl_light.c"
#include "ref_gl\gl_mesh.c"
#include "ref_gl\gl_model.c"
#include "ref_gl\gl_rmain.c"
#include "ref_gl\gl_rmisc.c"
#include "ref_gl\gl_rsurf.c"
#include "ref_gl\gl_warp.c"

/* Win32 platform glue */
#include "win32\cd_win.c"
#include "win32\conproc.c"
#include "win32\in_win.c"
#include "win32\net_wins.c"
#include "win32\q_shwin.c"
#include "win32\snd_win.c"
#include "win32\sys_win.c"
#include "win32\vid_dll.c"
#include "win32\vid_menu.c"
#include "win32\glw_imp.c"
#include "win32\qgl_win.c"
