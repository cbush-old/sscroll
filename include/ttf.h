#ifndef TTF_H
#define TTF_H

#include <iostream>
#include <cstdint>
#include <vector>
#include <stdexcept>
#include <memory>

#include <SDL.h>
#include "SDL_ttf_lite.h"

struct TTF {
  private:
    std::shared_ptr<TTF_Font*> font;
    std::shared_ptr<SDL_RWops*> font_rw;
    
  public:      
    unsigned w, h, *pixels;

  public:
    TTF();
    TTF(const char*);
    TTF(const char*,int const&);
  
  public:
    void open(const char*);
    void open(const char*,int const&);
    void resize(int const&);
    TTF_Glyph* render(const uint16_t&) const;
    void free(TTF_Glyph*) const;

};

#endif

