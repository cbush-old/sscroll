#include "world.h"

World::World(){

  bad_bullets.reserve(10000);
  bullets.reserve(10000);
  debris.reserve(10000);
  enemies.reserve(1000);
  players.reserve(5);
  powerups.reserve(1000);

}

void World::update(const double& dt){

  update<Bad_bullet_inst>(bad_bullets,dt);
  update<Bullet_inst>(bullets,dt);
  update<Debris_inst>(debris,dt);
  update<Enemy_inst>(enemies,dt);
  update<Player_inst>(players,dt);
  update<Powerup_inst>(powerups,dt);
  
  commit<Bad_bullet_inst>(bad_bullets);
  commit<Bullet_inst>(bullets);
  commit<Debris_inst>(debris);
  commit<Enemy_inst>(enemies);
  commit<Player_inst>(players);
  commit<Powerup_inst>(powerups);
  
}

int World::resolve_walls(Instance& I) const {
  
  vec3 next = I.pos + I.vel + I.dim;
  vec3 max = vec3(32000.f,128.0f - 56.0f, 32.0f);
  if(next.x >= max.x) I.vel.x -= next.x - max.x;
  if(next.y >= max.y) I.vel.y -= next.y - max.y;
  if(next.z >= max.z) I.vel.z -= next.z - max.z;
  // if(next.x <= 0.0f) I.vel.x -= next.x;
  // if(next.y <= 0.0f) I.vel.y -= next.y;
  // if(next.z <= 0.0f) I.vel.z -= next.z;
  
  return 1;
  
}

void World::draw_walls() const {
  
  static Spriteset set("ass/tiles.png",SPRITE_64x64);
  static Sprite_instance inst(&set);

  for(int i=-1000*32; i < 1000*32; i+=64){
    inst.pos = vec3((float)i,128.0f,3.0f);
    bool sees;
    if(!(sees = camera.sees(inst))) continue;
    camera.draw(inst);
  
  }  
  
  // background
  for(int i=-1000*32; i < 1000*32; i+=64){
    inst.pos = vec3((float)i,128.0f+sin(i/10)*32.0f,3.51f+cos(i/10)/2.0f);
    bool sees;
    if(!(sees = camera.sees(inst))) continue;
    camera.draw(inst);
  
  }
  
  // foreground
  for(int i=-1000*32; i < 1000*32; i+=64){
    inst.pos = vec3((float)i,128.0f+cos(float(i)/100.0f)*32.0f,2.49f+sin(i/10)/2.0f);
    bool sees;
    if(!(sees = camera.sees(inst))) continue;
    camera.draw(inst);
  
  }
  
}

