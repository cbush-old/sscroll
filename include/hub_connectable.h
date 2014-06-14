#ifndef HUB_CONNECTABLE_H
#define HUB_CONNECTABLE_H

#include "hub.h"

struct Hub_connectable {
  protected:
    Hub  deadhub;
    Hub* hub;

  public:
    Hub_connectable():hub(&deadhub){}
    inline void connect(Hub * const);
    inline void disconnect();

};

void Hub_connectable::connect(Hub * const h){ 
  hub = h; 
}

void Hub_connectable::disconnect(){ 
  hub = &deadhub; 
}


#endif
