#include "map_format.h"

using std::cout;
using std::hex;

template<typename T> T next(ifstream& file){
  T r = 0;
  for(int i=sizeof(T)-1;i>=0;--i) r|=file.get()<<(i*8);
  return r;
}

// META
template<> uint8_t Map::eat_chunk<Map::I>(ifstream& f){

}
template<> uint8_t Map::eat_chunk<Map::A>(ifstream& f){
  pstart.x = next<uint16_t>(f);
  pstart.y = next<uint16_t>(f);
}

// LINES
template<> uint8_t Map::eat_chunk<Map::C>(ifstream& f){
  next<uint16_t>(f); // type/options (ignored)
  point<uint16_t> p;
  p.x = next<uint16_t>(f);  // origin
  p.y = next<uint16_t>(f);
  map_line* clip = new map_line();
  clip->points.push_back(new point<uint16_t>(p.x,p.y));
  while(f.good()){
    static bool toggle = 1; // alternating relevant offset x/y
    s16 n = next<s16>(f);
    if(!n) break;
    if(!(toggle=!toggle)) p.x += n; else p.y += n;
    clip->points.push_back(new point<uint16_t>(p.x,p.y));
  }
  bounds.push_back(clip);
}
template<> uint8_t Map::eat_chunk<Map::L>(ifstream& f){
  map_line* clip = new map_line();
  next<uint16_t>(f); // type/options (ignored for now)
  point<uint16_t> p;
  p.x = next<uint16_t>(f);  // origin
  p.y = next<uint16_t>(f);
  clip->points.push_back(new point<uint16_t>(p.x,p.y));
  while(f.good()){
    int8_t x = next<int8_t>(f);
    int8_t y = next<int8_t>(f);
    if(!(x|y)) break;
    p.x += x;
    p.y += y;
    clip->points.push_back(new point<uint16_t>(p.x,p.y));
  }
  lines.push_back(clip);
}
template<> uint8_t Map::eat_chunk<Map::S>(ifstream& f){
  map_line* clip = new map_line();
  next<uint16_t>(f); // type/options (ignored for now)
  point<uint16_t> p;
  p.x = next<uint16_t>(f);  // origin
  p.y = next<uint16_t>(f);
  clip->points.push_back(new point<uint16_t>(p.x,p.y));
  while(f.good()){
    int8_t x = next<int8_t>(f);
    int8_t y = next<int8_t>(f);
    if(!(x|y)) break;
    p.x += x;
    p.y += y;
    clip->points.push_back(new point<uint16_t>(p.x,p.y));
  }
  lines.push_back(clip);
}


// ENTITIES
template<> uint8_t Map::eat_chunk<Map::N>(ifstream& f){
  int type = next<uint16_t>(f);
  int x = next<uint16_t>(f);
  int y = next<uint16_t>(f);
}
template<> uint8_t Map::eat_chunk<Map::P>(ifstream& f){
  int type = next<uint16_t>(f);
  int x = next<uint16_t>(f);
  int y = next<uint16_t>(f);
}
template<> uint8_t Map::eat_chunk<Map::D>(ifstream& f){
  int type = next<uint16_t>(f);
  int x = next<uint16_t>(f);
  int y = next<uint16_t>(f);
}


// DOORS
template<> uint8_t Map::eat_chunk<Map::W>(ifstream& f){
  int type = next<uint16_t>(f);
  int x1 = next<uint16_t>(f);
  int y1 = next<uint16_t>(f);
  int x2 = next<uint16_t>(f);
  int y2 = next<uint16_t>(f);
}
template<> uint8_t Map::eat_chunk<Map::X>(ifstream& f){
  int type = next<uint16_t>(f);
  int x1 = next<uint16_t>(f);
  int y1 = next<uint16_t>(f);
  int map_id = next<uint32_t>(f);
}




uint8_t Map::head_ok(ifstream& file){

  uint32_t head[1];
  file.read((char*)head,4);
  
  if(*head!=0xcb50414d){
    cout << "Header error\n";
    return 0;
  }
  
  return 1;
  
}

uint8_t Map::load(const char* filename){

  ifstream file (filename);
  if(!file.good()) return 1;
  if(!head_ok(file)){
    file.close();
    return 2;
  }

  while(file.good()) switch(file.get()){
    case 'A': eat_chunk<A>(file); break;
    case 'C': eat_chunk<C>(file); break;
    case 'D': eat_chunk<D>(file); break;
    case 'I': eat_chunk<I>(file); break;
    case 'L': eat_chunk<L>(file); break;
    case 'N': eat_chunk<N>(file); break;
    case 'P': eat_chunk<P>(file); break;
    case 'S': eat_chunk<S>(file); break;
    case 'W': eat_chunk<W>(file); break;
    case 'X': eat_chunk<X>(file); break;
    default: break;
  }
  
  return 0;
  
}

Map::Map(const char* filename){

  if(load(filename)){
    cout << "error\n";
    
  }
  
  
 
}

Map::~Map(){

  for(auto i : lines)  delete i;
  for(auto i : bounds) delete i;
  
}
