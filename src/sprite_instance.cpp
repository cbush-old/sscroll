#include "sprite_instance.h"

Sprite_instance::Sprite_instance():scale(vec3(1.0)){}

Sprite_instance::Sprite_instance(Spriteset* s):
  _row(0),_frame(0),w(s->w),h(s->h),rotation(0.0f),set(s),scale(vec3(1.0)),flip_x(0),flip_y(0){}

const GLuint Sprite_instance::get() const {    
  return (*set)[_frame];
}

unsigned Sprite_instance::frame() const {    
  return _frame;                   
}

void Sprite_instance::frame(unsigned i){     
  _frame = i%set->cols;            
}

void Sprite_instance::advance_frame(int n){  
  _frame = (_frame+n)%set->cols;   
}

void Sprite_instance::advance_frame(){       
  _frame = (++_frame)%set->cols;   
}

unsigned Sprite_instance::row() const { 
  return _row;                     
}

void Sprite_instance::row(unsigned i){       
  _row = i%set->rows;              
}

void Sprite_instance::advance_row(int n){    
  _row = (_frame+n)%set->rows;     
}

void Sprite_instance::advance_row(){         
  _row = (++_frame)%set->rows;     
}

