#ifndef BULLET_INST_H
#define BULLET_INST_H

#include "instance.h"

struct Bullet_inst;
struct Bullet_type;

#include "bullet_type.h"

struct Bullet_inst : Instance {

  friend class Bullet_type;

  private:
    Bullet_type* master;
  
  public:
    Bullet_inst(Bullet_type*);

  public:
    // void update(const double&);
    
};

#endif
