#ifndef ENEMY_INST_H
#define ENEMY_INST_H

#include "instance.h"

struct Enemy_inst;
struct Enemy_type;

#include "enemy_type.h"

struct Enemy_inst : Instance {

  friend class Enemy_type;
  
  public:
    Enemy_inst(Enemy_type*);

  public:
    // void update();

    
};

#endif
