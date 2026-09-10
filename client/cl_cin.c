/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
/* ============ begin inlined header: client/client.h ============ */
/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
#ifndef CLIENT_H
#define CLIENT_H

// client.h -- primary header for client

//define	PARANOID			// speed sapping error checking

#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/* ============ begin inlined header: client/ref.h ============ */
/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#ifndef CLIENT_REF_H
#define CLIENT_REF_H

/* already inlined above: qcommon/qcommon.h */

#define	MAX_DLIGHTS		32
#define	MAX_ENTITIES	128
#define	MAX_PARTICLES	4096
#define	MAX_LIGHTSTYLES	256

#define POWERSUIT_SCALE		4.0F

#define SHELL_RED_COLOR		0xF2
#define SHELL_GREEN_COLOR	0xD0
#define SHELL_BLUE_COLOR	0xF3

#define SHELL_RG_COLOR		0xDC
//#define SHELL_RB_COLOR		0x86
#define SHELL_RB_COLOR		0x68
#define SHELL_BG_COLOR		0x78

//ROGUE
#define SHELL_DOUBLE_COLOR	0xDF // 223
#define	SHELL_HALF_DAM_COLOR	0x90
#define SHELL_CYAN_COLOR	0x72
//ROGUE

#define SHELL_WHITE_COLOR	0xD7

typedef struct entity_s
{
	struct model_s		*model;			// opaque type outside refresh
	float				angles[3];

	/*
	** most recent data
	*/
	float				origin[3];		// also used as RF_BEAM's "from"
	int					frame;			// also used as RF_BEAM's diameter

	/*
	** previous data for lerping
	*/
	float				oldorigin[3];	// also used as RF_BEAM's "to"
	int					oldframe;

	/*
	** misc
	*/
	float	backlerp;				// 0.0 = current, 1.0 = old
	int		skinnum;				// also used as RF_BEAM's palette index

	int		lightstyle;				// for flashing entities
	float	alpha;					// ignore if RF_TRANSLUCENT isn't set

	struct image_s	*skin;			// NULL for inline skin
	int		flags;

} entity_t;

#define ENTITY_FLAGS  68

typedef struct
{
	vec3_t	origin;
	vec3_t	color;
	float	intensity;
} dlight_t;

typedef struct
{
	vec3_t	origin;
	int		color;
	float	alpha;
} particle_t;

typedef struct
{
	float		rgb[3];			// 0.0 - 2.0
	float		white;			// highest of rgb
} lightstyle_t;

typedef struct
{
	int			x, y, width, height;// in virtual screen coordinates
	float		fov_x, fov_y;
	float		vieworg[3];
	float		viewangles[3];
	float		blend[4];			// rgba 0-1 full screen blend
	float		time;				// time is uesed to auto animate
	int			rdflags;			// RDF_UNDERWATER, etc

	byte		*areabits;			// if not NULL, only areas with set bits will be drawn

	lightstyle_t	*lightstyles;	// [MAX_LIGHTSTYLES]

	int			num_entities;
	entity_t	*entities;

	int			num_dlights;
	dlight_t	*dlights;

	int			num_particles;
	particle_t	*particles;
} refdef_t;



#define	API_VERSION		3

//
// these are the functions exported by the refresh module
//
typedef struct
{
	// if api_version is different, the dll cannot be used
	int		api_version;

	// called when the library is loaded
	qboolean	(*Init) ( void *hinstance, void *wndproc );

	// called before the library is unloaded
	void	(*Shutdown) (void);

	// All data that will be used in a level should be
	// registered before rendering any frames to prevent disk hits,
	// but they can still be registered at a later time
	// if necessary.
	//
	// EndRegistration will free any remaining data that wasn't registered.
	// Any model_s or skin_s pointers from before the BeginRegistration
	// are no longer valid after EndRegistration.
	//
	// Skins and images need to be differentiated, because skins
	// are flood filled to eliminate mip map edge errors, and pics have
	// an implicit "pics/" prepended to the name. (a pic name that starts with a
	// slash will not use the "pics/" prefix or the ".pcx" postfix)
	void	(*BeginRegistration) (char *map);
	struct model_s *(*RegisterModel) (char *name);
	struct image_s *(*RegisterSkin) (char *name);
	struct image_s *(*RegisterPic) (char *name);
	void	(*SetSky) (char *name, float rotate, vec3_t axis);
	void	(*EndRegistration) (void);

	void	(*RenderFrame) (refdef_t *fd);

	void	(*DrawGetPicSize) (int *w, int *h, char *name);	// will return 0 0 if not found
	void	(*DrawPic) (int x, int y, char *name);
	void	(*DrawStretchPic) (int x, int y, int w, int h, char *name);
	void	(*DrawChar) (int x, int y, int c);
	void	(*DrawTileClear) (int x, int y, int w, int h, char *name);
	void	(*DrawFill) (int x, int y, int w, int h, int c);
	void	(*DrawFadeScreen) (void);

	// Draw images for cinematic rendering (which can have a different palette). Note that calls
	void	(*DrawStretchRaw) (int x, int y, int w, int h, int cols, int rows, byte *data);

	/*
	** video mode and refresh state management entry points
	*/
	void	(*CinematicSetPalette)( const unsigned char *palette);	// NULL = game palette
	void	(*BeginFrame)( float camera_separation );
	void	(*EndFrame) (void);

	void	(*AppActivate)( qboolean activate );

} refexport_t;

//
// these are the functions imported by the refresh module
//
typedef struct
{
	void	(*Sys_Error) (int err_level, char *str, ...);

	void	(*Cmd_AddCommand) (char *name, void(*cmd)(void));
	void	(*Cmd_RemoveCommand) (char *name);
	int		(*Cmd_Argc) (void);
	char	*(*Cmd_Argv) (int i);
	void	(*Cmd_ExecuteText) (int exec_when, char *text);

	void	(*Con_Printf) (int print_level, char *str, ...);

	// files will be memory mapped read only
	// the returned buffer may be part of a larger pak file,
	// or a discrete file from anywhere in the quake search path
	// a -1 return means the file does not exist
	// NULL can be passed for buf to just determine existance
	int		(*FS_LoadFile) (char *name, void **buf);
	void	(*FS_FreeFile) (void *buf);

	// gamedir will be the current directory that generated
	// files should be stored to, ie: "f:\quake\id1"
	char	*(*FS_Gamedir) (void);

	cvar_t	*(*Cvar_Get) (char *name, char *value, int flags);
	cvar_t	*(*Cvar_Set)( char *name, char *value );
	void	 (*Cvar_SetValue)( char *name, float value );

	qboolean	(*Vid_GetModeInfo)( int *width, int *height, int mode );
	void		(*Vid_MenuInit)( void );
	void		(*Vid_NewWindow)( int width, int height );
} refimport_t;


// this is the only function actually exported at the linker level
typedef	refexport_t	(*GetRefAPI_t) (refimport_t);

#endif	// CLIENT_REF_H
/* ============ end inlined header: client/ref.h ============ */

/* ============ begin inlined header: client/vid.h ============ */
/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
// vid.h -- video driver defs

typedef struct vrect_s
{
	int				x,y,width,height;
} vrect_t;

typedef struct
{
	int		width;		
	int		height;
} viddef_t;

extern	viddef_t	viddef;				// global video state

// Video module initialisation etc
void	VID_Init (void);
void	VID_Shutdown (void);
void	VID_CheckChanges (void);

void	VID_MenuInit( void );
void	VID_MenuDraw( void );
const char *VID_MenuKey( int );
/* ============ end inlined header: client/vid.h ============ */
/* ============ begin inlined header: client/screen.h ============ */
/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
// screen.h

void	SCR_Init (void);

void	SCR_UpdateScreen (void);

void	SCR_SizeUp (void);
void	SCR_SizeDown (void);
void	SCR_CenterPrint (char *str);
void	SCR_BeginLoadingPlaque (void);
void	SCR_EndLoadingPlaque (void);

void	SCR_DebugGraph (float value, int color);

void	SCR_TouchPics (void);

void	SCR_RunConsole (void);

extern	float		scr_con_current;
extern	float		scr_conlines;		// lines of console to display

extern	int			sb_lines;

extern	cvar_t		*scr_viewsize;
extern	cvar_t		*crosshair;

extern	vrect_t		scr_vrect;		// position of render window

extern	char		crosshair_pic[MAX_QPATH];
extern	int			crosshair_width, crosshair_height;

void SCR_AddDirtyPoint (int x, int y);
void SCR_DirtyScreen (void);

//
// scr_cin.c
//
void SCR_PlayCinematic (char *name);
qboolean SCR_DrawCinematic (void);
void SCR_RunCinematic (void);
void SCR_StopCinematic (void);
void SCR_FinishCinematic (void);

/* ============ end inlined header: client/screen.h ============ */
/* ============ begin inlined header: client/sound.h ============ */
/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

struct sfx_s;

void S_Init (void);
void S_Shutdown (void);

// if origin is NULL, the sound will be dynamically sourced from the entity
void S_StartSound (vec3_t origin, int entnum, int entchannel, struct sfx_s *sfx, float fvol,  float attenuation, float timeofs);
void S_StartLocalSound (char *s);

void S_RawSamples (int samples, int rate, int width, int channels, byte *data);

void S_StopAllSounds(void);
void S_Update (vec3_t origin, vec3_t v_forward, vec3_t v_right, vec3_t v_up);

void S_Activate (qboolean active);

void S_BeginRegistration (void);
struct sfx_s *S_RegisterSound (char *sample);
void S_EndRegistration (void);

struct sfx_s *S_FindName (char *name, qboolean create);

// the sound code makes callbacks to the client for entitiy position
// information, so entities can be dynamically re-spatialized
void CL_GetEntitySoundOrigin (int ent, vec3_t org);
/* ============ end inlined header: client/sound.h ============ */
/* ============ begin inlined header: client/input.h ============ */
/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
// input.h -- external (non-keyboard) input devices

void IN_Init (void);

void IN_Shutdown (void);

void IN_Commands (void);
// oportunity for devices to stick commands on the script buffer

void IN_Frame (void);

void IN_Move (usercmd_t *cmd);
// add additional movement on top of the keyboard move cmd

void IN_Activate (qboolean active);
/* ============ end inlined header: client/input.h ============ */
/* ============ begin inlined header: client/keys.h ============ */
/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

//
// these are the key numbers that should be passed to Key_Event
//
#define	K_TAB			9
#define	K_ENTER			13
#define	K_ESCAPE		27
#define	K_SPACE			32

// normal keys should be passed as lowercased ascii

#define	K_BACKSPACE		127
#define	K_UPARROW		128
#define	K_DOWNARROW		129
#define	K_LEFTARROW		130
#define	K_RIGHTARROW	131

#define	K_ALT			132
#define	K_CTRL			133
#define	K_SHIFT			134
#define	K_F1			135
#define	K_F2			136
#define	K_F3			137
#define	K_F4			138
#define	K_F5			139
#define	K_F6			140
#define	K_F7			141
#define	K_F8			142
#define	K_F9			143
#define	K_F10			144
#define	K_F11			145
#define	K_F12			146
#define	K_INS			147
#define	K_DEL			148
#define	K_PGDN			149
#define	K_PGUP			150
#define	K_HOME			151
#define	K_END			152

#define K_KP_HOME		160
#define K_KP_UPARROW	161
#define K_KP_PGUP		162
#define	K_KP_LEFTARROW	163
#define K_KP_5			164
#define K_KP_RIGHTARROW	165
#define K_KP_END		166
#define K_KP_DOWNARROW	167
#define K_KP_PGDN		168
#define	K_KP_ENTER		169
#define K_KP_INS   		170
#define	K_KP_DEL		171
#define K_KP_SLASH		172
#define K_KP_MINUS		173
#define K_KP_PLUS		174

#define K_PAUSE			255

//
// mouse buttons generate virtual keys
//
#define	K_MOUSE1		200
#define	K_MOUSE2		201
#define	K_MOUSE3		202

//
// joystick buttons
//
#define	K_JOY1			203
#define	K_JOY2			204
#define	K_JOY3			205
#define	K_JOY4			206

//
// aux keys are for multi-buttoned joysticks to generate so they can use
// the normal binding process
//
#define	K_AUX1			207
#define	K_AUX2			208
#define	K_AUX3			209
#define	K_AUX4			210
#define	K_AUX5			211
#define	K_AUX6			212
#define	K_AUX7			213
#define	K_AUX8			214
#define	K_AUX9			215
#define	K_AUX10			216
#define	K_AUX11			217
#define	K_AUX12			218
#define	K_AUX13			219
#define	K_AUX14			220
#define	K_AUX15			221
#define	K_AUX16			222
#define	K_AUX17			223
#define	K_AUX18			224
#define	K_AUX19			225
#define	K_AUX20			226
#define	K_AUX21			227
#define	K_AUX22			228
#define	K_AUX23			229
#define	K_AUX24			230
#define	K_AUX25			231
#define	K_AUX26			232
#define	K_AUX27			233
#define	K_AUX28			234
#define	K_AUX29			235
#define	K_AUX30			236
#define	K_AUX31			237
#define	K_AUX32			238

#define K_MWHEELDOWN	239
#define K_MWHEELUP		240

extern char		*keybindings[256];
extern	int		key_repeats[256];

extern	int	anykeydown;
extern char chat_buffer[];
extern	int chat_bufferlen;
extern	qboolean	chat_team;

void Key_Event (int key, qboolean down, unsigned time);
void Key_Init (void);
void Key_WriteBindings (FILE *f);
void Key_SetBinding (int keynum, char *binding);
void Key_ClearStates (void);
int Key_GetKey (void);

/* ============ end inlined header: client/keys.h ============ */
/* ============ begin inlined header: client/console.h ============ */
/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

//
// console
//

#define	NUM_CON_TIMES 4

#define		CON_TEXTSIZE	32768
typedef struct
{
	qboolean	initialized;

	char	text[CON_TEXTSIZE];
	int		current;		// line where next message will be printed
	int		x;				// offset in current line for next print
	int		display;		// bottom of console displays this line

	int		ormask;			// high bit mask for colored characters

	int 	linewidth;		// characters across screen
	int		totallines;		// total lines in console scrollback

	float	cursorspeed;

	int		vislines;

	float	times[NUM_CON_TIMES];	// cls.realtime time the line was generated
								// for transparent notify lines
} console_t;

extern	console_t	con;

void Con_DrawCharacter (int cx, int line, int num);

void Con_CheckResize (void);
void Con_Init (void);
void Con_DrawConsole (float frac);
void Con_Print (char *txt);
void Con_CenteredPrint (char *text);
void Con_Clear_f (void);
void Con_DrawNotify (void);
void Con_ClearNotify (void);
void Con_ToggleConsole_f (void);
/* ============ end inlined header: client/console.h ============ */
/* ============ begin inlined header: client/cdaudio.h ============ */
/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

int		CDAudio_Init(void);
void	CDAudio_Shutdown(void);
void	CDAudio_Play(int track, qboolean looping);
void	CDAudio_Stop(void);
void	CDAudio_Update(void);
void	CDAudio_Activate (qboolean active);
/* ============ end inlined header: client/cdaudio.h ============ */

//=============================================================================

typedef struct
{
	qboolean		valid;			// cleared if delta parsing was invalid
	int				serverframe;
	int				servertime;		// server time the message is valid for (in msec)
	int				deltaframe;
	byte			areabits[MAX_MAP_AREAS/8];		// portalarea visibility bits
	player_state_t	playerstate;
	int				num_entities;
	int				parse_entities;	// non-masked index into cl_parse_entities array
} frame_t;

typedef struct
{
	entity_state_t	baseline;		// delta from this if not from a previous frame
	entity_state_t	current;
	entity_state_t	prev;			// will always be valid, but might just be a copy of current

	int			serverframe;		// if not current, this ent isn't in the frame

	int			trailcount;			// for diminishing grenade trails
	vec3_t		lerp_origin;		// for trails (variable hz)

	int			fly_stoptime;
} centity_t;

#define MAX_CLIENTWEAPONMODELS		20		// PGM -- upped from 16 to fit the chainfist vwep

typedef struct
{
	char	name[MAX_QPATH];
	char	cinfo[MAX_QPATH];
	struct image_s	*skin;
	struct image_s	*icon;
	char	iconname[MAX_QPATH];
	struct model_s	*model;
	struct model_s	*weaponmodel[MAX_CLIENTWEAPONMODELS];
} clientinfo_t;

extern char cl_weaponmodels[MAX_CLIENTWEAPONMODELS][MAX_QPATH];
extern int num_cl_weaponmodels;

#define	CMD_BACKUP		64	// allow a lot of command backups for very fast systems

//
// the client_state_t structure is wiped completely at every
// server map change
//
typedef struct
{
	int			timeoutcount;

	int			timedemo_frames;
	int			timedemo_start;

	qboolean	refresh_prepped;	// false if on new level or new ref dll
	qboolean	sound_prepped;		// ambient sounds can start
	qboolean	force_refdef;		// vid has changed, so we can't use a paused refdef

	int			parse_entities;		// index (not anded off) into cl_parse_entities[]

	usercmd_t	cmd;
	usercmd_t	cmds[CMD_BACKUP];	// each mesage will send several old cmds
	int			cmd_time[CMD_BACKUP];	// time sent, for calculating pings
	short		predicted_origins[CMD_BACKUP][3];	// for debug comparing against server

	float		predicted_step;				// for stair up smoothing
	unsigned	predicted_step_time;

	vec3_t		predicted_origin;	// generated by CL_PredictMovement
	vec3_t		predicted_angles;
	vec3_t		prediction_error;

	frame_t		frame;				// received from server
	int			surpressCount;		// number of messages rate supressed
	frame_t		frames[UPDATE_BACKUP];

	// the client maintains its own idea of view angles, which are
	// sent to the server each frame.  It is cleared to 0 upon entering each level.
	// the server sends a delta each frame which is added to the locally
	// tracked view angles to account for standing on rotating objects,
	// and teleport direction changes
	vec3_t		viewangles;

	int			time;			// this is the time value that the client
								// is rendering at.  always <= cls.realtime
	float		lerpfrac;		// between oldframe and frame

	refdef_t	refdef;

	vec3_t		v_forward, v_right, v_up;	// set when refdef.angles is set

	//
	// transient data from server
	//
	char		layout[1024];		// general 2D overlay
	int			inventory[MAX_ITEMS];

	//
	// non-gameserver infornamtion
	// FIXME: move this cinematic stuff into the cin_t structure
	FILE		*cinematic_file;
	int			cinematictime;		// cls.realtime for first cinematic frame
	int			cinematicframe;
	char		cinematicpalette[768];
	qboolean	cinematicpalette_active;

	//
	// server state information
	//
	qboolean	attractloop;		// running the attract loop, any key will menu
	int			servercount;	// server identification for prespawns
	char		gamedir[MAX_QPATH];
	int			playernum;

	char		configstrings[MAX_CONFIGSTRINGS][MAX_QPATH];

	//
	// locally derived information from server state
	//
	struct model_s	*model_draw[MAX_MODELS];
	struct cmodel_s	*model_clip[MAX_MODELS];

	struct sfx_s	*sound_precache[MAX_SOUNDS];
	struct image_s	*image_precache[MAX_IMAGES];

	clientinfo_t	clientinfo[MAX_CLIENTS];
	clientinfo_t	baseclientinfo;
} client_state_t;

extern	client_state_t	cl;

/*
==================================================================

the client_static_t structure is persistant through an arbitrary number
of server connections

==================================================================
*/

typedef enum {
	ca_uninitialized,
	ca_disconnected, 	// not talking to a server
	ca_connecting,		// sending request packets to the server
	ca_connected,		// netchan_t established, waiting for svc_serverdata
	ca_active			// game views should be displayed
} connstate_t;

typedef enum {
	dl_none,
	dl_model,
	dl_sound,
	dl_skin,
	dl_single
} dltype_t;		// download type

typedef enum {key_game, key_console, key_message, key_menu} keydest_t;

typedef struct
{
	connstate_t	state;
	keydest_t	key_dest;

	int			framecount;
	int			realtime;			// always increasing, no clamping, etc
	float		frametime;			// seconds since last frame

// screen rendering information
	float		disable_screen;		// showing loading plaque between levels
									// or changing rendering dlls
									// if time gets > 30 seconds ahead, break it
	int			disable_servercount;	// when we receive a frame and cl.servercount
									// > cls.disable_servercount, clear disable_screen

// connection information
	char		servername[MAX_OSPATH];	// name of server from original connect
	float		connect_time;		// for connection retransmits

	int			quakePort;			// a 16 bit value that allows quake servers
									// to work around address translating routers
	netchan_t	netchan;
	int			serverProtocol;		// in case we are doing some kind of version hack

	int			challenge;			// from the server to use for connecting

	FILE		*download;			// file transfer from server
	char		downloadtempname[MAX_OSPATH];
	char		downloadname[MAX_OSPATH];
	int			downloadnumber;
	dltype_t	downloadtype;
	int			downloadpercent;

// demo recording info must be here, so it isn't cleared on level change
	qboolean	demorecording;
	qboolean	demowaiting;	// don't record until a non-delta message is received
	FILE		*demofile;
} client_static_t;

extern client_static_t	cls;

//=============================================================================

//
// cvars
//
extern	cvar_t	*cl_stereo_separation;
extern	cvar_t	*cl_stereo;

extern	cvar_t	*cl_gun;
extern	cvar_t	*cl_add_blend;
extern	cvar_t	*cl_add_lights;
extern	cvar_t	*cl_add_particles;
extern	cvar_t	*cl_add_entities;
extern	cvar_t	*cl_predict;
extern	cvar_t	*cl_footsteps;
extern	cvar_t	*cl_noskins;
extern	cvar_t	*cl_autoskins;

extern	cvar_t	*cl_upspeed;
extern	cvar_t	*cl_forwardspeed;
extern	cvar_t	*cl_sidespeed;

extern	cvar_t	*cl_yawspeed;
extern	cvar_t	*cl_pitchspeed;

extern	cvar_t	*cl_run;

extern	cvar_t	*cl_anglespeedkey;

extern	cvar_t	*cl_shownet;
extern	cvar_t	*cl_showmiss;
extern	cvar_t	*cl_showclamp;

extern	cvar_t	*lookspring;
extern	cvar_t	*lookstrafe;
extern	cvar_t	*sensitivity;

extern	cvar_t	*m_pitch;
extern	cvar_t	*m_yaw;
extern	cvar_t	*m_forward;
extern	cvar_t	*m_side;

extern	cvar_t	*freelook;

extern	cvar_t	*cl_lightlevel;	// FIXME HACK

extern	cvar_t	*cl_paused;
extern	cvar_t	*cl_timedemo;

extern	cvar_t	*cl_vwep;

typedef struct
{
	int		key;				// so entities can reuse same entry
	vec3_t	color;
	vec3_t	origin;
	float	radius;
	float	die;				// stop lighting after this time
	float	decay;				// drop this each second
	float	minlight;			// don't add when contributing less
} cdlight_t;

extern	centity_t	cl_entities[MAX_EDICTS];
extern	cdlight_t	cl_dlights[MAX_DLIGHTS];

// the cl_parse_entities must be large enough to hold UPDATE_BACKUP frames of
// entities, so that when a delta compressed message arives from the server
// it can be un-deltad from the original 
#define	MAX_PARSE_ENTITIES	1024
extern	entity_state_t	cl_parse_entities[MAX_PARSE_ENTITIES];

//=============================================================================

extern	netadr_t	net_from;
extern	sizebuf_t	net_message;

void DrawString (int x, int y, char *s);
void DrawAltString (int x, int y, char *s);	// toggle high bit
qboolean	CL_CheckOrDownloadFile (char *filename);

void CL_AddNetgraph (void);

//ROGUE
typedef struct cl_sustain
{
	int			id;
	int			type;
	int			endtime;
	int			nextthink;
	int			thinkinterval;
	vec3_t		org;
	vec3_t		dir;
	int			color;
	int			count;
	int			magnitude;
	void		(*think)(struct cl_sustain *self);
} cl_sustain_t;

#define MAX_SUSTAINS		32
void CL_ParticleSteamEffect2(cl_sustain_t *self);

void CL_TeleporterParticles (entity_state_t *ent);
void CL_ParticleEffect (vec3_t org, vec3_t dir, int color, int count);
void CL_ParticleEffect2 (vec3_t org, vec3_t dir, int color, int count);

// RAFAEL
void CL_ParticleEffect3 (vec3_t org, vec3_t dir, int color, int count);


//=================================================

// ========
// PGM
typedef struct particle_s
{
	struct particle_s	*next;

	float		time;

	vec3_t		org;
	vec3_t		vel;
	vec3_t		accel;
	float		color;
	float		colorvel;
	float		alpha;
	float		alphavel;
} cparticle_t;


#define	PARTICLE_GRAVITY	40
#define BLASTER_PARTICLE_COLOR		0xe0
// PMM
#define INSTANT_PARTICLE	-10000.0
// PGM
// ========

void CL_ClearEffects (void);
void CL_ClearTEnts (void);
void CL_BlasterTrail (vec3_t start, vec3_t end);
void CL_QuadTrail (vec3_t start, vec3_t end);
void CL_RailTrail (vec3_t start, vec3_t end);
void CL_BubbleTrail (vec3_t start, vec3_t end);
void CL_FlagTrail (vec3_t start, vec3_t end, float color);

// RAFAEL
void CL_IonripperTrail (vec3_t start, vec3_t end);

// ========
// PGM
void CL_BlasterParticles2 (vec3_t org, vec3_t dir, unsigned int color);
void CL_BlasterTrail2 (vec3_t start, vec3_t end);
void CL_DebugTrail (vec3_t start, vec3_t end);
void CL_SmokeTrail (vec3_t start, vec3_t end, int colorStart, int colorRun, int spacing);
void CL_Flashlight (int ent, vec3_t pos);
void CL_ForceWall (vec3_t start, vec3_t end, int color);
void CL_FlameEffects (centity_t *ent, vec3_t origin);
void CL_GenericParticleEffect (vec3_t org, vec3_t dir, int color, int count, int numcolors, int dirspread, float alphavel);
void CL_BubbleTrail2 (vec3_t start, vec3_t end, int dist);
void CL_Heatbeam (vec3_t start, vec3_t end);
void CL_ParticleSteamEffect (vec3_t org, vec3_t dir, int color, int count, int magnitude);
void CL_TrackerTrail (vec3_t start, vec3_t end, int particleColor);
void CL_Tracker_Explode(vec3_t origin);
void CL_TagTrail (vec3_t start, vec3_t end, float color);
void CL_ColorFlash (vec3_t pos, int ent, int intensity, float r, float g, float b);
void CL_Tracker_Shell(vec3_t origin);
void CL_MonsterPlasma_Shell(vec3_t origin);
void CL_ColorExplosionParticles (vec3_t org, int color, int run);
void CL_ParticleSmokeEffect (vec3_t org, vec3_t dir, int color, int count, int magnitude);
void CL_Widowbeamout (cl_sustain_t *self);
void CL_Nukeblast (cl_sustain_t *self);
void CL_WidowSplash (vec3_t org);
// PGM
// ========

int CL_ParseEntityBits (unsigned *bits);
void CL_ParseDelta (entity_state_t *from, entity_state_t *to, int number, int bits);
void CL_ParseFrame (void);

void CL_ParseTEnt (void);
void CL_ParseConfigString (void);
void CL_ParseMuzzleFlash (void);
void CL_ParseMuzzleFlash2 (void);
void SmokeAndFlash(vec3_t origin);

void CL_SetLightstyle (int i);

void CL_RunParticles (void);
void CL_RunDLights (void);
void CL_RunLightStyles (void);

void CL_AddEntities (void);
void CL_AddDLights (void);
void CL_AddTEnts (void);
void CL_AddLightStyles (void);

//=================================================

void CL_PrepRefresh (void);
void CL_RegisterSounds (void);

void CL_Quit_f (void);

void IN_Accumulate (void);

void CL_ParseLayout (void);


//
// cl_main
//
extern	refexport_t	re;		// interface to refresh .dll

void CL_Init (void);

void CL_FixUpGender(void);
void CL_Disconnect (void);
void CL_Disconnect_f (void);
void CL_GetChallengePacket (void);
void CL_PingServers_f (void);
void CL_Snd_Restart_f (void);
void CL_RequestNextDownload (void);

//
// cl_input
//
typedef struct
{
	int			down[2];		// key nums holding it down
	unsigned	downtime;		// msec timestamp
	unsigned	msec;			// msec down this frame
	int			state;
} kbutton_t;

extern	kbutton_t	in_mlook, in_klook;
extern 	kbutton_t 	in_strafe;
extern 	kbutton_t 	in_speed;

void CL_InitInput (void);
void CL_SendCmd (void);
void CL_SendMove (usercmd_t *cmd);

void CL_ClearState (void);

void CL_ReadPackets (void);

int  CL_ReadFromServer (void);
void CL_WriteToServer (usercmd_t *cmd);
void CL_BaseMove (usercmd_t *cmd);

void IN_CenterView (void);

float CL_KeyState (kbutton_t *key);
char *Key_KeynumToString (int keynum);

//
// cl_demo.c
//
void CL_WriteDemoMessage (void);
void CL_Stop_f (void);
void CL_Record_f (void);

//
// cl_parse.c
//
extern	char *svc_strings[256];

void CL_ParseServerMessage (void);
void CL_LoadClientinfo (clientinfo_t *ci, char *s);
void SHOWNET(char *s);
void CL_ParseClientinfo (int player);
void CL_Download_f (void);

//
// cl_view.c
//
extern	int			gun_frame;
extern	struct model_s	*gun_model;

void V_Init (void);
void V_RenderView( float stereo_separation );
void V_AddEntity (entity_t *ent);
void V_AddParticle (vec3_t org, int color, float alpha);
void V_AddLight (vec3_t org, float intensity, float r, float g, float b);
void V_AddLightStyle (int style, float r, float g, float b);

//
// cl_tent.c
//
void CL_RegisterTEntSounds (void);
void CL_RegisterTEntModels (void);
void CL_SmokeAndFlash(vec3_t origin);


//
// cl_pred.c
//
void CL_InitPrediction (void);
void CL_PredictMove (void);
void CL_CheckPredictionError (void);

//
// cl_fx.c
//
cdlight_t *CL_AllocDlight (int key);
void CL_BigTeleportParticles (vec3_t org);
void CL_RocketTrail (vec3_t start, vec3_t end, centity_t *old);
void CL_DiminishingTrail (vec3_t start, vec3_t end, centity_t *old, int flags);
void CL_FlyEffect (centity_t *ent, vec3_t origin);
void CL_BfgParticles (entity_t *ent);
void CL_AddParticles (void);
void CL_EntityEvent (entity_state_t *ent);
// RAFAEL
void CL_TrapParticles (entity_t *ent);

//
// menus
//
void M_Init (void);
void M_Keydown (int key);
void M_Draw (void);
void M_Menu_Main_f (void);
void M_ForceMenuOff (void);
void M_AddToServerList (netadr_t adr, char *info);

//
// cl_inv.c
//
void CL_ParseInventory (void);
void CL_KeyInventory (int key);
void CL_DrawInventory (void);

//
// cl_pred.c
//
void CL_PredictMovement (void);

#if id386
void x86_TimerStart( void );
void x86_TimerStop( void );
void x86_TimerInit( unsigned long smallest, unsigned longest );
unsigned long *x86_TimerGetHistogram( void );
#endif

#endif	// CLIENT_H
/* ============ end inlined header: client/client.h ============ */

typedef struct
{
	byte	*data;
	int		count;
} cblock_t;

typedef struct
{
	qboolean	restart_sound;
	int		s_rate;
	int		s_width;
	int		s_channels;

	int		width;
	int		height;
	byte	*pic;
	byte	*pic_pending;

	// order 1 huffman stuff
	int		*hnodes1;	// [256][256][2];
	int		numhnodes1[256];

	int		h_used[512];
	int		h_count[512];
} cinematics_t;

cinematics_t	cin;

/*
=================================================================

PCX LOADING

=================================================================
*/


/*
==============
SCR_LoadPCX
==============
*/
void SCR_LoadPCX (char *filename, byte **pic, byte **palette, int *width, int *height)
{
	byte	*raw;
	pcx_t	*pcx;
	int		x, y;
	int		len;
	int		dataByte, runLength;
	byte	*out, *pix;

	*pic = NULL;

	//
	// load the file
	//
	len = FS_LoadFile (filename, (void **)&raw);
	if (!raw)
		return;	// Com_Printf ("Bad pcx file %s\n", filename);

	//
	// parse the PCX file
	//
	pcx = (pcx_t *)raw;
	raw = &pcx->data;

	if (pcx->manufacturer != 0x0a
		|| pcx->version != 5
		|| pcx->encoding != 1
		|| pcx->bits_per_pixel != 8
		|| pcx->xmax >= 640
		|| pcx->ymax >= 480)
	{
		Com_Printf ("Bad pcx file %s\n", filename);
		return;
	}

	out = Z_Malloc ( (pcx->ymax+1) * (pcx->xmax+1) );

	*pic = out;

	pix = out;

	if (palette)
	{
		*palette = Z_Malloc(768);
		memcpy (*palette, (byte *)pcx + len - 768, 768);
	}

	if (width)
		*width = pcx->xmax+1;
	if (height)
		*height = pcx->ymax+1;

	for (y=0 ; y<=pcx->ymax ; y++, pix += pcx->xmax+1)
	{
		for (x=0 ; x<=pcx->xmax ; )
		{
			dataByte = *raw++;

			if((dataByte & 0xC0) == 0xC0)
			{
				runLength = dataByte & 0x3F;
				dataByte = *raw++;
			}
			else
				runLength = 1;

			while(runLength-- > 0)
				pix[x++] = dataByte;
		}

	}

	if ( raw - (byte *)pcx > len)
	{
		Com_Printf ("PCX file %s was malformed", filename);
		Z_Free (*pic);
		*pic = NULL;
	}

	FS_FreeFile (pcx);
}

//=============================================================

/*
==================
SCR_StopCinematic
==================
*/
void SCR_StopCinematic (void)
{
	cl.cinematictime = 0;	// done
	if (cin.pic)
	{
		Z_Free (cin.pic);
		cin.pic = NULL;
	}
	if (cin.pic_pending)
	{
		Z_Free (cin.pic_pending);
		cin.pic_pending = NULL;
	}
	if (cl.cinematicpalette_active)
	{
		re.CinematicSetPalette(NULL);
		cl.cinematicpalette_active = false;
	}
	if (cl.cinematic_file)
	{
		fclose (cl.cinematic_file);
		cl.cinematic_file = NULL;
	}
	if (cin.hnodes1)
	{
		Z_Free (cin.hnodes1);
		cin.hnodes1 = NULL;
	}

	// switch back down to 11 khz sound if necessary
	if (cin.restart_sound)
	{
		cin.restart_sound = false;
		CL_Snd_Restart_f ();
	}

}

/*
====================
SCR_FinishCinematic

Called when either the cinematic completes, or it is aborted
====================
*/
void SCR_FinishCinematic (void)
{
	// tell the server to advance to the next map / cinematic
	MSG_WriteByte (&cls.netchan.message, clc_stringcmd);
	SZ_Print (&cls.netchan.message, va("nextserver %i\n", cl.servercount));
}

//==========================================================================

/*
==================
SmallestNode1
==================
*/
int	SmallestNode1 (int numhnodes)
{
	int		i;
	int		best, bestnode;

	best = 99999999;
	bestnode = -1;
	for (i=0 ; i<numhnodes ; i++)
	{
		if (cin.h_used[i])
			continue;
		if (!cin.h_count[i])
			continue;
		if (cin.h_count[i] < best)
		{
			best = cin.h_count[i];
			bestnode = i;
		}
	}

	if (bestnode == -1)
		return -1;

	cin.h_used[bestnode] = true;
	return bestnode;
}


/*
==================
Huff1TableInit

Reads the 64k counts table and initializes the node trees
==================
*/
void Huff1TableInit (void)
{
	int		prev;
	int		j;
	int		*node, *nodebase;
	byte	counts[256];
	int		numhnodes;

	cin.hnodes1 = Z_Malloc (256*256*2*4);
	memset (cin.hnodes1, 0, 256*256*2*4);

	for (prev=0 ; prev<256 ; prev++)
	{
		memset (cin.h_count,0,sizeof(cin.h_count));
		memset (cin.h_used,0,sizeof(cin.h_used));

		// read a row of counts
		FS_Read (counts, sizeof(counts), cl.cinematic_file);
		for (j=0 ; j<256 ; j++)
			cin.h_count[j] = counts[j];

		// build the nodes
		numhnodes = 256;
		nodebase = cin.hnodes1 + prev*256*2;

		while (numhnodes != 511)
		{
			node = nodebase + (numhnodes-256)*2;

			// pick two lowest counts
			node[0] = SmallestNode1 (numhnodes);
			if (node[0] == -1)
				break;	// no more

			node[1] = SmallestNode1 (numhnodes);
			if (node[1] == -1)
				break;

			cin.h_count[numhnodes] = cin.h_count[node[0]] + cin.h_count[node[1]];
			numhnodes++;
		}

		cin.numhnodes1[prev] = numhnodes-1;
	}
}

/*
==================
Huff1Decompress
==================
*/
cblock_t Huff1Decompress (cblock_t in)
{
	byte		*input;
	byte		*out_p;
	int			nodenum;
	int			count;
	cblock_t	out;
	int			inbyte;
	int			*hnodes, *hnodesbase;
//int		i;

	// get decompressed count
	count = in.data[0] + (in.data[1]<<8) + (in.data[2]<<16) + (in.data[3]<<24);
	input = in.data + 4;
	out_p = out.data = Z_Malloc (count);

	// read bits

	hnodesbase = cin.hnodes1 - 256*2;	// nodes 0-255 aren't stored

	hnodes = hnodesbase;
	nodenum = cin.numhnodes1[0];
	while (count)
	{
		inbyte = *input++;
		//-----------
		if (nodenum < 256)
		{
			hnodes = hnodesbase + (nodenum<<9);
			*out_p++ = nodenum;
			if (!--count)
				break;
			nodenum = cin.numhnodes1[nodenum];
		}
		nodenum = hnodes[nodenum*2 + (inbyte&1)];
		inbyte >>=1;
		//-----------
		if (nodenum < 256)
		{
			hnodes = hnodesbase + (nodenum<<9);
			*out_p++ = nodenum;
			if (!--count)
				break;
			nodenum = cin.numhnodes1[nodenum];
		}
		nodenum = hnodes[nodenum*2 + (inbyte&1)];
		inbyte >>=1;
		//-----------
		if (nodenum < 256)
		{
			hnodes = hnodesbase + (nodenum<<9);
			*out_p++ = nodenum;
			if (!--count)
				break;
			nodenum = cin.numhnodes1[nodenum];
		}
		nodenum = hnodes[nodenum*2 + (inbyte&1)];
		inbyte >>=1;
		//-----------
		if (nodenum < 256)
		{
			hnodes = hnodesbase + (nodenum<<9);
			*out_p++ = nodenum;
			if (!--count)
				break;
			nodenum = cin.numhnodes1[nodenum];
		}
		nodenum = hnodes[nodenum*2 + (inbyte&1)];
		inbyte >>=1;
		//-----------
		if (nodenum < 256)
		{
			hnodes = hnodesbase + (nodenum<<9);
			*out_p++ = nodenum;
			if (!--count)
				break;
			nodenum = cin.numhnodes1[nodenum];
		}
		nodenum = hnodes[nodenum*2 + (inbyte&1)];
		inbyte >>=1;
		//-----------
		if (nodenum < 256)
		{
			hnodes = hnodesbase + (nodenum<<9);
			*out_p++ = nodenum;
			if (!--count)
				break;
			nodenum = cin.numhnodes1[nodenum];
		}
		nodenum = hnodes[nodenum*2 + (inbyte&1)];
		inbyte >>=1;
		//-----------
		if (nodenum < 256)
		{
			hnodes = hnodesbase + (nodenum<<9);
			*out_p++ = nodenum;
			if (!--count)
				break;
			nodenum = cin.numhnodes1[nodenum];
		}
		nodenum = hnodes[nodenum*2 + (inbyte&1)];
		inbyte >>=1;
		//-----------
		if (nodenum < 256)
		{
			hnodes = hnodesbase + (nodenum<<9);
			*out_p++ = nodenum;
			if (!--count)
				break;
			nodenum = cin.numhnodes1[nodenum];
		}
		nodenum = hnodes[nodenum*2 + (inbyte&1)];
		inbyte >>=1;
	}

	if (input - in.data != in.count && input - in.data != in.count+1)
	{
		Com_Printf ("Decompression overread by %i", (input - in.data) - in.count);
	}
	out.count = out_p - out.data;

	return out;
}

/*
==================
SCR_ReadNextFrame
==================
*/
byte *SCR_ReadNextFrame (void)
{
	int		r;
	int		command;
	byte	samples[22050/14*4];
	byte	compressed[0x20000];
	int		size;
	byte	*pic;
	cblock_t	in, huf1;
	int		start, end, count;

	// read the next frame
	r = fread (&command, 4, 1, cl.cinematic_file);
	if (r == 0)		// we'll give it one more chance
		r = fread (&command, 4, 1, cl.cinematic_file);

	if (r != 1)
		return NULL;
	command = LittleLong(command);
	if (command == 2)
		return NULL;	// last frame marker

	if (command == 1)
	{	// read palette
		FS_Read (cl.cinematicpalette, sizeof(cl.cinematicpalette), cl.cinematic_file);
		cl.cinematicpalette_active=0;	// dubious....  exposes an edge case
	}

	// decompress the next frame
	FS_Read (&size, 4, cl.cinematic_file);
	size = LittleLong(size);
	if (size > sizeof(compressed) || size < 1)
		Com_Error (ERR_DROP, "Bad compressed frame size");
	FS_Read (compressed, size, cl.cinematic_file);

	// read sound
	start = cl.cinematicframe*cin.s_rate/14;
	end = (cl.cinematicframe+1)*cin.s_rate/14;
	count = end - start;

	FS_Read (samples, count*cin.s_width*cin.s_channels, cl.cinematic_file);

	S_RawSamples (count, cin.s_rate, cin.s_width, cin.s_channels, samples);

	in.data = compressed;
	in.count = size;

	huf1 = Huff1Decompress (in);

	pic = huf1.data;

	cl.cinematicframe++;

	return pic;
}


/*
==================
SCR_RunCinematic

==================
*/
void SCR_RunCinematic (void)
{
	int		frame;

	if (cl.cinematictime <= 0)
	{
		SCR_StopCinematic ();
		return;
	}

	if (cl.cinematicframe == -1)
		return;		// static image

	if (cls.key_dest != key_game)
	{	// pause if menu or console is up
		cl.cinematictime = cls.realtime - cl.cinematicframe*1000/14;
		return;
	}

	frame = (cls.realtime - cl.cinematictime)*14.0/1000;
	if (frame <= cl.cinematicframe)
		return;
	if (frame > cl.cinematicframe+1)
	{
		Com_Printf ("Dropped frame: %i > %i\n", frame, cl.cinematicframe+1);
		cl.cinematictime = cls.realtime - cl.cinematicframe*1000/14;
	}
	if (cin.pic)
		Z_Free (cin.pic);
	cin.pic = cin.pic_pending;
	cin.pic_pending = NULL;
	cin.pic_pending = SCR_ReadNextFrame ();
	if (!cin.pic_pending)
	{
		SCR_StopCinematic ();
		SCR_FinishCinematic ();
		cl.cinematictime = 1;	// hack to get the black screen behind loading
		SCR_BeginLoadingPlaque ();
		cl.cinematictime = 0;
		return;
	}
}

/*
==================
SCR_DrawCinematic

Returns true if a cinematic is active, meaning the view rendering
should be skipped
==================
*/
qboolean SCR_DrawCinematic (void)
{
	if (cl.cinematictime <= 0)
	{
		return false;
	}

	if (cls.key_dest == key_menu)
	{	// blank screen and pause if menu is up
		re.CinematicSetPalette(NULL);
		cl.cinematicpalette_active = false;
		return true;
	}

	if (!cl.cinematicpalette_active)
	{
		re.CinematicSetPalette(cl.cinematicpalette);
		cl.cinematicpalette_active = true;
	}

	if (!cin.pic)
		return true;

	re.DrawStretchRaw (0, 0, viddef.width, viddef.height,
		cin.width, cin.height, cin.pic);

	return true;
}

/*
==================
SCR_PlayCinematic

==================
*/
void SCR_PlayCinematic (char *arg)
{
	int		width, height;
	byte	*palette;
	char	name[MAX_OSPATH], *dot;
	int		old_khz;

	// make sure CD isn't playing music
	CDAudio_Stop();

	cl.cinematicframe = 0;
	dot = strstr (arg, ".");
	if (dot && !strcmp (dot, ".pcx"))
	{	// static pcx image
		Com_sprintf (name, sizeof(name), "pics/%s", arg);
		SCR_LoadPCX (name, &cin.pic, &palette, &cin.width, &cin.height);
		cl.cinematicframe = -1;
		cl.cinematictime = 1;
		SCR_EndLoadingPlaque ();
		cls.state = ca_active;
		if (!cin.pic)
		{
			Com_Printf ("%s not found.\n", name);
			cl.cinematictime = 0;
		}
		else
		{
			memcpy (cl.cinematicpalette, palette, sizeof(cl.cinematicpalette));
			Z_Free (palette);
		}
		return;
	}

	Com_sprintf (name, sizeof(name), "video/%s", arg);
	FS_FOpenFile (name, &cl.cinematic_file);
	if (!cl.cinematic_file)
	{
//		Com_Error (ERR_DROP, "Cinematic %s not found.\n", name);
		SCR_FinishCinematic ();
		cl.cinematictime = 0;	// done
		return;
	}

	SCR_EndLoadingPlaque ();

	cls.state = ca_active;

	FS_Read (&width, 4, cl.cinematic_file);
	FS_Read (&height, 4, cl.cinematic_file);
	cin.width = LittleLong(width);
	cin.height = LittleLong(height);

	FS_Read (&cin.s_rate, 4, cl.cinematic_file);
	cin.s_rate = LittleLong(cin.s_rate);
	FS_Read (&cin.s_width, 4, cl.cinematic_file);
	cin.s_width = LittleLong(cin.s_width);
	FS_Read (&cin.s_channels, 4, cl.cinematic_file);
	cin.s_channels = LittleLong(cin.s_channels);

	Huff1TableInit ();

	// switch up to 22 khz sound if necessary
	old_khz = Cvar_VariableValue ("s_khz");
	if (old_khz != cin.s_rate/1000)
	{
		cin.restart_sound = true;
		Cvar_SetValue ("s_khz", cin.s_rate/1000);
		CL_Snd_Restart_f ();
		Cvar_SetValue ("s_khz", old_khz);
	}

	cl.cinematicframe = 0;
	cin.pic = SCR_ReadNextFrame ();
	cl.cinematictime = Sys_Milliseconds ();
}
