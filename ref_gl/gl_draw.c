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

// draw.c

/* ============ begin inlined header: ref_gl/gl_local.h ============ */
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
// disable data conversion warnings

#ifndef GL_LOCAL_H
#define GL_LOCAL_H

#if 0
#pragma warning(disable : 4244)     // MIPS
#pragma warning(disable : 4136)     // X86
#pragma warning(disable : 4051)     // ALPHA
#endif

#ifdef _WIN32
#  include <windows.h>
#endif

#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

#ifndef GL_COLOR_INDEX8_EXT
#define GL_COLOR_INDEX8_EXT GL_COLOR_INDEX
#endif

/* already inlined above: client/ref.h */

/* ============ begin inlined header: ref_gl/qgl.h ============ */
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
/*
** QGL.H
*/

#ifndef __QGL_H__
#define __QGL_H__

#ifdef _WIN32
#  include <windows.h>
#endif

#include <GL/gl.h>

qboolean QGL_Init( const char *dllname );
void     QGL_Shutdown( void );

#ifndef APIENTRY
#  define APIENTRY
#endif

extern  void ( APIENTRY * qglAccum )(GLenum op, GLfloat value);
extern  void ( APIENTRY * qglAlphaFunc )(GLenum func, GLclampf ref);
extern  GLboolean ( APIENTRY * qglAreTexturesResident )(GLsizei n, const GLuint *textures, GLboolean *residences);
extern  void ( APIENTRY * qglArrayElement )(GLint i);
extern  void ( APIENTRY * qglBegin )(GLenum mode);
extern  void ( APIENTRY * qglBindTexture )(GLenum target, GLuint texture);
extern  void ( APIENTRY * qglBitmap )(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
extern  void ( APIENTRY * qglBlendFunc )(GLenum sfactor, GLenum dfactor);
extern  void ( APIENTRY * qglCallList )(GLuint list);
extern  void ( APIENTRY * qglCallLists )(GLsizei n, GLenum type, const GLvoid *lists);
extern  void ( APIENTRY * qglClear )(GLbitfield mask);
extern  void ( APIENTRY * qglClearAccum )(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern  void ( APIENTRY * qglClearColor )(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
extern  void ( APIENTRY * qglClearDepth )(GLclampd depth);
extern  void ( APIENTRY * qglClearIndex )(GLfloat c);
extern  void ( APIENTRY * qglClearStencil )(GLint s);
extern  void ( APIENTRY * qglClipPlane )(GLenum plane, const GLdouble *equation);
extern  void ( APIENTRY * qglColor3b )(GLbyte red, GLbyte green, GLbyte blue);
extern  void ( APIENTRY * qglColor3bv )(const GLbyte *v);
extern  void ( APIENTRY * qglColor3d )(GLdouble red, GLdouble green, GLdouble blue);
extern  void ( APIENTRY * qglColor3dv )(const GLdouble *v);
extern  void ( APIENTRY * qglColor3f )(GLfloat red, GLfloat green, GLfloat blue);
extern  void ( APIENTRY * qglColor3fv )(const GLfloat *v);
extern  void ( APIENTRY * qglColor3i )(GLint red, GLint green, GLint blue);
extern  void ( APIENTRY * qglColor3iv )(const GLint *v);
extern  void ( APIENTRY * qglColor3s )(GLshort red, GLshort green, GLshort blue);
extern  void ( APIENTRY * qglColor3sv )(const GLshort *v);
extern  void ( APIENTRY * qglColor3ub )(GLubyte red, GLubyte green, GLubyte blue);
extern  void ( APIENTRY * qglColor3ubv )(const GLubyte *v);
extern  void ( APIENTRY * qglColor3ui )(GLuint red, GLuint green, GLuint blue);
extern  void ( APIENTRY * qglColor3uiv )(const GLuint *v);
extern  void ( APIENTRY * qglColor3us )(GLushort red, GLushort green, GLushort blue);
extern  void ( APIENTRY * qglColor3usv )(const GLushort *v);
extern  void ( APIENTRY * qglColor4b )(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
extern  void ( APIENTRY * qglColor4bv )(const GLbyte *v);
extern  void ( APIENTRY * qglColor4d )(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
extern  void ( APIENTRY * qglColor4dv )(const GLdouble *v);
extern  void ( APIENTRY * qglColor4f )(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern  void ( APIENTRY * qglColor4fv )(const GLfloat *v);
extern  void ( APIENTRY * qglColor4i )(GLint red, GLint green, GLint blue, GLint alpha);
extern  void ( APIENTRY * qglColor4iv )(const GLint *v);
extern  void ( APIENTRY * qglColor4s )(GLshort red, GLshort green, GLshort blue, GLshort alpha);
extern  void ( APIENTRY * qglColor4sv )(const GLshort *v);
extern  void ( APIENTRY * qglColor4ub )(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
extern  void ( APIENTRY * qglColor4ubv )(const GLubyte *v);
extern  void ( APIENTRY * qglColor4ui )(GLuint red, GLuint green, GLuint blue, GLuint alpha);
extern  void ( APIENTRY * qglColor4uiv )(const GLuint *v);
extern  void ( APIENTRY * qglColor4us )(GLushort red, GLushort green, GLushort blue, GLushort alpha);
extern  void ( APIENTRY * qglColor4usv )(const GLushort *v);
extern  void ( APIENTRY * qglColorMask )(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern  void ( APIENTRY * qglColorMaterial )(GLenum face, GLenum mode);
extern  void ( APIENTRY * qglColorPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern  void ( APIENTRY * qglCopyPixels )(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
extern  void ( APIENTRY * qglCopyTexImage1D )(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
extern  void ( APIENTRY * qglCopyTexImage2D )(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern  void ( APIENTRY * qglCopyTexSubImage1D )(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern  void ( APIENTRY * qglCopyTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern  void ( APIENTRY * qglCullFace )(GLenum mode);
extern  void ( APIENTRY * qglDeleteLists )(GLuint list, GLsizei range);
extern  void ( APIENTRY * qglDeleteTextures )(GLsizei n, const GLuint *textures);
extern  void ( APIENTRY * qglDepthFunc )(GLenum func);
extern  void ( APIENTRY * qglDepthMask )(GLboolean flag);
extern  void ( APIENTRY * qglDepthRange )(GLclampd zNear, GLclampd zFar);
extern  void ( APIENTRY * qglDisable )(GLenum cap);
extern  void ( APIENTRY * qglDisableClientState )(GLenum array);
extern  void ( APIENTRY * qglDrawArrays )(GLenum mode, GLint first, GLsizei count);
extern  void ( APIENTRY * qglDrawBuffer )(GLenum mode);
extern  void ( APIENTRY * qglDrawElements )(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
extern  void ( APIENTRY * qglDrawPixels )(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
extern  void ( APIENTRY * qglEdgeFlag )(GLboolean flag);
extern  void ( APIENTRY * qglEdgeFlagPointer )(GLsizei stride, const GLvoid *pointer);
extern  void ( APIENTRY * qglEdgeFlagv )(const GLboolean *flag);
extern  void ( APIENTRY * qglEnable )(GLenum cap);
extern  void ( APIENTRY * qglEnableClientState )(GLenum array);
extern  void ( APIENTRY * qglEnd )(void);
extern  void ( APIENTRY * qglEndList )(void);
extern  void ( APIENTRY * qglEvalCoord1d )(GLdouble u);
extern  void ( APIENTRY * qglEvalCoord1dv )(const GLdouble *u);
extern  void ( APIENTRY * qglEvalCoord1f )(GLfloat u);
extern  void ( APIENTRY * qglEvalCoord1fv )(const GLfloat *u);
extern  void ( APIENTRY * qglEvalCoord2d )(GLdouble u, GLdouble v);
extern  void ( APIENTRY * qglEvalCoord2dv )(const GLdouble *u);
extern  void ( APIENTRY * qglEvalCoord2f )(GLfloat u, GLfloat v);
extern  void ( APIENTRY * qglEvalCoord2fv )(const GLfloat *u);
extern  void ( APIENTRY * qglEvalMesh1 )(GLenum mode, GLint i1, GLint i2);
extern  void ( APIENTRY * qglEvalMesh2 )(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
extern  void ( APIENTRY * qglEvalPoint1 )(GLint i);
extern  void ( APIENTRY * qglEvalPoint2 )(GLint i, GLint j);
extern  void ( APIENTRY * qglFeedbackBuffer )(GLsizei size, GLenum type, GLfloat *buffer);
extern  void ( APIENTRY * qglFinish )(void);
extern  void ( APIENTRY * qglFlush )(void);
extern  void ( APIENTRY * qglFogf )(GLenum pname, GLfloat param);
extern  void ( APIENTRY * qglFogfv )(GLenum pname, const GLfloat *params);
extern  void ( APIENTRY * qglFogi )(GLenum pname, GLint param);
extern  void ( APIENTRY * qglFogiv )(GLenum pname, const GLint *params);
extern  void ( APIENTRY * qglFrontFace )(GLenum mode);
extern  void ( APIENTRY * qglFrustum )(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
extern  GLuint ( APIENTRY * qglGenLists )(GLsizei range);
extern  void ( APIENTRY * qglGenTextures )(GLsizei n, GLuint *textures);
extern  void ( APIENTRY * qglGetBooleanv )(GLenum pname, GLboolean *params);
extern  void ( APIENTRY * qglGetClipPlane )(GLenum plane, GLdouble *equation);
extern  void ( APIENTRY * qglGetDoublev )(GLenum pname, GLdouble *params);
extern  GLenum ( APIENTRY * qglGetError )(void);
extern  void ( APIENTRY * qglGetFloatv )(GLenum pname, GLfloat *params);
extern  void ( APIENTRY * qglGetIntegerv )(GLenum pname, GLint *params);
extern  void ( APIENTRY * qglGetLightfv )(GLenum light, GLenum pname, GLfloat *params);
extern  void ( APIENTRY * qglGetLightiv )(GLenum light, GLenum pname, GLint *params);
extern  void ( APIENTRY * qglGetMapdv )(GLenum target, GLenum query, GLdouble *v);
extern  void ( APIENTRY * qglGetMapfv )(GLenum target, GLenum query, GLfloat *v);
extern  void ( APIENTRY * qglGetMapiv )(GLenum target, GLenum query, GLint *v);
extern  void ( APIENTRY * qglGetMaterialfv )(GLenum face, GLenum pname, GLfloat *params);
extern  void ( APIENTRY * qglGetMaterialiv )(GLenum face, GLenum pname, GLint *params);
extern  void ( APIENTRY * qglGetPixelMapfv )(GLenum map, GLfloat *values);
extern  void ( APIENTRY * qglGetPixelMapuiv )(GLenum map, GLuint *values);
extern  void ( APIENTRY * qglGetPixelMapusv )(GLenum map, GLushort *values);
extern  void ( APIENTRY * qglGetPointerv )(GLenum pname, GLvoid* *params);
extern  void ( APIENTRY * qglGetPolygonStipple )(GLubyte *mask);
extern  const GLubyte * ( APIENTRY * qglGetString )(GLenum name);
extern  void ( APIENTRY * qglGetTexEnvfv )(GLenum target, GLenum pname, GLfloat *params);
extern  void ( APIENTRY * qglGetTexEnviv )(GLenum target, GLenum pname, GLint *params);
extern  void ( APIENTRY * qglGetTexGendv )(GLenum coord, GLenum pname, GLdouble *params);
extern  void ( APIENTRY * qglGetTexGenfv )(GLenum coord, GLenum pname, GLfloat *params);
extern  void ( APIENTRY * qglGetTexGeniv )(GLenum coord, GLenum pname, GLint *params);
extern  void ( APIENTRY * qglGetTexImage )(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
extern  void ( APIENTRY * qglGetTexLevelParameterfv )(GLenum target, GLint level, GLenum pname, GLfloat *params);
extern  void ( APIENTRY * qglGetTexLevelParameteriv )(GLenum target, GLint level, GLenum pname, GLint *params);
extern  void ( APIENTRY * qglGetTexParameterfv )(GLenum target, GLenum pname, GLfloat *params);
extern  void ( APIENTRY * qglGetTexParameteriv )(GLenum target, GLenum pname, GLint *params);
extern  void ( APIENTRY * qglHint )(GLenum target, GLenum mode);
extern  void ( APIENTRY * qglIndexMask )(GLuint mask);
extern  void ( APIENTRY * qglIndexPointer )(GLenum type, GLsizei stride, const GLvoid *pointer);
extern  void ( APIENTRY * qglIndexd )(GLdouble c);
extern  void ( APIENTRY * qglIndexdv )(const GLdouble *c);
extern  void ( APIENTRY * qglIndexf )(GLfloat c);
extern  void ( APIENTRY * qglIndexfv )(const GLfloat *c);
extern  void ( APIENTRY * qglIndexi )(GLint c);
extern  void ( APIENTRY * qglIndexiv )(const GLint *c);
extern  void ( APIENTRY * qglIndexs )(GLshort c);
extern  void ( APIENTRY * qglIndexsv )(const GLshort *c);
extern  void ( APIENTRY * qglIndexub )(GLubyte c);
extern  void ( APIENTRY * qglIndexubv )(const GLubyte *c);
extern  void ( APIENTRY * qglInitNames )(void);
extern  void ( APIENTRY * qglInterleavedArrays )(GLenum format, GLsizei stride, const GLvoid *pointer);
extern  GLboolean ( APIENTRY * qglIsEnabled )(GLenum cap);
extern  GLboolean ( APIENTRY * qglIsList )(GLuint list);
extern  GLboolean ( APIENTRY * qglIsTexture )(GLuint texture);
extern  void ( APIENTRY * qglLightModelf )(GLenum pname, GLfloat param);
extern  void ( APIENTRY * qglLightModelfv )(GLenum pname, const GLfloat *params);
extern  void ( APIENTRY * qglLightModeli )(GLenum pname, GLint param);
extern  void ( APIENTRY * qglLightModeliv )(GLenum pname, const GLint *params);
extern  void ( APIENTRY * qglLightf )(GLenum light, GLenum pname, GLfloat param);
extern  void ( APIENTRY * qglLightfv )(GLenum light, GLenum pname, const GLfloat *params);
extern  void ( APIENTRY * qglLighti )(GLenum light, GLenum pname, GLint param);
extern  void ( APIENTRY * qglLightiv )(GLenum light, GLenum pname, const GLint *params);
extern  void ( APIENTRY * qglLineStipple )(GLint factor, GLushort pattern);
extern  void ( APIENTRY * qglLineWidth )(GLfloat width);
extern  void ( APIENTRY * qglListBase )(GLuint base);
extern  void ( APIENTRY * qglLoadIdentity )(void);
extern  void ( APIENTRY * qglLoadMatrixd )(const GLdouble *m);
extern  void ( APIENTRY * qglLoadMatrixf )(const GLfloat *m);
extern  void ( APIENTRY * qglLoadName )(GLuint name);
extern  void ( APIENTRY * qglLogicOp )(GLenum opcode);
extern  void ( APIENTRY * qglMap1d )(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
extern  void ( APIENTRY * qglMap1f )(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
extern  void ( APIENTRY * qglMap2d )(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
extern  void ( APIENTRY * qglMap2f )(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
extern  void ( APIENTRY * qglMapGrid1d )(GLint un, GLdouble u1, GLdouble u2);
extern  void ( APIENTRY * qglMapGrid1f )(GLint un, GLfloat u1, GLfloat u2);
extern  void ( APIENTRY * qglMapGrid2d )(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
extern  void ( APIENTRY * qglMapGrid2f )(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
extern  void ( APIENTRY * qglMaterialf )(GLenum face, GLenum pname, GLfloat param);
extern  void ( APIENTRY * qglMaterialfv )(GLenum face, GLenum pname, const GLfloat *params);
extern  void ( APIENTRY * qglMateriali )(GLenum face, GLenum pname, GLint param);
extern  void ( APIENTRY * qglMaterialiv )(GLenum face, GLenum pname, const GLint *params);
extern  void ( APIENTRY * qglMatrixMode )(GLenum mode);
extern  void ( APIENTRY * qglMultMatrixd )(const GLdouble *m);
extern  void ( APIENTRY * qglMultMatrixf )(const GLfloat *m);
extern  void ( APIENTRY * qglNewList )(GLuint list, GLenum mode);
extern  void ( APIENTRY * qglNormal3b )(GLbyte nx, GLbyte ny, GLbyte nz);
extern  void ( APIENTRY * qglNormal3bv )(const GLbyte *v);
extern  void ( APIENTRY * qglNormal3d )(GLdouble nx, GLdouble ny, GLdouble nz);
extern  void ( APIENTRY * qglNormal3dv )(const GLdouble *v);
extern  void ( APIENTRY * qglNormal3f )(GLfloat nx, GLfloat ny, GLfloat nz);
extern  void ( APIENTRY * qglNormal3fv )(const GLfloat *v);
extern  void ( APIENTRY * qglNormal3i )(GLint nx, GLint ny, GLint nz);
extern  void ( APIENTRY * qglNormal3iv )(const GLint *v);
extern  void ( APIENTRY * qglNormal3s )(GLshort nx, GLshort ny, GLshort nz);
extern  void ( APIENTRY * qglNormal3sv )(const GLshort *v);
extern  void ( APIENTRY * qglNormalPointer )(GLenum type, GLsizei stride, const GLvoid *pointer);
extern  void ( APIENTRY * qglOrtho )(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
extern  void ( APIENTRY * qglPassThrough )(GLfloat token);
extern  void ( APIENTRY * qglPixelMapfv )(GLenum map, GLsizei mapsize, const GLfloat *values);
extern  void ( APIENTRY * qglPixelMapuiv )(GLenum map, GLsizei mapsize, const GLuint *values);
extern  void ( APIENTRY * qglPixelMapusv )(GLenum map, GLsizei mapsize, const GLushort *values);
extern  void ( APIENTRY * qglPixelStoref )(GLenum pname, GLfloat param);
extern  void ( APIENTRY * qglPixelStorei )(GLenum pname, GLint param);
extern  void ( APIENTRY * qglPixelTransferf )(GLenum pname, GLfloat param);
extern  void ( APIENTRY * qglPixelTransferi )(GLenum pname, GLint param);
extern  void ( APIENTRY * qglPixelZoom )(GLfloat xfactor, GLfloat yfactor);
extern  void ( APIENTRY * qglPointSize )(GLfloat size);
extern  void ( APIENTRY * qglPolygonMode )(GLenum face, GLenum mode);
extern  void ( APIENTRY * qglPolygonOffset )(GLfloat factor, GLfloat units);
extern  void ( APIENTRY * qglPolygonStipple )(const GLubyte *mask);
extern  void ( APIENTRY * qglPopAttrib )(void);
extern  void ( APIENTRY * qglPopClientAttrib )(void);
extern  void ( APIENTRY * qglPopMatrix )(void);
extern  void ( APIENTRY * qglPopName )(void);
extern  void ( APIENTRY * qglPrioritizeTextures )(GLsizei n, const GLuint *textures, const GLclampf *priorities);
extern  void ( APIENTRY * qglPushAttrib )(GLbitfield mask);
extern  void ( APIENTRY * qglPushClientAttrib )(GLbitfield mask);
extern  void ( APIENTRY * qglPushMatrix )(void);
extern  void ( APIENTRY * qglPushName )(GLuint name);
extern  void ( APIENTRY * qglRasterPos2d )(GLdouble x, GLdouble y);
extern  void ( APIENTRY * qglRasterPos2dv )(const GLdouble *v);
extern  void ( APIENTRY * qglRasterPos2f )(GLfloat x, GLfloat y);
extern  void ( APIENTRY * qglRasterPos2fv )(const GLfloat *v);
extern  void ( APIENTRY * qglRasterPos2i )(GLint x, GLint y);
extern  void ( APIENTRY * qglRasterPos2iv )(const GLint *v);
extern  void ( APIENTRY * qglRasterPos2s )(GLshort x, GLshort y);
extern  void ( APIENTRY * qglRasterPos2sv )(const GLshort *v);
extern  void ( APIENTRY * qglRasterPos3d )(GLdouble x, GLdouble y, GLdouble z);
extern  void ( APIENTRY * qglRasterPos3dv )(const GLdouble *v);
extern  void ( APIENTRY * qglRasterPos3f )(GLfloat x, GLfloat y, GLfloat z);
extern  void ( APIENTRY * qglRasterPos3fv )(const GLfloat *v);
extern  void ( APIENTRY * qglRasterPos3i )(GLint x, GLint y, GLint z);
extern  void ( APIENTRY * qglRasterPos3iv )(const GLint *v);
extern  void ( APIENTRY * qglRasterPos3s )(GLshort x, GLshort y, GLshort z);
extern  void ( APIENTRY * qglRasterPos3sv )(const GLshort *v);
extern  void ( APIENTRY * qglRasterPos4d )(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern  void ( APIENTRY * qglRasterPos4dv )(const GLdouble *v);
extern  void ( APIENTRY * qglRasterPos4f )(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern  void ( APIENTRY * qglRasterPos4fv )(const GLfloat *v);
extern  void ( APIENTRY * qglRasterPos4i )(GLint x, GLint y, GLint z, GLint w);
extern  void ( APIENTRY * qglRasterPos4iv )(const GLint *v);
extern  void ( APIENTRY * qglRasterPos4s )(GLshort x, GLshort y, GLshort z, GLshort w);
extern  void ( APIENTRY * qglRasterPos4sv )(const GLshort *v);
extern  void ( APIENTRY * qglReadBuffer )(GLenum mode);
extern  void ( APIENTRY * qglReadPixels )(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
extern  void ( APIENTRY * qglRectd )(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
extern  void ( APIENTRY * qglRectdv )(const GLdouble *v1, const GLdouble *v2);
extern  void ( APIENTRY * qglRectf )(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
extern  void ( APIENTRY * qglRectfv )(const GLfloat *v1, const GLfloat *v2);
extern  void ( APIENTRY * qglRecti )(GLint x1, GLint y1, GLint x2, GLint y2);
extern  void ( APIENTRY * qglRectiv )(const GLint *v1, const GLint *v2);
extern  void ( APIENTRY * qglRects )(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
extern  void ( APIENTRY * qglRectsv )(const GLshort *v1, const GLshort *v2);
extern  GLint ( APIENTRY * qglRenderMode )(GLenum mode);
extern  void ( APIENTRY * qglRotated )(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
extern  void ( APIENTRY * qglRotatef )(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
extern  void ( APIENTRY * qglScaled )(GLdouble x, GLdouble y, GLdouble z);
extern  void ( APIENTRY * qglScalef )(GLfloat x, GLfloat y, GLfloat z);
extern  void ( APIENTRY * qglScissor )(GLint x, GLint y, GLsizei width, GLsizei height);
extern  void ( APIENTRY * qglSelectBuffer )(GLsizei size, GLuint *buffer);
extern  void ( APIENTRY * qglShadeModel )(GLenum mode);
extern  void ( APIENTRY * qglStencilFunc )(GLenum func, GLint ref, GLuint mask);
extern  void ( APIENTRY * qglStencilMask )(GLuint mask);
extern  void ( APIENTRY * qglStencilOp )(GLenum fail, GLenum zfail, GLenum zpass);
extern  void ( APIENTRY * qglTexCoord1d )(GLdouble s);
extern  void ( APIENTRY * qglTexCoord1dv )(const GLdouble *v);
extern  void ( APIENTRY * qglTexCoord1f )(GLfloat s);
extern  void ( APIENTRY * qglTexCoord1fv )(const GLfloat *v);
extern  void ( APIENTRY * qglTexCoord1i )(GLint s);
extern  void ( APIENTRY * qglTexCoord1iv )(const GLint *v);
extern  void ( APIENTRY * qglTexCoord1s )(GLshort s);
extern  void ( APIENTRY * qglTexCoord1sv )(const GLshort *v);
extern  void ( APIENTRY * qglTexCoord2d )(GLdouble s, GLdouble t);
extern  void ( APIENTRY * qglTexCoord2dv )(const GLdouble *v);
extern  void ( APIENTRY * qglTexCoord2f )(GLfloat s, GLfloat t);
extern  void ( APIENTRY * qglTexCoord2fv )(const GLfloat *v);
extern  void ( APIENTRY * qglTexCoord2i )(GLint s, GLint t);
extern  void ( APIENTRY * qglTexCoord2iv )(const GLint *v);
extern  void ( APIENTRY * qglTexCoord2s )(GLshort s, GLshort t);
extern  void ( APIENTRY * qglTexCoord2sv )(const GLshort *v);
extern  void ( APIENTRY * qglTexCoord3d )(GLdouble s, GLdouble t, GLdouble r);
extern  void ( APIENTRY * qglTexCoord3dv )(const GLdouble *v);
extern  void ( APIENTRY * qglTexCoord3f )(GLfloat s, GLfloat t, GLfloat r);
extern  void ( APIENTRY * qglTexCoord3fv )(const GLfloat *v);
extern  void ( APIENTRY * qglTexCoord3i )(GLint s, GLint t, GLint r);
extern  void ( APIENTRY * qglTexCoord3iv )(const GLint *v);
extern  void ( APIENTRY * qglTexCoord3s )(GLshort s, GLshort t, GLshort r);
extern  void ( APIENTRY * qglTexCoord3sv )(const GLshort *v);
extern  void ( APIENTRY * qglTexCoord4d )(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
extern  void ( APIENTRY * qglTexCoord4dv )(const GLdouble *v);
extern  void ( APIENTRY * qglTexCoord4f )(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern  void ( APIENTRY * qglTexCoord4fv )(const GLfloat *v);
extern  void ( APIENTRY * qglTexCoord4i )(GLint s, GLint t, GLint r, GLint q);
extern  void ( APIENTRY * qglTexCoord4iv )(const GLint *v);
extern  void ( APIENTRY * qglTexCoord4s )(GLshort s, GLshort t, GLshort r, GLshort q);
extern  void ( APIENTRY * qglTexCoord4sv )(const GLshort *v);
extern  void ( APIENTRY * qglTexCoordPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern  void ( APIENTRY * qglTexEnvf )(GLenum target, GLenum pname, GLfloat param);
extern  void ( APIENTRY * qglTexEnvfv )(GLenum target, GLenum pname, const GLfloat *params);
extern  void ( APIENTRY * qglTexEnvi )(GLenum target, GLenum pname, GLint param);
extern  void ( APIENTRY * qglTexEnviv )(GLenum target, GLenum pname, const GLint *params);
extern  void ( APIENTRY * qglTexGend )(GLenum coord, GLenum pname, GLdouble param);
extern  void ( APIENTRY * qglTexGendv )(GLenum coord, GLenum pname, const GLdouble *params);
extern  void ( APIENTRY * qglTexGenf )(GLenum coord, GLenum pname, GLfloat param);
extern  void ( APIENTRY * qglTexGenfv )(GLenum coord, GLenum pname, const GLfloat *params);
extern  void ( APIENTRY * qglTexGeni )(GLenum coord, GLenum pname, GLint param);
extern  void ( APIENTRY * qglTexGeniv )(GLenum coord, GLenum pname, const GLint *params);
extern  void ( APIENTRY * qglTexImage1D )(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
extern  void ( APIENTRY * qglTexImage2D )(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
extern  void ( APIENTRY * qglTexParameterf )(GLenum target, GLenum pname, GLfloat param);
extern  void ( APIENTRY * qglTexParameterfv )(GLenum target, GLenum pname, const GLfloat *params);
extern  void ( APIENTRY * qglTexParameteri )(GLenum target, GLenum pname, GLint param);
extern  void ( APIENTRY * qglTexParameteriv )(GLenum target, GLenum pname, const GLint *params);
extern  void ( APIENTRY * qglTexSubImage1D )(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
extern  void ( APIENTRY * qglTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
extern  void ( APIENTRY * qglTranslated )(GLdouble x, GLdouble y, GLdouble z);
extern  void ( APIENTRY * qglTranslatef )(GLfloat x, GLfloat y, GLfloat z);
extern  void ( APIENTRY * qglVertex2d )(GLdouble x, GLdouble y);
extern  void ( APIENTRY * qglVertex2dv )(const GLdouble *v);
extern  void ( APIENTRY * qglVertex2f )(GLfloat x, GLfloat y);
extern  void ( APIENTRY * qglVertex2fv )(const GLfloat *v);
extern  void ( APIENTRY * qglVertex2i )(GLint x, GLint y);
extern  void ( APIENTRY * qglVertex2iv )(const GLint *v);
extern  void ( APIENTRY * qglVertex2s )(GLshort x, GLshort y);
extern  void ( APIENTRY * qglVertex2sv )(const GLshort *v);
extern  void ( APIENTRY * qglVertex3d )(GLdouble x, GLdouble y, GLdouble z);
extern  void ( APIENTRY * qglVertex3dv )(const GLdouble *v);
extern  void ( APIENTRY * qglVertex3f )(GLfloat x, GLfloat y, GLfloat z);
extern  void ( APIENTRY * qglVertex3fv )(const GLfloat *v);
extern  void ( APIENTRY * qglVertex3i )(GLint x, GLint y, GLint z);
extern  void ( APIENTRY * qglVertex3iv )(const GLint *v);
extern  void ( APIENTRY * qglVertex3s )(GLshort x, GLshort y, GLshort z);
extern  void ( APIENTRY * qglVertex3sv )(const GLshort *v);
extern  void ( APIENTRY * qglVertex4d )(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern  void ( APIENTRY * qglVertex4dv )(const GLdouble *v);
extern  void ( APIENTRY * qglVertex4f )(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern  void ( APIENTRY * qglVertex4fv )(const GLfloat *v);
extern  void ( APIENTRY * qglVertex4i )(GLint x, GLint y, GLint z, GLint w);
extern  void ( APIENTRY * qglVertex4iv )(const GLint *v);
extern  void ( APIENTRY * qglVertex4s )(GLshort x, GLshort y, GLshort z, GLshort w);
extern  void ( APIENTRY * qglVertex4sv )(const GLshort *v);
extern  void ( APIENTRY * qglVertexPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern  void ( APIENTRY * qglViewport )(GLint x, GLint y, GLsizei width, GLsizei height);

extern	void ( APIENTRY * qglPointParameterfEXT)( GLenum param, GLfloat value );
extern	void ( APIENTRY * qglPointParameterfvEXT)( GLenum param, const GLfloat *value );
extern	void ( APIENTRY * qglColorTableEXT)( int, int, int, int, int, const void * );

extern	void ( APIENTRY * qglLockArraysEXT) (int , int);
extern	void ( APIENTRY * qglUnlockArraysEXT) (void);

extern	void ( APIENTRY * qglMTexCoord2fSGIS)( GLenum, GLfloat, GLfloat );
extern	void ( APIENTRY * qglSelectTextureSGIS)( GLenum );

#ifdef _WIN32

extern  int   ( WINAPI * qwglChoosePixelFormat )(HDC, CONST PIXELFORMATDESCRIPTOR *);
extern  int   ( WINAPI * qwglDescribePixelFormat) (HDC, int, UINT, LPPIXELFORMATDESCRIPTOR);
extern  int   ( WINAPI * qwglGetPixelFormat)(HDC);
extern  BOOL  ( WINAPI * qwglSetPixelFormat)(HDC, int, CONST PIXELFORMATDESCRIPTOR *);
extern  BOOL  ( WINAPI * qwglSwapBuffers)(HDC);

extern BOOL  ( WINAPI * qwglCopyContext)(HGLRC, HGLRC, UINT);
extern HGLRC ( WINAPI * qwglCreateContext)(HDC);
extern HGLRC ( WINAPI * qwglCreateLayerContext)(HDC, int);
extern BOOL  ( WINAPI * qwglDeleteContext)(HGLRC);
extern HGLRC ( WINAPI * qwglGetCurrentContext)(VOID);
extern HDC   ( WINAPI * qwglGetCurrentDC)(VOID);
extern PROC  ( WINAPI * qwglGetProcAddress)(LPCSTR);
extern BOOL  ( WINAPI * qwglMakeCurrent)(HDC, HGLRC);
extern BOOL  ( WINAPI * qwglShareLists)(HGLRC, HGLRC);
extern BOOL  ( WINAPI * qwglUseFontBitmaps)(HDC, DWORD, DWORD, DWORD);

extern BOOL  ( WINAPI * qwglUseFontOutlines)(HDC, DWORD, DWORD, DWORD, FLOAT,
                                           FLOAT, int, LPGLYPHMETRICSFLOAT);

extern BOOL ( WINAPI * qwglDescribeLayerPlane)(HDC, int, int, UINT,
                                            LPLAYERPLANEDESCRIPTOR);
extern int  ( WINAPI * qwglSetLayerPaletteEntries)(HDC, int, int, int,
                                                CONST COLORREF *);
extern int  ( WINAPI * qwglGetLayerPaletteEntries)(HDC, int, int, int,
                                                COLORREF *);
extern BOOL ( WINAPI * qwglRealizeLayerPalette)(HDC, int, BOOL);
extern BOOL ( WINAPI * qwglSwapLayerBuffers)(HDC, UINT);

extern BOOL ( WINAPI * qwglSwapIntervalEXT)( int interval );

extern BOOL ( WINAPI * qwglGetDeviceGammaRampEXT ) ( unsigned char *pRed, unsigned char *pGreen, unsigned char *pBlue );
extern BOOL ( WINAPI * qwglSetDeviceGammaRampEXT ) ( const unsigned char *pRed, const unsigned char *pGreen, const unsigned char *pBlue );

#endif

/*
** extension constants
*/
#define GL_POINT_SIZE_MIN_EXT				0x8126
#define GL_POINT_SIZE_MAX_EXT				0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT	0x8128
#define GL_DISTANCE_ATTENUATION_EXT			0x8129

#ifdef __sgi
#define GL_SHARED_TEXTURE_PALETTE_EXT		GL_TEXTURE_COLOR_TABLE_SGI
#else
#define GL_SHARED_TEXTURE_PALETTE_EXT		0x81FB
#endif

#define GL_TEXTURE0_SGIS					0x835E
#define GL_TEXTURE1_SGIS					0x835F

#endif
/* ============ end inlined header: ref_gl/qgl.h ============ */

#define	REF_VERSION	"GL 0.01"

// up / down
#define	PITCH	0

// left / right
#define	YAW		1

// fall over
#define	ROLL	2


typedef struct
{
	unsigned		width, height;			// coordinates from main game
} rviddef_t;

extern	rviddef_t	vid;


/*

  skins will be outline flood filled and mip mapped
  pics and sprites with alpha will be outline flood filled
  pic won't be mip mapped

  model skin
  sprite frame
  wall texture
  pic

*/

typedef enum 
{
	it_skin,
	it_sprite,
	it_wall,
	it_pic,
	it_sky
} imagetype_t;

typedef struct image_s
{
	char	name[MAX_QPATH];			// game path, including extension
	imagetype_t	type;
	int		width, height;				// source image
	int		upload_width, upload_height;	// after power of two and picmip
	int		registration_sequence;		// 0 = free
	struct msurface_s	*texturechain;	// for sort-by-texture world drawing
	int		texnum;						// gl texture binding
	float	sl, tl, sh, th;				// 0,0 - 1,1 unless part of the scrap
	qboolean	scrap;
	qboolean	has_alpha;

	qboolean paletted;
} image_t;

#define	TEXNUM_LIGHTMAPS	1024
#define	TEXNUM_SCRAPS		1152
#define	TEXNUM_IMAGES		1153

#define		MAX_GLTEXTURES	1024

//===================================================================

typedef enum
{
	rserr_ok,

	rserr_invalid_fullscreen,
	rserr_invalid_mode,

	rserr_unknown
} rserr_t;

/* ============ begin inlined header: ref_gl/gl_model.h ============ */
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

/*

d*_t structures are on-disk representations
m*_t structures are in-memory

*/

/*
==============================================================================

BRUSH MODELS

==============================================================================
*/


//
// in memory representation
//
// !!! if this is changed, it must be changed in asm_draw.h too !!!
typedef struct
{
	vec3_t		position;
} mvertex_t;

typedef struct
{
	vec3_t		mins, maxs;
	vec3_t		origin;		// for sounds or lights
	float		radius;
	int			headnode;
	int			visleafs;		// not including the solid leaf 0
	int			firstface, numfaces;
} mmodel_t;


#define	SIDE_FRONT	0
#define	SIDE_BACK	1
#define	SIDE_ON		2


#define	SURF_PLANEBACK		2
#define	SURF_DRAWSKY		4
#define SURF_DRAWTURB		0x10
#define SURF_DRAWBACKGROUND	0x40
#define SURF_UNDERWATER		0x80

// !!! if this is changed, it must be changed in asm_draw.h too !!!
typedef struct
{
	unsigned short	v[2];
	unsigned int	cachededgeoffset;
} medge_t;

typedef struct mtexinfo_s
{
	float		vecs[2][4];
	int			flags;
	int			numframes;
	struct mtexinfo_s	*next;		// animation chain
	image_t		*image;
} mtexinfo_t;

#define	VERTEXSIZE	7

typedef struct glpoly_s
{
	struct	glpoly_s	*next;
	struct	glpoly_s	*chain;
	int		numverts;
	int		flags;			// for SURF_UNDERWATER (not needed anymore?)
	float	verts[4][VERTEXSIZE];	// variable sized (xyz s1t1 s2t2)
} glpoly_t;

typedef struct msurface_s
{
	int			visframe;		// should be drawn when node is crossed

	cplane_t	*plane;
	int			flags;

	int			firstedge;	// look up in model->surfedges[], negative numbers
	int			numedges;	// are backwards edges
	
	short		texturemins[2];
	short		extents[2];

	int			light_s, light_t;	// gl lightmap coordinates
	int			dlight_s, dlight_t; // gl lightmap coordinates for dynamic lightmaps

	glpoly_t	*polys;				// multiple if warped
	struct	msurface_s	*texturechain;
	struct  msurface_s	*lightmapchain;

	mtexinfo_t	*texinfo;
	
// lighting info
	int			dlightframe;
	int			dlightbits;

	int			lightmaptexturenum;
	byte		styles[MAXLIGHTMAPS];
	float		cached_light[MAXLIGHTMAPS];	// values currently used in lightmap
	byte		*samples;		// [numstyles*surfsize]
} msurface_t;

typedef struct mnode_s
{
// common with leaf
	int			contents;		// -1, to differentiate from leafs
	int			visframe;		// node needs to be traversed if current
	
	float		minmaxs[6];		// for bounding box culling

	struct mnode_s	*parent;

// node specific
	cplane_t	*plane;
	struct mnode_s	*children[2];	

	unsigned short		firstsurface;
	unsigned short		numsurfaces;
} mnode_t;



typedef struct mleaf_s
{
// common with node
	int			contents;		// wil be a negative contents number
	int			visframe;		// node needs to be traversed if current

	float		minmaxs[6];		// for bounding box culling

	struct mnode_s	*parent;

// leaf specific
	int			cluster;
	int			area;

	msurface_t	**firstmarksurface;
	int			nummarksurfaces;
} mleaf_t;


//===================================================================

//
// Whole model
//

typedef enum {mod_bad, mod_brush, mod_sprite, mod_alias } modtype_t;

typedef struct model_s
{
	char		name[MAX_QPATH];

	int			registration_sequence;

	modtype_t	type;
	int			numframes;
	
	int			flags;

//
// volume occupied by the model graphics
//		
	vec3_t		mins, maxs;
	float		radius;

//
// solid volume for clipping 
//
	qboolean	clipbox;
	vec3_t		clipmins, clipmaxs;

//
// brush model
//
	int			firstmodelsurface, nummodelsurfaces;
	int			lightmap;		// only for submodels

	int			numsubmodels;
	mmodel_t	*submodels;

	int			numplanes;
	cplane_t	*planes;

	int			numleafs;		// number of visible leafs, not counting 0
	mleaf_t		*leafs;

	int			numvertexes;
	mvertex_t	*vertexes;

	int			numedges;
	medge_t		*edges;

	int			numnodes;
	int			firstnode;
	mnode_t		*nodes;

	int			numtexinfo;
	mtexinfo_t	*texinfo;

	int			numsurfaces;
	msurface_t	*surfaces;

	int			numsurfedges;
	int			*surfedges;

	int			nummarksurfaces;
	msurface_t	**marksurfaces;

	dvis_t		*vis;

	byte		*lightdata;

	// for alias models and skins
	image_t		*skins[MAX_MD2SKINS];

	int			extradatasize;
	void		*extradata;
} model_t;

//============================================================================

void	Mod_Init (void);
void	Mod_ClearAll (void);
model_t *Mod_ForName (char *name, qboolean crash);
mleaf_t *Mod_PointInLeaf (float *p, model_t *model);
byte	*Mod_ClusterPVS (int cluster, model_t *model);

void	Mod_Modellist_f (void);

void	*Hunk_Begin (int maxsize);
void	*Hunk_Alloc (int size);
int		Hunk_End (void);
void	Hunk_Free (void *base);

void	Mod_FreeAll (void);
void	Mod_Free (model_t *mod);
/* ============ end inlined header: ref_gl/gl_model.h ============ */

void GL_BeginRendering (int *x, int *y, int *width, int *height);
void GL_EndRendering (void);

void GL_SetDefaultState( void );
void GL_UpdateSwapInterval( void );

extern	float	gldepthmin, gldepthmax;

typedef struct
{
	float	x, y, z;
	float	s, t;
	float	r, g, b;
} glvert_t;


#define	MAX_LBM_HEIGHT		480

#define BACKFACE_EPSILON	0.01


//====================================================

extern	image_t		gltextures[MAX_GLTEXTURES];
extern	int			numgltextures;


extern	image_t		*r_notexture;
extern	image_t		*r_particletexture;
extern	entity_t	*currententity;
extern	model_t		*currentmodel;
extern	int			r_visframecount;
extern	int			r_framecount;
extern	cplane_t	frustum[4];
extern	int			c_brush_polys, c_alias_polys;


extern	int			gl_filter_min, gl_filter_max;

//
// view origin
//
extern	vec3_t	vup;
extern	vec3_t	vpn;
extern	vec3_t	vright;
extern	vec3_t	r_origin;

//
// screen size info
//
extern	refdef_t	r_newrefdef;
extern	int		r_viewcluster, r_viewcluster2, r_oldviewcluster, r_oldviewcluster2;

extern	cvar_t	*r_norefresh;
extern	cvar_t	*r_lefthand;
extern	cvar_t	*r_drawentities;
extern	cvar_t	*r_drawworld;
extern	cvar_t	*r_speeds;
extern	cvar_t	*r_fullbright;
extern	cvar_t	*r_novis;
extern	cvar_t	*r_nocull;
extern	cvar_t	*r_lerpmodels;

extern	cvar_t	*r_lightlevel;	// FIXME: This is a HACK to get the client's light level

extern cvar_t	*gl_vertex_arrays;

extern cvar_t	*gl_ext_swapinterval;
extern cvar_t	*gl_ext_palettedtexture;
extern cvar_t	*gl_ext_multitexture;
extern cvar_t	*gl_ext_pointparameters;
extern cvar_t	*gl_ext_compiled_vertex_array;

extern cvar_t	*gl_particle_min_size;
extern cvar_t	*gl_particle_max_size;
extern cvar_t	*gl_particle_size;
extern cvar_t	*gl_particle_att_a;
extern cvar_t	*gl_particle_att_b;
extern cvar_t	*gl_particle_att_c;

extern	cvar_t	*gl_nosubimage;
extern	cvar_t	*gl_bitdepth;
extern	cvar_t	*gl_mode;
extern	cvar_t	*gl_log;
extern	cvar_t	*gl_lightmap;
extern	cvar_t	*gl_shadows;
extern	cvar_t	*gl_dynamic;
extern  cvar_t  *gl_monolightmap;
extern	cvar_t	*gl_nobind;
extern	cvar_t	*gl_round_down;
extern	cvar_t	*gl_picmip;
extern	cvar_t	*gl_skymip;
extern	cvar_t	*gl_showtris;
extern	cvar_t	*gl_finish;
extern	cvar_t	*gl_ztrick;
extern	cvar_t	*gl_clear;
extern	cvar_t	*gl_cull;
extern	cvar_t	*gl_poly;
extern	cvar_t	*gl_texsort;
extern	cvar_t	*gl_polyblend;
extern	cvar_t	*gl_flashblend;
extern	cvar_t	*gl_lightmaptype;
extern	cvar_t	*gl_modulate;
extern	cvar_t	*gl_playermip;
extern	cvar_t	*gl_drawbuffer;
extern	cvar_t	*gl_3dlabs_broken;
extern  cvar_t  *gl_driver;
extern	cvar_t	*gl_swapinterval;
extern	cvar_t	*gl_texturemode;
extern	cvar_t	*gl_texturealphamode;
extern	cvar_t	*gl_texturesolidmode;
extern  cvar_t  *gl_saturatelighting;
extern  cvar_t  *gl_lockpvs;

extern	cvar_t	*vid_fullscreen;
extern	cvar_t	*vid_gamma;

extern	cvar_t		*intensity;

extern	int		gl_lightmap_format;
extern	int		gl_solid_format;
extern	int		gl_alpha_format;
extern	int		gl_tex_solid_format;
extern	int		gl_tex_alpha_format;

extern	int		c_visible_lightmaps;
extern	int		c_visible_textures;

extern	float	r_world_matrix[16];

void R_TranslatePlayerSkin (int playernum);
void GL_Bind (int texnum);
void GL_MBind( GLenum target, int texnum );
void GL_TexEnv( GLenum value );
void GL_EnableMultitexture( qboolean enable );
void GL_SelectTexture( GLenum );

void R_LightPoint (vec3_t p, vec3_t color);
void R_PushDlights (void);

//====================================================================

extern	model_t	*r_worldmodel;

extern	unsigned	d_8to24table[256];

extern	int		registration_sequence;


void V_AddBlend (float r, float g, float b, float a, float *v_blend);

int 	R_Init( void *hinstance, void *hWnd );
void	R_Shutdown( void );

void R_RenderView (refdef_t *fd);
void GL_ScreenShot_f (void);
void R_DrawAliasModel (entity_t *e);
void R_DrawBrushModel (entity_t *e);
void R_DrawSpriteModel (entity_t *e);
void R_DrawBeam( entity_t *e );
void R_DrawWorld (void);
void R_RenderDlights (void);
void R_DrawAlphaSurfaces (void);
void R_RenderBrushPoly (msurface_t *fa);
void R_InitParticleTexture (void);
void Draw_InitLocal (void);
void GL_SubdivideSurface (msurface_t *fa);
qboolean R_CullBox (vec3_t mins, vec3_t maxs);
void R_RotateForEntity (entity_t *e);
void R_MarkLeaves (void);

glpoly_t *WaterWarpPolyVerts (glpoly_t *p);
void EmitWaterPolys (msurface_t *fa);
void R_AddSkySurface (msurface_t *fa);
void R_ClearSkyBox (void);
void R_DrawSkyBox (void);
void R_MarkLights (dlight_t *light, int bit, mnode_t *node);

#if 0
short LittleShort (short l);
short BigShort (short l);
int	LittleLong (int l);
float LittleFloat (float f);

char	*va(char *format, ...);
// does a varargs printf into a temp buffer
#endif

void COM_StripExtension (char *in, char *out);

void	Draw_GetPicSize (int *w, int *h, char *name);
void	Draw_Pic (int x, int y, char *name);
void	Draw_StretchPic (int x, int y, int w, int h, char *name);
void	Draw_Char (int x, int y, int c);
void	Draw_TileClear (int x, int y, int w, int h, char *name);
void	Draw_Fill (int x, int y, int w, int h, int c);
void	Draw_FadeScreen (void);
void	Draw_StretchRaw (int x, int y, int w, int h, int cols, int rows, byte *data);

void	R_BeginFrame( float camera_separation );
void	R_SwapBuffers( int );
void	R_SetPalette ( const unsigned char *palette);

int		Draw_GetPalette (void);

void GL_ResampleTexture (unsigned *in, int inwidth, int inheight, unsigned *out,  int outwidth, int outheight);

struct image_s *R_RegisterSkin (char *name);

void LoadPCX (char *filename, byte **pic, byte **palette, int *width, int *height);
image_t *GL_LoadPic (char *name, byte *pic, int width, int height, imagetype_t type, int bits);
image_t	*GL_FindImage (char *name, imagetype_t type);
void	GL_TextureMode( char *string );
void	GL_ImageList_f (void);

void	GL_SetTexturePalette( unsigned palette[256] );

void	GL_InitImages (void);
void	GL_ShutdownImages (void);

void	GL_FreeUnusedImages (void);

void GL_TextureAlphaMode( char *string );
void GL_TextureSolidMode( char *string );

/*
** GL extension emulation functions
*/
void GL_DrawParticles( int n, const particle_t particles[], const unsigned colortable[768] );

/*
** GL config stuff
*/
#define GL_RENDERER_VOODOO		0x00000001
#define GL_RENDERER_VOODOO2   	0x00000002
#define GL_RENDERER_VOODOO_RUSH	0x00000004
#define GL_RENDERER_BANSHEE		0x00000008
#define		GL_RENDERER_3DFX		0x0000000F

#define GL_RENDERER_PCX1		0x00000010
#define GL_RENDERER_PCX2		0x00000020
#define GL_RENDERER_PMX			0x00000040
#define		GL_RENDERER_POWERVR		0x00000070

#define GL_RENDERER_PERMEDIA2	0x00000100
#define GL_RENDERER_GLINT_MX	0x00000200
#define GL_RENDERER_GLINT_TX	0x00000400
#define GL_RENDERER_3DLABS_MISC	0x00000800
#define		GL_RENDERER_3DLABS	0x00000F00

#define GL_RENDERER_REALIZM		0x00001000
#define GL_RENDERER_REALIZM2	0x00002000
#define		GL_RENDERER_INTERGRAPH	0x00003000

#define GL_RENDERER_3DPRO		0x00004000
#define GL_RENDERER_REAL3D		0x00008000
#define GL_RENDERER_RIVA128		0x00010000
#define GL_RENDERER_DYPIC		0x00020000

#define GL_RENDERER_V1000		0x00040000
#define GL_RENDERER_V2100		0x00080000
#define GL_RENDERER_V2200		0x00100000
#define		GL_RENDERER_RENDITION	0x001C0000

#define GL_RENDERER_O2          0x00100000
#define GL_RENDERER_IMPACT      0x00200000
#define GL_RENDERER_RE			0x00400000
#define GL_RENDERER_IR			0x00800000
#define		GL_RENDERER_SGI			0x00F00000

#define GL_RENDERER_MCD			0x01000000
#define GL_RENDERER_OTHER		0x80000000

typedef struct
{
	int         renderer;
	const char *renderer_string;
	const char *vendor_string;
	const char *version_string;
	const char *extensions_string;

	qboolean	allow_cds;
} glconfig_t;

typedef struct
{
	float inverse_intensity;
	qboolean fullscreen;

	int     prev_mode;

	unsigned char *d_16to8table;

	int lightmap_textures;

	int	currenttextures[2];
	int currenttmu;

	float camera_separation;
	qboolean stereo_enabled;

	unsigned char originalRedGammaTable[256];
	unsigned char originalGreenGammaTable[256];
	unsigned char originalBlueGammaTable[256];
} glstate_t;

extern glconfig_t  gl_config;
extern glstate_t   gl_state;

/*
====================================================================

IMPORTED FUNCTIONS

====================================================================
*/

extern	refimport_t	ri;


/*
====================================================================

IMPLEMENTATION SPECIFIC FUNCTIONS

====================================================================
*/

void		GLimp_BeginFrame( float camera_separation );
void		GLimp_EndFrame( void );
int 		GLimp_Init( void *hinstance, void *hWnd );
void		GLimp_Shutdown( void );
int     	GLimp_SetMode( int *pwidth, int *pheight, int mode, qboolean fullscreen );
void		GLimp_AppActivate( qboolean active );
void		GLimp_EnableLogging( qboolean enable );
void		GLimp_LogNewFrame( void );

#endif	// GL_LOCAL_H

/* ============ end inlined header: ref_gl/gl_local.h ============ */

image_t		*draw_chars;

extern	qboolean	scrap_dirty;
void Scrap_Upload (void);


/*
===============
Draw_InitLocal
===============
*/
void Draw_InitLocal (void)
{
	// load console characters (don't bilerp characters)
	draw_chars = GL_FindImage ("pics/conchars.pcx", it_pic);
	GL_Bind( draw_chars->texnum );
	qglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	qglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}



/*
================
Draw_Char

Draws one 8*8 graphics character with 0 being transparent.
It can be clipped to the top of the screen to allow the console to be
smoothly scrolled off.
================
*/
void Draw_Char (int x, int y, int num)
{
	int				row, col;
	float			frow, fcol, size;

	num &= 255;
	
	if ( (num&127) == 32 )
		return;		// space

	if (y <= -8)
		return;			// totally off screen

	row = num>>4;
	col = num&15;

	frow = row*0.0625;
	fcol = col*0.0625;
	size = 0.0625;

	GL_Bind (draw_chars->texnum);

	qglBegin (GL_QUADS);
	qglTexCoord2f (fcol, frow);
	qglVertex2f (x, y);
	qglTexCoord2f (fcol + size, frow);
	qglVertex2f (x+8, y);
	qglTexCoord2f (fcol + size, frow + size);
	qglVertex2f (x+8, y+8);
	qglTexCoord2f (fcol, frow + size);
	qglVertex2f (x, y+8);
	qglEnd ();
}

/*
=============
Draw_FindPic
=============
*/
image_t	*Draw_FindPic (char *name)
{
	image_t *gl;
	char	fullname[MAX_QPATH];

	if (name[0] != '/' && name[0] != '\\')
	{
		Com_sprintf (fullname, sizeof(fullname), "pics/%s.pcx", name);
		gl = GL_FindImage (fullname, it_pic);
	}
	else
		gl = GL_FindImage (name+1, it_pic);

	return gl;
}

/*
=============
Draw_GetPicSize
=============
*/
void Draw_GetPicSize (int *w, int *h, char *pic)
{
	image_t *gl;

	gl = Draw_FindPic (pic);
	if (!gl)
	{
		*w = *h = -1;
		return;
	}
	*w = gl->width;
	*h = gl->height;
}

/*
=============
Draw_StretchPic
=============
*/
void Draw_StretchPic (int x, int y, int w, int h, char *pic)
{
	image_t *gl;

	gl = Draw_FindPic (pic);
	if (!gl)
	{
		ri.Con_Printf (PRINT_ALL, "Can't find pic: %s\n", pic);
		return;
	}

	if (scrap_dirty)
		Scrap_Upload ();

	if ( ( ( gl_config.renderer == GL_RENDERER_MCD ) || ( gl_config.renderer & GL_RENDERER_RENDITION ) ) && !gl->has_alpha)
		qglDisable (GL_ALPHA_TEST);

	GL_Bind (gl->texnum);
	qglBegin (GL_QUADS);
	qglTexCoord2f (gl->sl, gl->tl);
	qglVertex2f (x, y);
	qglTexCoord2f (gl->sh, gl->tl);
	qglVertex2f (x+w, y);
	qglTexCoord2f (gl->sh, gl->th);
	qglVertex2f (x+w, y+h);
	qglTexCoord2f (gl->sl, gl->th);
	qglVertex2f (x, y+h);
	qglEnd ();

	if ( ( ( gl_config.renderer == GL_RENDERER_MCD ) || ( gl_config.renderer & GL_RENDERER_RENDITION ) ) && !gl->has_alpha)
		qglEnable (GL_ALPHA_TEST);
}


/*
=============
Draw_Pic
=============
*/
void Draw_Pic (int x, int y, char *pic)
{
	image_t *gl;

	gl = Draw_FindPic (pic);
	if (!gl)
	{
		ri.Con_Printf (PRINT_ALL, "Can't find pic: %s\n", pic);
		return;
	}
	if (scrap_dirty)
		Scrap_Upload ();

	if ( ( ( gl_config.renderer == GL_RENDERER_MCD ) || ( gl_config.renderer & GL_RENDERER_RENDITION ) ) && !gl->has_alpha)
		qglDisable (GL_ALPHA_TEST);

	GL_Bind (gl->texnum);
	qglBegin (GL_QUADS);
	qglTexCoord2f (gl->sl, gl->tl);
	qglVertex2f (x, y);
	qglTexCoord2f (gl->sh, gl->tl);
	qglVertex2f (x+gl->width, y);
	qglTexCoord2f (gl->sh, gl->th);
	qglVertex2f (x+gl->width, y+gl->height);
	qglTexCoord2f (gl->sl, gl->th);
	qglVertex2f (x, y+gl->height);
	qglEnd ();

	if ( ( ( gl_config.renderer == GL_RENDERER_MCD ) || ( gl_config.renderer & GL_RENDERER_RENDITION ) )  && !gl->has_alpha)
		qglEnable (GL_ALPHA_TEST);
}

/*
=============
Draw_TileClear

This repeats a 64*64 tile graphic to fill the screen around a sized down
refresh window.
=============
*/
void Draw_TileClear (int x, int y, int w, int h, char *pic)
{
	image_t	*image;

	image = Draw_FindPic (pic);
	if (!image)
	{
		ri.Con_Printf (PRINT_ALL, "Can't find pic: %s\n", pic);
		return;
	}

	if ( ( ( gl_config.renderer == GL_RENDERER_MCD ) || ( gl_config.renderer & GL_RENDERER_RENDITION ) )  && !image->has_alpha)
		qglDisable (GL_ALPHA_TEST);

	GL_Bind (image->texnum);
	qglBegin (GL_QUADS);
	qglTexCoord2f (x/64.0, y/64.0);
	qglVertex2f (x, y);
	qglTexCoord2f ( (x+w)/64.0, y/64.0);
	qglVertex2f (x+w, y);
	qglTexCoord2f ( (x+w)/64.0, (y+h)/64.0);
	qglVertex2f (x+w, y+h);
	qglTexCoord2f ( x/64.0, (y+h)/64.0 );
	qglVertex2f (x, y+h);
	qglEnd ();

	if ( ( ( gl_config.renderer == GL_RENDERER_MCD ) || ( gl_config.renderer & GL_RENDERER_RENDITION ) )  && !image->has_alpha)
		qglEnable (GL_ALPHA_TEST);
}


/*
=============
Draw_Fill

Fills a box of pixels with a single color
=============
*/
void Draw_Fill (int x, int y, int w, int h, int c)
{
	union
	{
		unsigned	c;
		byte		v[4];
	} color;

	if ( (unsigned)c > 255)
		ri.Sys_Error (ERR_FATAL, "Draw_Fill: bad color");

	qglDisable (GL_TEXTURE_2D);

	color.c = d_8to24table[c];
	qglColor3f (color.v[0]/255.0,
		color.v[1]/255.0,
		color.v[2]/255.0);

	qglBegin (GL_QUADS);

	qglVertex2f (x,y);
	qglVertex2f (x+w, y);
	qglVertex2f (x+w, y+h);
	qglVertex2f (x, y+h);

	qglEnd ();
	qglColor3f (1,1,1);
	qglEnable (GL_TEXTURE_2D);
}

//=============================================================================

/*
================
Draw_FadeScreen

================
*/
void Draw_FadeScreen (void)
{
	qglEnable (GL_BLEND);
	qglDisable (GL_TEXTURE_2D);
	qglColor4f (0, 0, 0, 0.8);
	qglBegin (GL_QUADS);

	qglVertex2f (0,0);
	qglVertex2f (vid.width, 0);
	qglVertex2f (vid.width, vid.height);
	qglVertex2f (0, vid.height);

	qglEnd ();
	qglColor4f (1,1,1,1);
	qglEnable (GL_TEXTURE_2D);
	qglDisable (GL_BLEND);
}


//====================================================================


/*
=============
Draw_StretchRaw
=============
*/
extern unsigned	r_rawpalette[256];

void Draw_StretchRaw (int x, int y, int w, int h, int cols, int rows, byte *data)
{
	unsigned	image32[256*256];
	unsigned char image8[256*256];
	int			i, j, trows;
	byte		*source;
	int			frac, fracstep;
	float		hscale;
	int			row;
	float		t;

	GL_Bind (0);

	if (rows<=256)
	{
		hscale = 1;
		trows = rows;
	}
	else
	{
		hscale = rows/256.0;
		trows = 256;
	}
	t = rows*hscale / 256;

	if ( !qglColorTableEXT )
	{
		unsigned *dest;

		for (i=0 ; i<trows ; i++)
		{
			row = (int)(i*hscale);
			if (row > rows)
				break;
			source = data + cols*row;
			dest = &image32[i*256];
			fracstep = cols*0x10000/256;
			frac = fracstep >> 1;
			for (j=0 ; j<256 ; j++)
			{
				dest[j] = r_rawpalette[source[frac>>16]];
				frac += fracstep;
			}
		}

		qglTexImage2D (GL_TEXTURE_2D, 0, gl_tex_solid_format, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, image32);
	}
	else
	{
		unsigned char *dest;

		for (i=0 ; i<trows ; i++)
		{
			row = (int)(i*hscale);
			if (row > rows)
				break;
			source = data + cols*row;
			dest = &image8[i*256];
			fracstep = cols*0x10000/256;
			frac = fracstep >> 1;
			for (j=0 ; j<256 ; j++)
			{
				dest[j] = source[frac>>16];
				frac += fracstep;
			}
		}

		qglTexImage2D( GL_TEXTURE_2D, 
			           0, 
					   GL_COLOR_INDEX8_EXT, 
					   256, 256, 
					   0, 
					   GL_COLOR_INDEX, 
					   GL_UNSIGNED_BYTE, 
					   image8 );
	}
	qglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	qglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if ( ( gl_config.renderer == GL_RENDERER_MCD ) || ( gl_config.renderer & GL_RENDERER_RENDITION ) ) 
		qglDisable (GL_ALPHA_TEST);

	qglBegin (GL_QUADS);
	qglTexCoord2f (0, 0);
	qglVertex2f (x, y);
	qglTexCoord2f (1, 0);
	qglVertex2f (x+w, y);
	qglTexCoord2f (1, t);
	qglVertex2f (x+w, y+h);
	qglTexCoord2f (0, t);
	qglVertex2f (x, y+h);
	qglEnd ();

	if ( ( gl_config.renderer == GL_RENDERER_MCD ) || ( gl_config.renderer & GL_RENDERER_RENDITION ) ) 
		qglEnable (GL_ALPHA_TEST);
}

