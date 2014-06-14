#ifndef POINT_H
#define POINT_H

#include <sstream>
#include <cmath>

template<typename T> struct line;

template<typename T> struct point {
  public:
    union { T x,w; };
    union { T y,h; };
   
  public:
    point<T>(T _x, T _y):x(_x),y(_y){}
    point<T>():x(0),y(0){}
    operator const char*();
    
  public:
    inline point<T> operator= (point p){     x = p.x, y = p.y;  return *this;    }
    inline point<T> operator+ (point<T> p){  return point<T>(x + p.x, y + p.y);  }
    inline point<T> operator- (point<T> p){  return point<T>(x - p.x, y - p.y);  }
    inline point<T> operator* (point<T> p){  return point<T>(x*p.x, y*p.y);  }
    inline point<T> operator/ (point<T> p){  p.x /= x;  p.y /= y;  return p;  }
    inline point<T> operator* (double d){    return point<T>(x*d,y*d);      }
    inline point<T> operator/ (double d){    return point<T>(x/d, y/d);     }
    point<T> operator+=(point<T> p){   return *this=*this+p;    }
    point<T> operator-=(point<T> p){   return *this=*this-p;    }
    point<T> operator*=(point<T> p){   return *this=*this*p;    }
    point<T> operator/=(point<T> p){   return *this=*this/p;    }
    point<T> operator*=(double d){  return *this*=point<T>(d,d);   }
    point<T> operator/=(double d){  return *this/=point<T>(d,d);   }
    
  public:
    template<typename U> inline friend bool operator==(point<U>,point<U>);
    template<typename U> inline friend bool operator!=(point<U>,point<U>);
    template<typename U> inline friend bool operator< (point<U>,point<U>);
    template<typename U> inline friend point<U> midpoint(point<U>,point<U>);
    template<typename U> inline friend point<U> round(point<U>);
    template<typename U> inline friend double distance(point<U>,point<U>);
    
  public:
    bool within(point<T> tl,point<T> br){  return (tl.y <= y&&y <= br.y)&&(tl.x <= x&&x <= br.x);   }
    bool inseg(line<T> seg){  
      return (
        ((seg.p1.y <= y&&y <= seg.p2.y)&&(seg.p1.x <= x&&x <= seg.p2.x))||
        ((seg.p1.y >= y&&y >= seg.p2.y)&&(seg.p1.x <= x&&x <= seg.p2.x))||
        ((seg.p1.y >= y&&y >= seg.p2.y)&&(seg.p1.x >= x&&x >= seg.p2.x))||
        ((seg.p1.y <= y&&y <= seg.p2.y)&&(seg.p1.x >= x&&x >= seg.p2.x))
      );
    }
    inline void rotate(double t){
      double tmp_x = x;
      x = x*cos(t) - y*sin(t);
      y = tmp_x*sin(t) + y*cos(t);
    }
    
};

template<typename T> inline bool operator==(point<T> p1,point<T> p2){  return p1.x==p2.x&&p1.y==p2.y;  }
template<typename T> inline bool operator< (point<T> p1,point<T> p2){  return (p1.x<p2.x&&p1.y<p2.y);  }
template<typename T> inline bool operator> (point<T> p1,point<T> p2){  return (p1.x>p2.x&&p1.y>p2.y);  }
template<typename T> bool operator!=(point<T> p1,point<T> p2){ return !(p1==p2); }
template<typename T> bool operator<=(point<T> p1,point<T> p2){ return (p1.x<=p2.x&&p1.y<=p2.y); }
template<typename T> bool operator>=(point<T> p1,point<T> p2){ return (p1.x>=p2.x&&p1.y>=p2.y); }
template<typename T> inline point<T> midpoint(point<T> p1,point<T> p2){
  return point<T>((p1.x+p2.x)/2.0,(p1.y+p2.y)/2.0);
}
template<typename T> inline double distance(point<T> p1,point<T> p2){ return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)); }
template<typename T> inline point<T> round(point<T> p){  return point<T>(round(p.x),round(p.y));   }

// tostring
template<typename T> point<T>::operator const char*(){
  std::stringstream ss;
  ss << '(' << x << ',' << y << ')';
  return ss.str().c_str();
}


#endif
