#ifndef DEBRIS_TYPE_H
#define DEBRIS_TYPE_H

#include "debris_inst.h"

struct Debris_inst;

struct Debris_type : Physical {
  
  friend class Debris_inst;
  
  private:
    void update(Debris_inst&) const;
  
  public:
    // Debris_type();

};

#endif
