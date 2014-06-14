#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

#include <iostream>
#include <cstdint>
#include <map>

#include "hub.h"

struct Input;

typedef void(*input_callback)(const Input&);

struct Input : Hub_connectable {
  protected:
    std::map<SDL_Keycode,std::pair<PORT,int8_t>> keys;
    
  protected:
    virtual void bind(SDL_Keycode,std::pair<PORT,int8_t>);

  public:
    inline char& operator[](PORT i) const { return (*hub)[i]; }
    
  public:
    virtual void handle(SDL_Event&);
    
  public:
    virtual int load_mapping(const char*);
    virtual void unbind(const int);
    virtual void unbind_all();

};

struct Keyboard : Input {
  public:
    Keyboard();

};

#endif
