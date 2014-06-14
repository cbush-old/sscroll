#ifndef SHADER_H
#define SHADER_H

#include "gl_object.h"

struct ShaderProgram;

struct Shader : GL_object {

  friend class ShaderProgram;
 
  public:
    Shader();
    Shader(const char*);
    virtual ~Shader()=0;
    
  public:
    void print_log() const;
    
  public:
    void load(const char*);
    bool compile() const;
    
};

struct Fragment_shader : Shader { Fragment_shader(); Fragment_shader(const char*); };
struct Geometry_shader : Shader { Geometry_shader(); Geometry_shader(const char*); };
struct Tess_control_shader : Shader { Tess_control_shader(); Tess_control_shader(const char*); };
struct Tess_evaluation_shader : Shader { Tess_evaluation_shader(); Tess_evaluation_shader(const char*); };
struct Vertex_shader : Shader { Vertex_shader(); Vertex_shader(const char*); };

#endif

