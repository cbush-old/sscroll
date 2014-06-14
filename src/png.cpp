#include <cstdio>
#include <cstring>
#include "array_deleter.h"
#include "png_file.h"
#include <png.h>

PNG::PNG(const char* filename){

  load(filename);

}

const uint32_t PNG::operator[](uint32_t const& i) const {

  return pixels.get()[i];
  
}

void PNG::load(const char* filename) {

  FILE *fp = fopen(filename, "rb");
  
  if(!fp) throw std::runtime_error("Couldn't open PNG file.");

  png_structp png_ptr;   
  png_infop info_ptr;
  png_byte header[8];
  
  fread(header, 1, 8, fp);
  
  if(png_sig_cmp(header, 0, 8)){
    fclose(fp);
    throw std::runtime_error("PNG load error: wrong file format.");
  }
  
  fseek(fp,0,SEEK_SET);

  if(!(png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL))){
    fclose(fp);
    throw std::runtime_error("PNG load error: couldn't allocate read struct.");
  }
  
  if(!(info_ptr = png_create_info_struct(png_ptr))){
    fclose(fp);
    throw std::runtime_error("PNG load error: couldn't allocate info struct.");
  }
  
  png_init_io(png_ptr, fp);
  png_read_png(png_ptr, info_ptr, 0, NULL);
  fclose(fp);
  
  h = png_get_image_height(png_ptr, info_ptr);
  w = png_get_image_width(png_ptr, info_ptr);  
  
  png_bytep *row_pointers = png_get_rows(png_ptr, info_ptr);

  pixels = std::shared_ptr<uint32_t>(new uint32_t[h*w],array_deleter<uint32_t>());
  
  uint32_t r, g, b, a;
  
  for(int j=0, k=0, i=0; i < h; i++, j = 0)
    while(j < w*4){
      r = row_pointers[i][j++] << 24;
      g = row_pointers[i][j++] << 16;
      b = row_pointers[i][j++] << 8;
      a = row_pointers[i][j++] << 0;
      pixels.get()[k++] = r+g+b+a;
    };

  png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

}
