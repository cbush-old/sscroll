#ifndef SPRITESET_H
#define SPRITESET_H

#include "oslayer.h"

#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <vector>
#include <memory>

enum SPRITE_MODE {
  SPRITE_8x8,
  SPRITE_16x16,
  SPRITE_32x32,
  SPRITE_32x48,
  SPRITE_48x16,
  SPRITE_64x64,
  SPRITE_128x128,
  SPRITE_128x256,
  SPRITE_256x256,
  SPRITE_256x512,
  SPRITE_512x512,
  N_SPRITE_MODES
};

class Spriteset {
  private:
    int error;
    
  public:
    SPRITE_MODE mode;
    std::shared_ptr<std::vector<GLuint>> ids;
    unsigned rows, cols; // number of sprites down, across
    unsigned w, h; // size of each sprite
    
  public:
    Spriteset();
    Spriteset(const char*, SPRITE_MODE const&, GLenum const& texparam=GL_NEAREST);

  private:
    void set_wh();
    int load(const char*, GLenum const& texparam=GL_NEAREST);

  public:
    int load(const char*, SPRITE_MODE const&, GLenum const& texparam=GL_NEAREST);
    const GLuint operator[](uint32_t const&) const;
   
};

#endif

