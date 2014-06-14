#ifndef HUB_H
#define HUB_H

#include <vector>
#include "glmath.h"

enum PORT {
  NO_PORT,
  PLAYER_X_PORT,
  PLAYER_Y_PORT,
  PLAYER_Z_PORT,
  PLAYER_JUMP_PORT,
  PLAYER_SHOOT_PORT,
  PLAYER_WHIP_PORT,
  PLAYER_RUN_PORT,
  CAM_X_PORT,
  CAM_Y_PORT,
  CAM_Z_PORT,
  CAM_XR_PORT,
  CAM_YR_PORT,
  CAM_ZR_PORT,
  CAM_FOLLOW_PORT,
  N_PORTS
};

template<typename T> struct Input_hub {
  private:
    std::vector<T> port;

  public:
    Input_hub();
    ~Input_hub();
  
  public:
    T& operator[](PORT i){  return port[i];   }
    T& operator[](PORT i) const {  return port[i];   }
    vec3 vecmsg;

};

template<typename T> Input_hub<T>::Input_hub(){   port.resize(N_PORTS);   }
template<typename T> Input_hub<T>::~Input_hub(){  port.clear();   }

using Hub = Input_hub<char>;

#include "hub_connectable.h"

#endif
