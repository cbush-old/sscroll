#ifndef SSCROLL_GLX_H
#define SSCROLL_GLX_H

#include <iostream>
#include <cstdint>
#include <gl.h>

#undef __glext_h_
#undef GL_VERSION_1_5
#undef GL_VERSION_2_0
#define GL_GLEXT_PROTOTYPES
#include "glext.h"

#include <SDL.h>

void glxLoad();

#ifdef USE_WINDOWS_GLX


typedef void  (APIENTRY *glFunc_sizei_uintp)(GLsizei, GLuint*);
typedef void  (APIENTRY *glFunc_uint_sizei_sizeip_charp)(GLuint,GLsizei,GLsizei*,GLchar*);
typedef void  (APIENTRY *glFunc_uint_sizei_charpp_intp)(GLuint, GLsizei, const GLchar**, const GLint*);
typedef void  (APIENTRY *glFunc_enum)(GLenum);
typedef void  (APIENTRY *glFunc_enum_uint)(GLenum, GLuint);
typedef bool  (APIENTRY *glFunc_enum_r_bool)(GLenum);
typedef bool  (APIENTRY *glFunc_uint_r_bool)(GLuint);
typedef bool  (APIENTRY *glFunc_enum_r_uint)(GLenum);
typedef void  (APIENTRY *glFunc_enum_sizeiptr_voidp_enum)(GLenum, GLsizeiptr, GLvoid*, GLenum);
typedef void  (APIENTRY *glFunc_enum_intptr_sizeiptr_voidp)(GLenum, GLintptr, GLsizeiptr, GLvoid*);
typedef void  (APIENTRY *glFunc_uint)(GLuint);
typedef void  (APIENTRY *glFunc_uint_uint)(GLuint, GLuint);
typedef void  (APIENTRY *glFunc_uint_enum_intp)(GLuint, GLenum, GLint*);
typedef void* (APIENTRY *glFunc_enum_enum_r_voidp)(GLenum, GLenum);
typedef GLint  (APIENTRY *glFunc_uint_charp_r_int)(GLuint, const GLchar*);
typedef GLuint (APIENTRY *glFunc_void_r_uint)(void);
typedef void* (APIENTRY *glFunc_int_float)(GLint, GLfloat);
typedef void* (APIENTRY *glFunc_int_2float)(GLint, GLfloat, GLfloat); 
typedef void* (APIENTRY *glFunc_int_3float)(GLint, GLfloat, GLfloat, GLfloat);
typedef void* (APIENTRY *glFunc_int_4float)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void* (APIENTRY *glFunc_int_sizei_bool_floatp)(GLint, GLsizei, GLboolean, const GLfloat*);
typedef void* (APIENTRY *glFunc_enum_int_sizei)(GLenum, GLint, GLsizei);
typedef void* (APIENTRY *glFunc_uint_int_enum_bool_sizei_voidp)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*);

extern glFunc_int_float   glVertexAttrib1f, glUniform1f;
extern glFunc_int_2float  glVertexAttrib2f, glUniform2f;
extern glFunc_int_3float  glVertexAttrib3f, glUniform3f;
extern glFunc_int_4float  glVertexAttrib4f, glUniform4f;
extern glFunc_int_sizei_bool_floatp glUniformMatrix4fv;
extern glFunc_uint_sizei_charpp_intp  glShaderSource;
extern glFunc_uint_charp_r_int   glGetUniformLocation, glGetAttribLocation;
extern glFunc_sizei_uintp  glGenBuffers, glDeleteBuffers;
extern glFunc_enum         glBlendEquation;
extern glFunc_enum_r_bool  glUnmapBuffer;
extern glFunc_uint_r_bool  glIsShader, glIsProgram;
extern glFunc_enum_r_uint  glCreateShader;
extern glFunc_enum_uint    glBindBuffer;
extern glFunc_uint_enum_intp    glGetShaderiv, glGetProgramiv;
extern glFunc_enum_enum_r_voidp  glMapBuffer;
extern glFunc_enum_sizeiptr_voidp_enum  glBufferData;
extern glFunc_enum_intptr_sizeiptr_voidp  glBufferSubData;
extern glFunc_void_r_uint  glCreateProgram;
extern glFunc_uint_int_enum_bool_sizei_voidp glVertexAttribPointer;
extern glFunc_uint  
  glLinkProgram,
  glUseProgram,
  glDeleteProgram,
  glDeleteShader,
  glCompileShader,
  glEnableVertexAttribArray,
  glDisableVertexAttribArray;
extern glFunc_uint_uint
  glAttachShader,
  glDetachShader;
extern glFunc_uint_sizei_sizeip_charp
  glGetShaderInfoLog,
  glGetProgramInfoLog;

#endif
#endif