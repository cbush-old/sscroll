#include "ttf.h"

struct ttfenv {
  private:
    ttfenv(){ if(!TTF_WasInit()&&TTF_Init()==-1) throw std::runtime_error(TTF_GetError()); }
    ~ttfenv(){ if(TTF_WasInit()) TTF_Quit(); }
  
  public:
    static ttfenv& get(){ static ttfenv handle; return handle; }

};

struct rwops_deleter {
  inline void operator()(SDL_RWops** rw) const {
    if(*rw) SDL_RWclose(*rw);
    delete rw;
  }
};
struct TTF_font_deleter {
  inline void operator()(TTF_Font** font) const {
    TTF_CloseFont(*font);
    delete font;
  }
};

TTF::TTF(){ 
  ttfenv::get();
}

TTF::TTF(const char* path){
  ttfenv::get();
  open(path);
}

TTF::TTF(const char* path, int const& ptsize){
  ttfenv::get();
  open(path);
  resize(ptsize);
}

void TTF::open(const char* path){ 
  
  font_rw = std::shared_ptr<SDL_RWops*>(new SDL_RWops*(NULL),rwops_deleter());
  
  *font_rw = SDL_RWFromFile(path,"r");
  if(*font_rw==NULL) throw std::runtime_error("Could not open TTF file.");

}

void TTF::resize(int const& ptsize){
  
  font = std::shared_ptr<TTF_Font*>(new TTF_Font*(NULL),TTF_font_deleter());
  
  SDL_RWseek(*font_rw, 0, SEEK_SET);
  *font = TTF_OpenFontIndexRW(*font_rw, 0, ptsize, 0);
  
  if(*font==NULL) throw std::runtime_error("Could not open TTF font index.");
  
}

void TTF::open(const char* path, int const& ptsize){
  open(path);
  resize(ptsize);
  
}

TTF_Glyph* TTF::render(uint16_t const& c) const {
  
  TTF_Glyph* glyph;
  
  glyph = TTF_RenderGlyph_Blended(*font, c);
  
  if(glyph == NULL) throw std::runtime_error("RenderGlyph returned null");

  return glyph;
  
}

void TTF::free(TTF_Glyph* data) const {
  
  TTF_FreeGlyph(data);

}

