#ifndef WALL_H
#define WALL_H

#include <iostream>
#include <cstdint>
#include <vector>

using std::vector;

#include "line.h"
#include "cam.h"

struct Wall {
  public:
    vector<point<double>> vertex;
    int terrain_type;
  
  public:
    Wall();
    Wall(const vector<point<double>>&);
    
};

#endif
