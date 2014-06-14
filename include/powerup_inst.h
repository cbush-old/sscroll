#ifndef POWERUP_INST_H
#define POWERUP_INST_H


struct Powerup_inst;
struct Powerup_type;

#include "instance.h"
#include "powerup_type.h"

struct Powerup_inst : Instance {

  friend class Powerup_type;
  
  public:
    Powerup_inst(Powerup_type*);

  public:
    // void update();
    
};

#endif
