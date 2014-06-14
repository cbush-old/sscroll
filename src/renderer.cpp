#include "renderer.h"

Renderer::Renderer() {

  attach_shaders();
  program.link();
  extract_vars();
  
}

void Renderer::attach_shaders() {

  program.attach(Vertex_shader("ass/shader.glvs"));
  program.attach(Fragment_shader("ass/shader.glfs"));

}

void Renderer::extract_vars(){

  program.bind();
  vs_position = program.get_attrib("position");
  texcoord_in = program.get_attrib("texin");
  color       = program.get_uniform("color");
  modelview   = program.get_uniform("modelview");
  projection  = program.get_uniform("projection");
  program.unbind();

}
