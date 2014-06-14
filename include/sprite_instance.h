#ifndef SPRITE_INSTANCE_H
#define SPRITE_INSTANCE_H

#include "spriteset.h"
#include "glmath.h"

class Sprite_instance {
  private:
    int _row, _frame;
    
  public:
    Spriteset* set;
    int w, h;
    bool flip_x, flip_y;
    vec3 pos, scale;
    float rotation;
    
  public:
    Sprite_instance();
    Sprite_instance(Spriteset*);
    
  public:
    const GLuint get() const;
    unsigned frame() const;
    void frame(unsigned);
    void advance_frame();
    void advance_frame(int);
    unsigned row() const;
    void row(unsigned);
    void advance_row();
    void advance_row(int);
    
};

#endif

