#ifndef POWERUP_TYPE_H
#define POWERUP_TYPE_H

#include "powerup_inst.h"

struct Powerup_type : Physical {

  friend class Powerup_inst;
  
  private:
    void update(Powerup_inst&) const;
  
  public:
    // Powerup_type();
    
};

#endif
