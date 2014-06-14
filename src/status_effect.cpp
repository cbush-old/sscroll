#include "status_effect.h"

Status_effect::Status_effect(int type, int value){
  poisoned = type&POISONED?   value:0;
  petrified = type&PETRIFIED? value:0;
  frozen = type&FROZEN?       value:0;
  burning = type&BURNING?     value:0;
  confused = type&CONFUSED?   value:0;
  invincible = type&INVINCIBLE? value:0;
  invisible = type&INVISIBLE? value:0;
  shrunken = type&SHRUNKEN?   value:0;
  gigantic = type&GIGANTIC?   value:0;
  blind = type&BLIND?         value:0;

}

Status_effect& Status_effect::operator= (const Status_effect& hs2){
  poisoned = hs2.poisoned;
  petrified = hs2.petrified;
  frozen = hs2.frozen;
  burning = hs2.burning;
  confused = hs2.confused;
  invincible = hs2.invincible;
  invisible = hs2.invisible;
  shrunken = hs2.shrunken;
  gigantic = hs2.gigantic;
  blind = hs2.blind;

}

Status_effect& Status_effect::operator+= (const Status_effect& hs2){  *this = *this + hs2;  }
Status_effect& Status_effect::operator-= (const Status_effect& hs2){  *this = *this - hs2;  }

Status_effect Status_effect::operator- (const Status_effect& hs2) const {
  Status_effect r(*this);
  r.poisoned -= hs2.poisoned < poisoned? hs2.poisoned : poisoned;
  r.petrified -= hs2.petrified < petrified? hs2.petrified : petrified;
  r.frozen -= hs2.frozen < frozen? hs2.frozen : frozen;
  r.burning -= hs2.burning < burning? hs2.burning : burning;
  r.confused -= hs2.confused < confused? hs2.confused : confused;
  r.invincible -= hs2.invincible < invincible? hs2.invincible : invincible;
  r.invisible -= hs2.invisible < invisible? hs2.invisible : invisible;
  r.shrunken -= hs2.shrunken < shrunken? hs2.shrunken : shrunken;
  r.gigantic -= hs2.gigantic < gigantic? hs2.gigantic : gigantic;
  return r;
}

Status_effect Status_effect::operator+ (const Status_effect& hs2) const {
  Status_effect r(*this);
  r.poisoned += hs2.poisoned;
  r.petrified += hs2.petrified;
  r.frozen += hs2.frozen;
  r.burning += hs2.burning;
  r.confused += hs2.confused;
  r.invincible += hs2.invincible;
  r.invisible += hs2.invisible;
  r.shrunken += hs2.shrunken;
  r.gigantic += hs2.gigantic;
  return r;
}

