#include "instance.h"
#include "world.h"

extern uint8_t global_rate;
extern Camera camera;

Instance::Instance():active(1),sprite_draw_offset(vec3()){}

void Instance::update(const double& dt){
  
  vel.y += gravity*dt;
  world.resolve_walls(*this);
  
}

void Instance::commit(){  
  pos += vel;
  sprite.pos = pos + sprite_draw_offset; 
  // sprite.rotation+=45.0f;
}

void Instance::die(){
  active = 0;
}
