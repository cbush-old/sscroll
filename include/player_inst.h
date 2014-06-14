#ifndef PLAYER_INST_H
#define PLAYER_INST_H

#include "instance.h"

struct Player_inst;
struct Player_type;

#include "player_type.h"
#include "hub.h"

struct Player_inst : Instance, Hub_connectable {

  friend class Player_type;
  
  private:
    Player_type *master;

  private:
    int8_t last_xv;
    bool onground;
    int i;
    
  public:
    Player_inst(Player_type*);
    
  public:
    void update(const double&);

};

#endif
