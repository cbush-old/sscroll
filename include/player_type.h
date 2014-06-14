#ifndef PLAYER_TYPE_H
#define PLAYER_TYPE_H

#include "player_inst.h"

struct Player_type : Physical {

  friend class Player_inst;
  
  private:
    void update(Player_inst&) const;
  
  public:
    int cooldown;
  
  public:
    Player_type();
    
};

#endif
