#ifndef HARD_TYPE_H
#define HARD_TYPE_H

template<const int T,typename U=int> struct hard_type {
  private:
    U v;
    
  public:
    hard_type<T,U>(){}
    hard_type<T,U>(U const& _v):v(_v){}
    inline hard_type<T,U>& operator=(hard_type<T,U> const& b){ v = b.v; return *this; }
    inline hard_type<T,U>& operator+=(hard_type<T,U> const& b){ v += b.v; return *this; }
    inline hard_type<T,U>& operator-=(hard_type<T,U> const& b){ v -= b.v; return *this; }
    inline hard_type<T,U>& operator*=(hard_type<T,U> const& b){ v *= b.v; return *this; }
    inline hard_type<T,U>& operator/=(hard_type<T,U> const& b){ v /= b.v; return *this; }
    inline hard_type<T,U>& operator%=(hard_type<T,U> const& b){ v %= b.v; return *this; }
    inline hard_type<T,U>& operator&=(hard_type<T,U> const& b){ v &= b.v; return *this; }
    inline hard_type<T,U>& operator|=(hard_type<T,U> const& b){ v |= b.v; return *this; }
    inline hard_type<T,U>& operator^=(hard_type<T,U> const& b){ v ^= b.v; return *this; }
    inline hard_type<T,U>& operator<<=(hard_type<T,U> const& b){ v <<= b.v; return *this; }
    inline hard_type<T,U>& operator>>=(hard_type<T,U> const& b){ v >>= b.v; return *this; }
    inline hard_type<T,U>& operator++(){ ++v; return *this; }
    inline hard_type<T,U>& operator--(){ --v; return *this; }
    inline hard_type<T,U> operator+() const { return hard_type<T,U>(+v); }
    inline hard_type<T,U> operator-() const { return hard_type<T,U>(-v); }
    inline hard_type<T,U> operator++(int){ return hard_type<T,U>(v++); }
    inline hard_type<T,U> operator--(int){ return hard_type<T,U>(v--); }
    inline hard_type<T,U> operator+(hard_type<T,U> const& b) const { return hard_type<T,U>(v + b.v); }
    inline hard_type<T,U> operator-(hard_type<T,U> const& b) const { return hard_type<T,U>(v - b.v); }
    inline hard_type<T,U> operator*(hard_type<T,U> const& b) const { return hard_type<T,U>(v * b.v); }
    inline hard_type<T,U> operator/(hard_type<T,U> const& b) const { return hard_type<T,U>(v / b.v); }
    inline hard_type<T,U> operator%(hard_type<T,U> const& b) const { return hard_type<T,U>(v % b.v); }
    inline bool operator!() const { return !v; }
    inline bool operator&&(hard_type<T,U> const& b) const { return v&&b.v; }
    inline bool operator||(hard_type<T,U> const& b) const { return v||b.v; }
    inline bool operator==(hard_type<T,U> const& b) const { return v==b.v; }
    inline bool operator!=(hard_type<T,U> const& b) const { return !(v==b.v); }
    inline hard_type<T,U> operator~() const { return hard_type<T,U>(~v); }
    inline hard_type<T,U> operator&(hard_type<T,U> const& b) const { return hard_type<T,U>(v&b.v); }
    inline hard_type<T,U> operator|(hard_type<T,U> const& b) const { return hard_type<T,U>(v|b.v); }
    inline hard_type<T,U> operator^(hard_type<T,U> const& b) const { return hard_type<T,U>(v^b.v); }
    inline hard_type<T,U> operator<<(hard_type<T,U> const& b) const { return hard_type<T,U>(v<<b.v); }
    inline hard_type<T,U> operator>>(hard_type<T,U> const& b) const { return hard_type<T,U>(v>>b.v); }
    template<typename V> operator V() const { return (V)v; }
    
};

#endif
