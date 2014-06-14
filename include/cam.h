#ifndef CAM_H
#define CAM_H

#include "renderer.h"
#include "sprite_instance.h"

struct Camera : Renderer, Hub_connectable {
  private:
    const VBO vbo { std::vector<float> { 
    // this must line up with SPRITE_VBO_MODE in spriteset.h
        0, 0, 1, 0, 0, 1, 1, 1, // tex 1
        0, 0, 2, 0, 0, 2, 2, 2, // tex 2x2
        0, 0, 3, 0, 0, 3, 3, 3, // tex 3x3
        0, 0, 4, 0, 0, 4, 4, 4, // tex 4x4
        -4, -4, 4, -4, -4, 4, 4, 4, // vtx 8x8
        -8, -8, 8, -8, -8, 8, 8, 8, // vtx 16x16
        -16, -16, 16, -16, -16, 16, 16, 16, // vtx 32x32
        -16, -24, 16, -24, -16, 24, 16, 24, // vtx 32x48
        -24, -8, 24, -8, -24, 8, 24, 8, // vtx 48x16
        -32, -32, 32, -32, -32, 32, 32, 32, // vtx 64x64
        -64, -64, 64, -64, -64, 64, 64, 64, // vtx 128x128
        -64, -128, 64, -128, -64, 128, 64, 128, // vtx 128x256
        -128, -128, 128, -128, -128, 128, 128, 128, // vtx 256x256      
        -128, -256, 128, -256, -128, 256, 128, 256, // vtx 256x512      
        -256, -256, 256, -256, -256, 256, 256, 256, // vtx 512x512
    } };
    
  private:
    float move_speed;
    quat orientation;
    vec3 pos;
    
  public:
    Camera();
    
  public:
    // void zoom_to_fit(const vector<point<double>*>& );
    void follow(vec3 * const);
    void unfollow();
    void check_bounds();
    void update();
    void scan_to(vec3);
    bool sees(const vec3&);
    bool sees(const Sprite_instance&);
    
  public:
    void draw(const Sprite_instance&);
    void draw_sky();
    
};

#endif
