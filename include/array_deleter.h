#ifndef ARRAY_DELETER_H
#define ARRAY_DELETER_H

template<typename T> struct array_deleter {
  inline void operator()(T *array) const {
    delete[] array; 
  }
};

#endif
