#include "oslayer.h"

#include <iostream>

// just a wrapper for SDL
oslayer::oslayer(){ 
  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,0);
  window = SDL_CreateWindow("",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1,1,SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
  glcon  = SDL_GL_CreateContext(window);
  glxLoad();
  
  glEnable(GL_BLEND);       
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glEnable(GL_DEPTH_TEST);  
  glDepthFunc(GL_LESS);
 
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  SDL_GL_SwapWindow(window);
}

oslayer::~oslayer(){
  SDL_GL_DeleteContext(glcon);
  SDL_DestroyWindow(window);
  SDL_Quit();
  
}

oslayer& oslayer::get(){
  static oslayer handle;
  return handle;
}

SDL_Window* oslayer::get_window(){ 
  return get().window;
}

void oslayer::resize(int w,int h){
  SDL_Window* window_ = get().window;
  SDL_SetWindowSize(window_,w,h);
  SDL_SetWindowPosition(window_,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  SDL_GL_SwapWindow(window_);
  glViewport(0,0,w,h);

}

void oslayer::swap(){
  SDL_GL_SwapWindow(get().window);
}
