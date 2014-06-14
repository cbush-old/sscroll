#ifndef BAD_BULLET_TYPE_H
#define BAD_BULLET_TYPE_H

#include "bad_bullet_inst.h"

struct Bad_bullet_type : Physical {
  
  friend class Bad_bullet_inst;
  
  private:
    void update(Bad_bullet_inst&) const;
  
  public:
    // Bad_bullet_type();

};

#endif
