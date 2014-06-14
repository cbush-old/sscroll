#include "player_type.h"

#include "world.h"

Player_type::Player_type(){
  
  max_hp = 100;
  
}

#include <cstdlib>

void Player_type::update(Player_inst& I) const {

  static int i = 0;
  i++;
  
  static Spriteset b_spr ("ass/bullet1.png",SPRITE_16x16);
  static Bullet_type b_mast;
  
  if((*I.hub)[PLAYER_SHOOT_PORT]){
    
    static int8_t last_xd = 0;
    
    int8_t xd = (*I.hub)[PLAYER_X_PORT];
    int8_t yd = (*I.hub)[PLAYER_Y_PORT];
  
    if(xd) last_xd = xd;
    if(!xd&&yd) last_xd = 0;
    
    b_mast.spriteset = &b_spr;
    b_mast.max_hp = 5;
    b_mast.checks_walls = 1;
    b_mast.gravitates = 1;
    
    float power = 16.0f;
    double random = (double)rand()*0.000000003d;
    random -= random/2.0f;
    Bullet_inst bullet (&b_mast);
    bullet.sprite = Sprite_instance(&b_spr);
    bullet.hit_radius = 128.0f;
    bullet.pos = I.pos - vec3(0.0f,0.0f,0.0f);
    bullet.vel = vec3(last_xd * power + random, yd * power + random, 0.0f);

    
    world.push(bullet);

  }
  
  
}
