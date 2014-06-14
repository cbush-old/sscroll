#include "vbo.h"

VBO::VBO(){ id = nullptr; }

VBO::VBO(std::vector<float> const& v){

  oslayer::get();
  id = std::shared_ptr<GLuint>(new GLuint, GL_buffer_deleter());
  
  glGenBuffers(1, id.get());
  glBindBuffer(GL_ARRAY_BUFFER, *id);
  glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(v.size()*sizeof(float)), (GLvoid*)v.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
 
}

void VBO::point(attribute const& attr, int const& offs) const {
  // don't use this before constructing a vbo with a vector
  glBindBuffer(GL_ARRAY_BUFFER, *id);
  glVertexAttribPointer((GLuint)attr,2,GL_FLOAT,GL_FALSE,0,(void*)offs); 
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  
}
