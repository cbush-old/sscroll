#ifndef FONT_H
#define FONT_H

#include "renderer.h"
#include <vector>
#include <memory>
#include <string>
#include <map>

using width_height = std::pair<unsigned, unsigned>;

struct Font : Renderer {

  struct glyph {
    unsigned w, h, y;
    glyph(){}
    glyph(unsigned _w, unsigned _h, unsigned _y):w(_w),h(_h),y(_y){}
    
  };

  private:
    const int max_char = '~';
    const int min_char = ' '+1;
    std::map<width_height,unsigned> vbo_offset;
    std::vector<glyph> glyphs;
    std::shared_ptr<std::vector<GLuint>> ids;
    VBO vbo;
 
  private:
    float _kerning { 1.25f };
    float max_line_h { 0.0f };
    float _line_h { 1.0f };

  public:
    Font();
    Font(const char*);

  public:
    int load(const char*);
    void write(std::string const&, float const&, float const&, float const&);
    void kerning(float const&);
    void line_height(float const&);
    float kerning() const;
    float line_height() const;

};

#endif
