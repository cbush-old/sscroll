#ifndef ENEMY_TYPE_H
#define ENEMY_TYPE_H

#include "enemy_inst.h"

struct Enemy_type : Physical {
  
  friend class Enemy_inst;
  
  private:
    void update(Enemy_inst&) const;
  
  public:
    // Enemy_type();

};

#endif
