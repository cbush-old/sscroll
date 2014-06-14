#ifndef STATUS_EFFECT_H
#define STATUS_EFFECT_H

#include <cstdint>

enum status_effect_type {
  POISONED=0x1,  PETRIFIED=0x2,  FROZEN=0x4,  BURNING=0x8,
  CONFUSED=0x10,  INVINCIBLE=0x20,  INVISIBLE=0x40,  SHRUNKEN=0x80,
  GIGANTIC=0x100,  BLIND=0x200
};

typedef uint16_t status_effect_mask;

struct Status_effect {
  public:
    // health effect types
    uint8_t poisoned, petrified, frozen, burning,
      confused, invincible, invisible, shrunken,
      gigantic, blind;
    
  public:
    Status_effect():
      poisoned(0), petrified(0), frozen(0), burning(0),
      confused(0), invincible(0), invisible(0), shrunken(0),
      gigantic(0), blind(0){}

    Status_effect(int,int);
    
  public:
    Status_effect& operator= (const Status_effect&);
    Status_effect  operator+ (const Status_effect&) const;
    Status_effect  operator- (const Status_effect&) const;
    Status_effect& operator+=(const Status_effect&);
    Status_effect& operator-=(const Status_effect&);
    
};

typedef Status_effect S_effect;

#endif
