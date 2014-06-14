#include "player_inst.h"

#include "world.h"

Player_inst::Player_inst(Player_type* _master){

  hub = &deadhub;
  master = _master;
  active = 1;
  hp     = master->max_hp;
  sprite = Sprite_instance(master->spriteset);
  pos = vec3(1.0f,1.0f,-1.0f);
  vel = vec3(0.0f);
  sprite_draw_offset = vec3(0.0f,0.0f,0.0f);
  hit_radius = 128.0f;

}

void Player_inst::update(const double& dt){
  
  if(!active) return;

  int8_t xv = (*hub)[PLAYER_X_PORT];
  int8_t yv = (*hub)[PLAYER_JUMP_PORT]?-1:0;
  
  if(xv) last_xv = xv;
  
  float speed = ((*hub)[PLAYER_RUN_PORT]+1.0f)*6.0f;
  vel.x = xv * speed * dt;
  
  sprite.flip_y = last_xv < 0;
  
  if(!onground){
  
    sprite.frame(6);
    
  } else {
    
    vel.y += yv * gravity * 16.0f;
    
    if(xv&&((i+=dt)>=3.0f)){
      i = 0.0f;
      sprite.advance_frame();
      if(sprite.frame()==0) sprite.advance_frame();
    } else if(!xv) sprite.frame(0);
  
  }
  
  
  // Bullet_inst* b = world.collide<Bullet_inst>(*this);
  // if(b) b->die();
 
  vel.y += gravity*dt;
  float tmp = vel.y;
  world.resolve_walls(*this);
  
  onground = (vel.y != tmp);
  
  master->update(*this);

  hub->vecmsg = pos + vel;

}
