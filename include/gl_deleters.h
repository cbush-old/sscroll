#ifndef GL_DELETERS_H
#define GL_DELETERS_H

#include "oslayer.h"
#include <vector>

struct GL_buffer_deleter {
  inline void operator()(GLuint *id) const {
    glDeleteBuffers(1, id); 
    delete id; 
  }
};

struct GL_program_deleter {
  inline void operator()(GLuint *id) const {
    glDeleteProgram(*id); 
    delete id; 
  }
};

struct GL_shader_deleter {
  inline void operator()(GLuint *id) const {
    glDeleteShader(*id); 
    delete id; 
  }
};

struct GL_textures_deleter {
  inline void operator()(std::vector<GLuint>* v) const {
    glDeleteTextures(v->size(),v->data());
    delete v;
  }
};

#endif
