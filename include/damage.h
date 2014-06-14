#ifndef DAMAGE_H
#define DAMAGE_H

#include <cstdint>
// implements a matrix-like damage struct
enum damage_type {
  BLUNT=0x1,        BLADE=0x2,      PIERCE=0x4,   STING=0x8,
  CRUSH=0x10,       FIRE=0x20,      ICE=0x40,     ELECTRICAL=0x80,
  BIOHAZARD=0x100,  ACID=0x200,     PSI=0x400,    WOODEN=0x800,
  SILVER=0x1000,    RADIATION=0x2000
};

typedef uint16_t damage_type_mask;

struct Damage {
  public:
    // damage types
    uint8_t blunt, blade, pierce, sting,
      crush, fire, ice, electrical,
      biohazard, acid, psi, wooden,
      silver, radiation;
    
  public:
    Damage():
      blunt(0), blade(0), pierce(0), sting(0), 
      crush(0), fire(0), ice(0), electrical(0), 
      biohazard(0), acid(0), psi(0), wooden(0), 
      silver(0), radiation(0){}

    Damage(damage_type_mask,uint8_t);
    
  public:
    Damage& operator= (const Damage&);
    Damage  operator+ (const Damage&) const;
    Damage  operator- (const Damage&) const;
    Damage& operator+= (const Damage&);
    Damage& operator-= (const Damage&);
    operator int();
    
    
};

#endif
