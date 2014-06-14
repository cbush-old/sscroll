#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

using std::string;
using std::vector;

enum PHYSICAL_TYPE {
  BAD_BULLETS,
  BULLETS,
  DEBRIS,
  ENEMIES,
  PHYSICALS,
  PLAYERS,
  POWERUPS,
  N_PHYSICAL_TYPES
};

struct Instance;
extern float gravity;

#include "damage.h"
#include "status_effect.h"
#include "sprite_instance.h"

struct Physical {
  
  friend class Instance;
  
  protected:
    virtual void update(Instance&) const;
    
  public:
    unsigned max_hp;
    vector<PHYSICAL_TYPE> collide_checks;
    
    uint8_t gravitates, checks_walls, attacks, moves;      
    Damage damage, defense;
    S_effect effect, protect;
    
    float repulsion;
 
  public:
    Spriteset* spriteset;
    string name;
    
  public:
    Physical();
    

    
};


#endif
