#include "shaderprogram.h"

#include <iostream>

ShaderProgram::ShaderProgram(){ 

  oslayer::get();
  id = std::shared_ptr<GLuint>(new GLuint(glCreateProgram()), GL_program_deleter());
  
}

int ShaderProgram::bind() const {

  glUseProgram(*id);

  GLenum error = glGetError();
  if(error != GL_NO_ERROR){
    std::cout << "Error binding shader program: " << error << "\n";
    print_log();
    return 0;
  }
  return 1;
  
}

void ShaderProgram::unbind() const {  
  glUseProgram(0);
}

void ShaderProgram::attach(Shader const& s) const {
  s.compile();
  glAttachShader(*id, *s.id);
}

void ShaderProgram::detach(Shader const& s) const {
  glDetachShader(*id, *s.id);
}

bool ShaderProgram::link() const {

  glLinkProgram(*id);
  
  int success = GL_FALSE;
  glGetProgramiv(*id, GL_LINK_STATUS, &success); 
  if(success != GL_TRUE){ 
    std::cout << "Error linking program #" << *id << "\n";
    print_log();
    return false; 
  }
  return true;

}

void ShaderProgram::enable(attribute const& attr) const {
 
  glEnableVertexAttribArray(attr);
  
}

void ShaderProgram::disable(attribute const& attr) const {
 
  glDisableVertexAttribArray(attr); 
  
}

void ShaderProgram::print_log() const {

  if(!glIsProgram(*id)){
    std::cout << "Name " << *id << " is not a program\n";
    return;
  }
  
  int log_length, max_length;
  glGetProgramiv(*id,GL_INFO_LOG_LENGTH,&max_length);
  char* log = new char[max_length];
  glGetProgramInfoLog(*id, max_length, &log_length, log);
  if(log_length > 0) std::cout << log << '\n';
  delete[] log;
  
}

uniform ShaderProgram::get_uniform(const char* s) const {  return uniform(glGetUniformLocation(*id,s));   }
attribute ShaderProgram::get_attrib(const char* s) const {  return attribute(glGetAttribLocation(*id,s));   }
void ShaderProgram::set(uniform& var, float const& arg1) const {   glUniform1f((GLint)var,arg1);    }
void ShaderProgram::set(uniform& var, float const& arg1, float const& arg2) const {   glUniform2f((GLint)var,arg1,arg2);    }
void ShaderProgram::set(uniform& var, float const& arg1, float const& arg2, float const& arg3) const {   glUniform3f((GLint)var,arg1,arg2,arg3);    }
void ShaderProgram::set(uniform& var, float const& arg1, float const& arg2, float const& arg3, float const& arg4) const {   glUniform4f((GLint)var,arg1,arg2,arg3,arg4);    }
void ShaderProgram::set(attribute& var, float const& arg1) const {   glVertexAttrib1f((GLint)var,arg1);    }
void ShaderProgram::set(attribute& var, float const& arg1, float const& arg2) const {   glVertexAttrib2f((GLint)var,arg1,arg2);    }
void ShaderProgram::set(attribute& var, float const& arg1, float const& arg2, float const& arg3) const {   glVertexAttrib3f((GLint)var,arg1,arg2,arg3);    }
void ShaderProgram::set(attribute& var, float const& arg1, float const& arg2, float const& arg3, float const& arg4) const {   glVertexAttrib4f((GLint)var,arg1,arg2,arg3,arg4);    }
void ShaderProgram::set_matrix(uniform& location, GLsizei const& count, GLboolean const& transpose, const GLfloat* value) const {   
  glUniformMatrix4fv((GLint)location,count,transpose,value);    
}

