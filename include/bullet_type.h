#ifndef BULLET_TYPE_H
#define BULLET_TYPE_H

#include "bullet_inst.h"

struct Bullet_type : Physical {
  
  friend class Bullet_inst;
  
  private:
    void update(Bullet_inst&) const;
  
  public:
    // Bullet_type();

};

#endif
