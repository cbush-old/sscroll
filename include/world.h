#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>

using std::vector;

#include "cam.h"

#include "wall.h"
#include "bad_bullet_type.h"
#include "bullet_type.h"
#include "debris_type.h"
#include "enemy_type.h"
#include "player_type.h"
#include "powerup_type.h"

extern Camera camera;

struct World {
  private:
    vector<Wall>            walls;
    vector<Player_inst>     players;      // PLAYERS // the player(s)
    vector<Bullet_inst>     bullets;      // BULLETS // the players' bullets
    vector<Bad_bullet_inst> bad_bullets;  // BAD_BULLETS // enemy bullets, react to the player(s)
    vector<Enemy_inst>      enemies;      // ENEMIES // only the players' bullets will look here
    vector<Powerup_inst>    powerups;     // POWERUPS // either bullet group will react to them, and they look for players
    vector<Debris_inst>     debris;       // DEBRIS // particles and effects that probably don't react to anything
  
  private:
    template<class T> inline vector<T>& get_vector();
    template<class T> inline void update(vector<T>&,const double&);
    template<class T> inline void commit(vector<T>&);
    
  public:
    World();
    
  public:
    void update(const double&);
    int resolve_walls(Instance&) const;
    void draw_walls() const;

  public:
    template<class T> void push(T);
    template<class T> T* collide(const Instance&); 
 
};

template<> inline vector<Bad_bullet_inst>& World::get_vector<Bad_bullet_inst>() { return bad_bullets; }
template<> inline vector<Bullet_inst>& World::get_vector<Bullet_inst>() { return bullets; }
template<> inline vector<Debris_inst>& World::get_vector<Debris_inst>() { return debris; }
template<> inline vector<Enemy_inst>& World::get_vector<Enemy_inst>() { return enemies; }
template<> inline vector<Player_inst>& World::get_vector<Player_inst>() { return players; }
template<> inline vector<Powerup_inst>& World::get_vector<Powerup_inst>() { return powerups; }

template<class T> void World::push(T instance){
  get_vector<T>().push_back(instance);

}

template<class T> T* World::collide(const Instance& B){

  vector<T>& v = get_vector<T>();
  
  size_t n = v.size();
  vec3 next_B = B.pos + B.vel;
  
  for(size_t i=0; i < n; ++i){
  
    T *A = &v[i];
    vec3 next_A = A->pos + A->vel;
    vec3 diff = next_B - next_A;
    
    if((diff.x*diff.x + diff.y*diff.y + diff.z*diff.z) <= (A->hit_radius + B.hit_radius)) return A;

  }
  
  return nullptr;

}

template<class T> void World::update(vector<T>& group, const double& ts){ 
  for(auto& i : group) 
    i.update(ts); 

}

template<class T> void World::commit(vector<T>& group){
  for(auto i=group.begin(); i!=group.end(); ){
    if(!i->is_active())
      i = group.erase(i);
    else {
      i->commit();
      const Sprite_instance& spr = i->get_sprite();
      if(camera.sees(spr)) camera.draw(spr);  
      i++;
    }
  }
}
 
extern World world;

#endif
