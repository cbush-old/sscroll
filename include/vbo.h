#ifndef VBO_H
#define VBO_H

#include <vector>
#include "gl_object.h"

struct VBO : GL_object {  
  
  public:
    VBO();
    VBO(std::vector<float> const&);

  public:
    void point(attribute const&, int const&) const;
    
};


#endif
