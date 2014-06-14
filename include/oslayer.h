#ifndef OSLAYER_H
#define OSLAYER_H

#include "windows_glx.h"

struct oslayer {
  private:
    oslayer();
    ~oslayer();
  
  private:
    SDL_GLContext glcon;
    SDL_Window *window;
  
  public:
    inline static void delay(unsigned const&);
    static oslayer& get();
    static SDL_Window* get_window();
    static void swap();
    static void resize(int,int);

};

void oslayer::delay(unsigned const& t){ SDL_Delay(t); }

#endif
