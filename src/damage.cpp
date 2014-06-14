#include "damage.h"

Damage::Damage(damage_type_mask type, uint8_t value){
  blunt       = type&BLUNT?     value:0;
  blade       = type&BLADE?     value:0;
  pierce      = type&PIERCE?    value:0;
  sting       = type&STING?     value:0;
  crush       = type&CRUSH?     value:0;
  fire        = type&FIRE?      value:0;
  ice         = type&ICE?       value:0;
  electrical  = type&ELECTRICAL? value:0;
  biohazard   = type&BIOHAZARD? value:0;
  acid        = type&ACID?      value:0;
  psi         = type&PSI?       value:0;
  wooden      = type&WOODEN?    value:0;
  silver      = type&SILVER?    value:0;
  radiation   = type&RADIATION? value:0;
  
}

Damage& Damage::operator= (const Damage& d2){
  blunt       = d2.blunt;
  blade       = d2.blade;
  pierce      = d2.pierce;
  sting       = d2.sting;
  crush       = d2.crush;
  fire        = d2.fire;
  ice         = d2.ice;
  electrical  = d2.electrical;
  biohazard   = d2.biohazard;
  acid        = d2.acid;
  psi         = d2.psi;
  wooden      = d2.wooden;
  silver      = d2.silver;
  radiation   = d2.radiation;
  return *this;
  
}

Damage Damage::operator+ (const Damage& d2) const {
  Damage r(*this);
  r.blunt       += d2.blunt;
  r.blade       += d2.blade;
  r.pierce      += d2.pierce;
  r.sting       += d2.sting;
  r.crush       += d2.crush;
  r.fire        += d2.fire;
  r.ice         += d2.ice;
  r.electrical  += d2.electrical;
  r.biohazard   += d2.biohazard;
  r.acid        += d2.acid;
  r.psi         += d2.psi;
  r.wooden      += d2.wooden;
  r.silver      += d2.silver;
  r.radiation   += d2.radiation;
  return r;
}

Damage Damage::operator- (const Damage& d2) const {
  Damage r(*this);
  r.blunt -= d2.blunt > blunt? d2.blunt:blunt;
  r.blade -= d2.blade > blade? d2.blade:blade;
  r.pierce -= d2.pierce > pierce? d2.pierce:pierce;
  r.sting -= d2.sting > sting? d2.sting:sting;
  r.crush -= d2.crush > crush? d2.crush:crush;
  r.fire -= d2.fire > fire? d2.fire:fire;
  r.ice -= d2.ice > ice? d2.ice:ice;
  r.electrical -= d2.electrical > electrical? d2.electrical:electrical;
  r.biohazard -= d2.biohazard > biohazard? d2.biohazard:biohazard;
  r.acid -= d2.acid > acid? d2.acid:acid;
  r.psi -= d2.psi > psi? d2.psi:psi;
  r.wooden -= d2.wooden > wooden? d2.wooden:wooden;
  r.silver -= d2.silver > silver? d2.silver:silver;
  r.radiation -= d2.radiation > radiation? d2.radiation:radiation;
  return r;
  
}

Damage& Damage::operator+= (const Damage& d2){  return *this = *this + d2;  }
Damage& Damage::operator-= (const Damage& d2){  return *this = *this - d2;  }
Damage::operator int(){
  return blunt + blade + pierce + sting +
    crush + fire + ice + electrical + biohazard +
    acid + psi + wooden + silver + radiation;
}
