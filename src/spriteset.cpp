#include "spriteset.h"

#include "png_file.h"
#include "gl_object.h"

#include <cstring>

const GLuint Spriteset::operator[](uint32_t const& i) const {

  return ids->at(i);

}

void Spriteset::set_wh(){

  switch(mode){
    case SPRITE_8x8: w = h = 8; break;
    case SPRITE_16x16: w = h = 16; break;
    case SPRITE_32x32: w = h = 32; break;
    case SPRITE_64x64: w = h = 64; break;
    case SPRITE_128x128: w = h = 128; break;
    case SPRITE_256x256: w = h = 256; break;
    case SPRITE_512x512: w = h = 512; break;
    case SPRITE_32x48: w = 32; h = 48; break;
    case SPRITE_48x16: w = 48; h = 16; break;
    case SPRITE_128x256: w = 128; h = 256; break;
    case SPRITE_256x512: w = 256; h = 512; break;
    default: throw std::runtime_error("Invalid spriteset mode!");
  }

}

Spriteset::Spriteset(const char* file, SPRITE_MODE const& mode_, GLenum const& param):mode(mode_){

  set_wh();
  load(file, param);

}

int Spriteset::load(const char* file, SPRITE_MODE const& mode_, GLenum const& param){

  mode = mode_;
  set_wh();
  load(file, param);

}

int Spriteset::load(const char* file, GLenum const& param){

  oslayer::get(); 
 
  PNG source = PNG(file);
  
  cols = source.w/w;
  rows = source.h/h;
  
  std::vector<uint32_t> pixels (w*h,0);
  
  ids = std::shared_ptr<std::vector<GLuint>>(new std::vector<GLuint>(rows*cols,0), GL_textures_deleter());
  glGenTextures(rows*cols, ids->data());
  
  if(glGetError()) throw std::runtime_error("Call to glGenTextures() failed in loading Spriteset.");
  
  for(int i = 0; i < rows*cols; ++i){
    for(int y = 0; y < h; ++y){
      for(int x = 0; x < w; ++x){
        pixels[y*w+x] = source[i*w+(y*cols*w+x)];
      }
    }
    glBindTexture(GL_TEXTURE_2D, ids->at(i));
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, pixels.data());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,param);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,param);
  
  }

}
