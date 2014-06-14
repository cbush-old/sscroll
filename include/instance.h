#ifndef INSTANCE_H
#define INSTANCE_H

struct Physical;

#include "physical.h"

struct Instance {

  friend class Physical;

  protected:
    uint8_t active;
    vec3 sprite_draw_offset;

  public:
    vec3 pos, vel, dim;
    Physical const *master;
    Sprite_instance sprite;
  
  public:
    uint8_t tick; // internal tick
    int hp;
    float hit_radius;  
    
  public:
    Instance();
    
  public:
    virtual void update(const double&);
    virtual void commit();
    virtual void die();
    
  public:
    inline const uint8_t& is_active(){ return active; }
    inline const Sprite_instance& get_sprite(){ return sprite; }
 
};

#endif
