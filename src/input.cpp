#include "input.h"
#include <string>
#include <fstream>
#include <sstream>

using std::string;
using std::stringstream;
using std::getline;
using cmd_pair = std::pair<PORT,int8_t>;
using char_cmd = std::pair<string,cmd_pair>;

void Input::unbind_all(){
  keys.clear();
}

void Input::unbind(const int key){
  keys[key] = cmd_pair(NO_PORT,0);
}

void Input::bind(SDL_Keycode k, cmd_pair p){
  keys[k] = p;  
}

int Input::load_mapping(const char* filename){

  // loads key mapping from file - \n line breaks -
  // text editors that use \r\n must add a space 
  // before newlines for the format to work
  
  std::ifstream file(filename);
  if(!file.good()) return 1;

  #include "key_lookup.cc"
  #include "cmd_lookup.cc"
  
  bool key_toggle = 0;
  string line;
  string cmd_str, key_str, token;
  while(getline(file,line)){  
    stringstream sline (line);
    while(getline(sline,token,' ')){
      if(!key_toggle){
    
        if(!cmd_lookup.count(token)) continue;       
        key_toggle = !key_toggle;
        cmd_str = token;
        
      } else {
      
        key_toggle = !key_toggle;
        if(!key_lookup.count(token)) continue;
          
        bind(
          key_lookup.find(token)->second, 
          cmd_lookup.find(cmd_str)->second
        );
        
      }
    }
  }
  
  return 0;
  
}

void Input::handle(SDL_Event& e){

  SDL_Keycode key;
  cmd_pair val;
  
  while(SDL_PollEvent(&e)){
    switch(e.type){
      case SDL_KEYUP:
        key = e.key.keysym.sym;
        val = keys[key];
        if((*hub)[val.first]==val.second) (*hub)[val.first] = 0;
        break;
      case SDL_KEYDOWN:
        key = e.key.keysym.sym;
        if(key==SDLK_ESCAPE){  
          e.type = SDL_QUIT;
          return;
        } else {
          val = keys[key];
          (*hub)[val.first] = val.second;
        }
        break;
    }
  }
  
}

Keyboard::Keyboard(){}
