#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "shader.h"

struct ShaderProgram : GL_object {  

  public:
    ShaderProgram();
    
  public:
    void print_log() const;
  
  public:
    void attach(Shader const&) const;
    void detach(Shader const&) const;
    bool link() const;
    int  bind() const;
    void enable(attribute const&) const;
    void disable(attribute const&) const;
    void unbind() const;
    
  public:
    uniform get_uniform(const char*) const;
    attribute get_attrib(const char*) const;
    void set(uniform&, float const&) const;
    void set(uniform&, float const&, float const&) const;
    void set(uniform&, float const&, float const&, float const&) const;
    void set(uniform&, float const&, float const&, float const&, float const&) const;
    void set(attribute&, float const&) const;
    void set(attribute&, float const&, float const&) const;
    void set(attribute&, float const&, float const&, float const&) const;
    void set(attribute&, float const&, float const&, float const&, float const&) const;
    void set_matrix(uniform&, GLsizei const&, GLboolean const&, GLfloat const *) const;
  
};

#endif
