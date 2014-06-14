#ifndef DEBRIS_INST_H
#define DEBRIS_INST_H

#include "instance.h"

struct Debris_inst;
struct Debris_type;

#include "debris_type.h"

struct Debris_inst : Instance {

  friend class Debris_type;
  
  private:
    Debris_type *master;
  
  public:
    Debris_inst(Debris_type*);

  public:
    // void update();

};

#endif
