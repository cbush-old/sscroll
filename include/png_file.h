#ifndef _PNG_H
#define _PNG_H

#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <memory>
// wrapper for libpng15

class PNG {
  public:
    unsigned w, h;
    std::shared_ptr<uint32_t> pixels;

  public:
    PNG(const char*);
    
  public:
    void load(const char*);
    const uint32_t operator[](uint32_t const&) const;

};

#endif

