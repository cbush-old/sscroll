#include "shader.h"

#include <iostream>
#include <fstream>
#include <cstring>

inline std::string file_get_contents(const char* name){

  std::ifstream file (name);
  if(!file.good()) return NULL;
  int length = file.seekg(0,file.end).tellg();
  file.seekg(0,file.beg);
  
  if(++length < 1){
    file.close();
    return NULL;
  }
  
  std::string contents;
  getline(file,contents,'\0');
  file.close();
  return contents;

}

Shader::Shader(){ 
  oslayer::get(); 
}

Shader::Shader(const char* s){
  oslayer::get(); 
  load(s);
}

Shader::~Shader(){}

Fragment_shader::Fragment_shader(){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_FRAGMENT_SHADER)),GL_shader_deleter()); }
Geometry_shader::Geometry_shader(){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_GEOMETRY_SHADER)),GL_shader_deleter()); }
Tess_control_shader::Tess_control_shader(){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_TESS_CONTROL_SHADER)),GL_shader_deleter()); }
Tess_evaluation_shader::Tess_evaluation_shader(){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_TESS_EVALUATION_SHADER)),GL_shader_deleter()); }
Vertex_shader::Vertex_shader(){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_VERTEX_SHADER)),GL_shader_deleter()); }

Fragment_shader::Fragment_shader(const char* s){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_FRAGMENT_SHADER)),GL_shader_deleter()); load(s); }
Geometry_shader::Geometry_shader(const char* s){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_GEOMETRY_SHADER)),GL_shader_deleter()); load(s); }
Tess_control_shader::Tess_control_shader(const char* s){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_TESS_CONTROL_SHADER)),GL_shader_deleter()); load(s); }
Tess_evaluation_shader::Tess_evaluation_shader(const char* s){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_TESS_EVALUATION_SHADER)),GL_shader_deleter()); load(s); }
Vertex_shader::Vertex_shader(const char* s){ id=std::shared_ptr<GLuint>(new GLuint(glCreateShader(GL_VERTEX_SHADER)),GL_shader_deleter()); load(s); }


void Shader::load(const char* filename){

  std::string file = file_get_contents(filename);
  
  char const * source[1] { file.c_str() };
  
  if(!source[0]){
    std::cout << "Couldn't load shader " << file << '\n';
    return;
  }
  
  glShaderSource(*id, 1, source, NULL);
  
}

bool Shader::compile() const {

  glCompileShader(*id);
  
  GLint compiled = GL_FALSE;
  glGetShaderiv(*id,GL_COMPILE_STATUS,&compiled);
  
  if(compiled!=GL_TRUE){
    std::cout << "Couldn't compile shader #" << *id << "!\n";
    print_log();
    return 0;
  }
  return 1;
  
}

void Shader::print_log() const {

  if(!glIsShader(*id)){
    std::cout << "Name " << *id << " is not a shader\n";
    return;
  }
  
  int log_length, max_length;
  glGetShaderiv(*id,GL_INFO_LOG_LENGTH,&max_length);
  
  char* log = new char[max_length];
  
  glGetShaderInfoLog(*id, max_length, &log_length, log);
  
  if(log_length > 0) std::cout << log << '\n';
  
  delete[] log;

}

