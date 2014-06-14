#include "windows_glx.h"

#ifdef USE_WINDOWS_GLX
glFunc_enum 
  glBlendEquation       = NULL;
  
glFunc_int_float
  glUniform1f           = NULL,
  glVertexAttrib1f      = NULL;
  
glFunc_int_2float
  glUniform2f           = NULL,
  glVertexAttrib2f      = NULL;
  
glFunc_int_3float
  glUniform3f           = NULL,
  glVertexAttrib3f      = NULL;
  
glFunc_int_4float
  glUniform4f           = NULL,
  glVertexAttrib4f      = NULL;

glFunc_int_sizei_bool_floatp
  glUniformMatrix4fv    = NULL;

glFunc_uint_sizei_charpp_intp
  glShaderSource        = NULL;

glFunc_uint_charp_r_int
  glGetUniformLocation  = NULL,
  glGetAttribLocation   = NULL;
  
glFunc_sizei_uintp
  glGenBuffers          = NULL,
  glDeleteBuffers       = NULL;

glFunc_enum_r_bool
  glUnmapBuffer         = NULL;

glFunc_enum_r_uint
  glCreateShader        = NULL;

glFunc_enum_uint
  glBindBuffer          = NULL;
  
glFunc_enum_enum_r_voidp
  glMapBuffer           = NULL;
  
glFunc_enum_sizeiptr_voidp_enum
  glBufferData          = NULL;
  
glFunc_enum_intptr_sizeiptr_voidp
  glBufferSubData       = NULL;
  
glFunc_void_r_uint
  glCreateProgram       = NULL;
  
glFunc_uint
  glLinkProgram         = NULL,
  glUseProgram          = NULL,
  glDeleteProgram       = NULL,
  glDeleteShader        = NULL,
  glCompileShader       = NULL,
  glEnableVertexAttribArray = NULL,
  glDisableVertexAttribArray = NULL;

glFunc_uint_int_enum_bool_sizei_voidp
  glVertexAttribPointer = NULL;
  
glFunc_uint_uint
  glAttachShader        = NULL,
  glDetachShader        = NULL;
  
glFunc_uint_sizei_sizeip_charp
  glGetShaderInfoLog    = NULL,
  glGetProgramInfoLog   = NULL;
  
glFunc_uint_r_bool  
  glIsShader    = NULL, 
  glIsProgram   = NULL;
  
glFunc_uint_enum_intp    
  glGetShaderiv   = NULL, 
  glGetProgramiv  = NULL;

#endif
void glxLoad(){
#ifdef USE_WINDOWS_GLX
  // buffers
  glBindBuffer      = (glFunc_enum_uint)SDL_GL_GetProcAddress("glBindBuffer");
  glBufferData      = (glFunc_enum_sizeiptr_voidp_enum)SDL_GL_GetProcAddress("glBufferData");
  glBufferSubData   = (glFunc_enum_intptr_sizeiptr_voidp)SDL_GL_GetProcAddress("glBufferSubData");
  glDeleteBuffers   = (glFunc_sizei_uintp)SDL_GL_GetProcAddress("glDeleteBuffers");
  glGenBuffers      = (glFunc_sizei_uintp)SDL_GL_GetProcAddress("glGenBuffers");
  glMapBuffer       = (glFunc_enum_enum_r_voidp)SDL_GL_GetProcAddress("glMapBuffer");
  glUnmapBuffer     = (glFunc_enum_r_bool)SDL_GL_GetProcAddress("glUnmapBuffer");
  glEnableVertexAttribArray = (glFunc_uint)SDL_GL_GetProcAddress("glEnableVertexAttribArray");
  glDisableVertexAttribArray = (glFunc_uint)SDL_GL_GetProcAddress("glDisableVertexAttribArray");
  glVertexAttribPointer = (glFunc_uint_int_enum_bool_sizei_voidp)SDL_GL_GetProcAddress("glVertexAttribPointer");
  
  // shaders
  glAttachShader    = (glFunc_uint_uint)SDL_GL_GetProcAddress("glAttachShader");
  glCompileShader   = (glFunc_uint)SDL_GL_GetProcAddress("glCompileShader");
  glCreateProgram   = (glFunc_void_r_uint)SDL_GL_GetProcAddress("glCreateProgram");
  glCreateShader    = (glFunc_enum_r_uint)SDL_GL_GetProcAddress("glCreateShader");
  glDeleteProgram   = (glFunc_uint)SDL_GL_GetProcAddress("glDeleteProgram");
  glDeleteShader    = (glFunc_uint)SDL_GL_GetProcAddress("glDeleteShader");
  glDetachShader    = (glFunc_uint_uint)SDL_GL_GetProcAddress("glDetachShader");
  glLinkProgram     = (glFunc_uint)SDL_GL_GetProcAddress("glLinkProgram");
  glUseProgram      = (glFunc_uint)SDL_GL_GetProcAddress("glUseProgram");
  glShaderSource    = (glFunc_uint_sizei_charpp_intp)SDL_GL_GetProcAddress("glShaderSource");
  
  glGetShaderInfoLog    = (glFunc_uint_sizei_sizeip_charp)SDL_GL_GetProcAddress("glGetShaderInfoLog");
  glGetProgramInfoLog   = (glFunc_uint_sizei_sizeip_charp)SDL_GL_GetProcAddress("glGetProgramInfoLog");
  glIsShader            = (glFunc_uint_r_bool)SDL_GL_GetProcAddress("glIsShader");
  glIsProgram           = (glFunc_uint_r_bool)SDL_GL_GetProcAddress("glIsProgram");
  glGetShaderiv         = (glFunc_uint_enum_intp)SDL_GL_GetProcAddress("glGetShaderiv");
  glGetProgramiv        = (glFunc_uint_enum_intp)SDL_GL_GetProcAddress("glGetProgramiv");
  
  // variables
  glGetAttribLocation    = (glFunc_uint_charp_r_int)SDL_GL_GetProcAddress("glGetAttribLocation");
  glGetUniformLocation   = (glFunc_uint_charp_r_int)SDL_GL_GetProcAddress("glGetUniformLocation");
  glVertexAttrib1f    = (glFunc_int_float)SDL_GL_GetProcAddress("glVertexAttrib1f");
  glVertexAttrib2f    = (glFunc_int_2float)SDL_GL_GetProcAddress("glVertexAttrib2f");
  glVertexAttrib3f    = (glFunc_int_3float)SDL_GL_GetProcAddress("glVertexAttrib3f");
  glVertexAttrib4f    = (glFunc_int_4float)SDL_GL_GetProcAddress("glVertexAttrib4f");
  glUniform1f    = (glFunc_int_float)SDL_GL_GetProcAddress("glUniform1f");
  glUniform2f    = (glFunc_int_2float)SDL_GL_GetProcAddress("glUniform2f");
  glUniform3f    = (glFunc_int_3float)SDL_GL_GetProcAddress("glUniform3f");
  glUniform4f    = (glFunc_int_4float)SDL_GL_GetProcAddress("glUniform4f");
  glUniformMatrix4fv = (glFunc_int_sizei_bool_floatp)SDL_GL_GetProcAddress("glUniformMatrix4fv");
  
  // other
  glBlendEquation = (glFunc_enum)SDL_GL_GetProcAddress("glBlendEquation");
#endif
}
