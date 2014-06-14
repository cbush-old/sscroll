#ifndef GL_OBJECT_H
#define GL_OBJECT_H

#include <memory>
#include "gl_deleters.h"
#include "glmath.h"
#include "hard_type.h"

enum gl_var {  ATTRIBUTE, UNIFORM   };

using attribute = hard_type<ATTRIBUTE,GLint>;
using uniform = hard_type<UNIFORM,GLint>;


struct GL_object {
  
  protected:
    std::shared_ptr<GLuint> id;
    
  public:
    inline virtual ~GL_object()=0;
    
};

GL_object::~GL_object(){}

#endif
