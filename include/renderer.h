#ifndef RENDERER_H
#define RENDERER_H

#include "vbo.h"
#include "shaderprogram.h"
#include "hub.h"

struct Renderer {

  protected:
    ShaderProgram program;
    uniform projection, modelview, color;
    attribute vs_position, texcoord_in;
    mat4 projection_matrix, modelview_matrix;
    
  protected:
    VBO vbo;

  protected:
    virtual void attach_shaders();
    virtual void extract_vars();
    
  public:
    Renderer();

};

#endif
