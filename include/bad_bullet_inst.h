#ifndef BAD_BULLET_INST_H
#define BAD_BULLET_INST_H

#include "instance.h"

struct Bad_bullet_inst;
struct Bad_bullet_type;

#include "bad_bullet_type.h"

struct Bad_bullet_inst : Instance {

  friend class Bad_bullet_type;
  
  public:
    Bad_bullet_inst(Bad_bullet_type*);

  public:
    // void update();
    
};

#endif
