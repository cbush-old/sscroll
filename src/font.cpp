#include "font.h"
#include "ttf.h"
#include "gl_object.h"

Font::Font(){
  oslayer::get();
  
}

Font::Font(const char* path):Font(){
  load(path);
}

int Font::load(const char* path){ 
  
  const uint16_t range = max_char - min_char;
  
  ids = std::shared_ptr<std::vector<GLuint>>(new std::vector<GLuint>(range,0), GL_textures_deleter());
  glGenTextures(range, ids->data());
  
  TTF ttf (path);
  
  // static const std::vector<uint32_t> mips { 256, 128, 64, 32, 16, 8, 4 };
  static const std::vector<uint32_t> mips { 256 };
  static const uint32_t max_mip = mips[0];
  static const size_t n_mips = mips.size();
  
  glyphs.resize(range);
  GLint level = -1;
  
  unsigned offset = 0;
  
  
  
  for(uint32_t const& mip : mips){
    
    level++;
    ttf.resize(mip);
    
    for(uint16_t i = 0; i < range; ++i){

      TTF_Glyph* raster = ttf.render(min_char+i);
      
      if(raster->h > mip || raster->w > mip) throw std::runtime_error("Font size error!");
      
      std::vector<uint32_t> pixel_copy (mip*mip,0);
      
      for(int y = 0; y < raster->h; ++y){
        for(int x = 0; x < raster->w; ++x){
          pixel_copy[y*mip+x] = raster->pixels[raster->w * y + x];
        }
      }
  
      if(raster->h > max_line_h) max_line_h = (float)raster->h;
      
      glBindTexture(GL_TEXTURE_2D, ids->at(i)); 
      
      if(mip == max_mip){
        
        glyphs[i] = glyph(raster->w, raster->h, raster->y_offset);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); // seems that no mipmapping looks best
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_LEVEL,n_mips-1);
        
      }
      glTexImage2D(GL_TEXTURE_2D, level, GL_RGBA, mip, mip, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixel_copy.data());

      pixel_copy.clear();
      ttf.free(raster);
      
    }
  }

  vbo = VBO(std::vector<float> {
      0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
      0.0f, 0.0f, (float)mips[0], 0.0f, 0.0f, (float)mips[0], (float)mips[0], (float)mips[0]
  });
  
  vbo.point(texcoord_in,0);
  
  program.bind();
  projection_matrix = glm::ortho<GLfloat>(0,800,600,0,0,1);
  program.set_matrix(projection,1,GL_FALSE,glm::value_ptr(projection_matrix));  
  
  program.set(color,1.0f,1.0f,1.0f,1.0f);
  program.unbind();

}

void Font::write(std::string const& s, float const& top, float const& left, float const& size){
  
  program.bind();
  
  program.enable(vs_position);
  program.enable(texcoord_in);
  vbo.point(vs_position, 8 * sizeof(float));
  
  float shrink = 0.0042f;
  modelview_matrix = glm::translate(mat4(), vec3(left,top,0.0f));
  modelview_matrix = glm::scale(modelview_matrix, vec3(size*shrink,size*shrink,0.0f));
  mat4 cursor = mat4(); 
  
  for(uint16_t i=0; i < s.length(); ++i){
    
    if(s[i]=='\r'){ 
      continue;
    } else if(s[i]=='\n'){
      cursor = mat4();
      modelview_matrix = glm::translate(modelview_matrix,vec3(0.0f, max_line_h * _line_h, 0.0f));
    } else if(s[i]==' '){
    
    } else if(s[i]=='\t'){
    
    
    } else {
      
      uint16_t k = (s[i] < min_char || s[i] > max_char)? 0 : s[i] - min_char;
      
      mat4 m = glm::translate(mat4(),vec3(0.0f,(float)glyphs[k].y,0.0f));
      program.set_matrix(modelview,1,GL_FALSE,glm::value_ptr(modelview_matrix * cursor * m));
      glBindTexture(GL_TEXTURE_2D,ids->at(k));
      glDrawArrays(GL_TRIANGLE_STRIP,0,4);
      
      cursor = glm::translate(cursor,vec3(float(glyphs[k].w * _kerning),0.0f,0.0f));
      
    }
  }
  
  program.disable(texcoord_in);
  program.disable(vs_position);
  program.unbind();

}

float Font::kerning() const {
  return _kerning;
}

void Font::kerning(float const& v){
  _kerning = v;
}

float Font::line_height() const {
  return _line_h;
}

void Font::line_height(float const& v){
  _line_h = v;
}

