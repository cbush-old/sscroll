#ifndef LINE_H
#define LINE_H

#include "point.h"

template<typename T> struct line {
  public:
    point<T> p1,p2;
    
  public:
    line<T>(){}
    line<T>(point<T> a, point<T> b):p1(a),p2(b){}

  public:
    inline T dx(){  return p2.x - p1.x;    }
    inline T dy(){  return p2.y - p1.y;    }
    inline T m(){   
      T run = dx();  
      return run? dy()/run:0;
    }
    inline point<T> midpoint(){  return point<T>((p1.x+p2.x)/2.0,(p1.y+p2.y)/2.0);            }
    inline T intercept(){        return p1.y-p1.x*m();                                        }
    inline T length(){           return (T)sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));    }
    inline line<T> normal(){     return line<T>(point<T>(-dy(), dx()),point<T>(dy(), -dx()));        }
    inline double t(){           return atan2(p2.x-p1.x,p2.y-p1.y);                                  }
    inline bool is_vertical(){   return p1.x==p2.x;                }
    inline bool parallels(line<T> l2){   return 0==(m()-l2.m());   }
    inline void rotate(double angle){
      p1.rotate(angle);
      p2.rotate(angle);
    }
 
  public:
    template<typename U> inline friend point<U> intercept(line<U>,line<U>);
    template<typename U> inline friend bool perpendicular(line<U>,line<U>);
    
};

template<typename T> inline bool perpendicular(line<T> ln1, line<T> ln2){
  double dx1 = ln1.dx(), dy1 = ln1.dy();
  double dx2 = ln2.dx(), dy2 = ln2.dy();
  if(!dx1) return !dy2;
  if(!dy1) return !dx2;
  line<double> norm = ln2.normal();
  
  
  return false;
}

template<typename T> inline point<T> intercept(line<T> ln1, line<T> ln2){
  
  point<T> ip;
  if(ln2.dx()){ // ln2 not vertical
    if(!ln1.dx()){ // ln1 is vertical
      ip.x = ln1.p1.x;
      if(!ln2.dy()){ // ln2 horizontal
        ip.y = ln2.p1.y;
      } else {
        T m2 = ln2.m();
        T b2 = ln2.p1.y - m2 * ln2.p1.x;
        ip.y = m2*ip.x+b2;
      }
      return ip;
    } else { // ln1 is not vertical
      T m1 = ln1.m();
      T m2 = ln2.m();
      T b1 = ln1.p1.y - m1 * ln1.p1.x;
      T b2 = ln2.p1.y - m2 * ln2.p1.x;
      ip.x = (b2-b1)/(m1-m2);
      if(!ln2.dy()){
        ip.y = ln2.p1.y;
      } else {
        ip.y = m1*ip.x+b1;
      }
      return ip;
    }
  } else { // ln2 is vertical
    if(!ln1.dy()){ // ln1 is horizontal
      ip.x = ln1.p1.x;
      ip.y = ln2.p1.y;
    } else {
      T m1 = ln1.m();
      T b1 = ln1.p1.y - m1 * ln1.p1.x;
      ip.x = ln2.p1.x;
      ip.y = m1*ip.x+b1;
    }
    return ip;
  }

}

#endif
