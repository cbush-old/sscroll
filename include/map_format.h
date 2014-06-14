#ifndef MAP_FORMAT_H
#define MAP_FORMAT_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>

#include "point.h"

using std::vector;
using std::ifstream;

struct map_line {
  public:
    vector<point<uint16_t>*> points;
};

struct Map {
  private:
    enum chunk_type {   A,C,D,I,L,N,P,S,W,X   };
  
    uint8_t head_ok(ifstream&);
    uint8_t load(const char*);
    
    template<chunk_type T> uint8_t eat_chunk(ifstream&){}
  
  public:
    point<uint16_t> pstart;
    vector<uint8_t> entities;
    vector<uint8_t> doors;
    vector<map_line*> lines, bounds;
  
  public:
    Map(const char*);
    ~Map(); 
    
  
};

template<> uint8_t Map::eat_chunk<Map::A>(ifstream&);
template<> uint8_t Map::eat_chunk<Map::C>(ifstream&);
template<> uint8_t Map::eat_chunk<Map::D>(ifstream&);
template<> uint8_t Map::eat_chunk<Map::I>(ifstream&);
template<> uint8_t Map::eat_chunk<Map::L>(ifstream&);
template<> uint8_t Map::eat_chunk<Map::N>(ifstream&);
template<> uint8_t Map::eat_chunk<Map::P>(ifstream&);
template<> uint8_t Map::eat_chunk<Map::S>(ifstream&);
template<> uint8_t Map::eat_chunk<Map::W>(ifstream&);
template<> uint8_t Map::eat_chunk<Map::X>(ifstream&);

#endif
