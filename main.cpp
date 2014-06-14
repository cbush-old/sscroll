////////////////////////////////////////
//                                    //
//                                    //
////////////////////////////////////////

#include <iostream>
#include <cstdint>

#include "input.h"
#include "world.h"
#include "font.h"

Camera camera;
Player_type player;
World world;

float gravity;
uint8_t global_rate;

enum modes {
  IN_GAME,
  BIND_KEYS
} Game_mode;


vec3 global_scale;

int main() {

  Font font("ass/LiberationMono-Regular.ttf");
  
  const uint32_t delay = 33;
  global_scale = vec3(32.0);
  gravity = 1.0f;
  
  Game_mode = IN_GAME;
  
  Keyboard input;
  Hub hub;
  
  if(input.load_mapping("ass/default.in")){
  
    std::cout << "Couldn't load input map!\n";
    return 1;
  
  }
  
  Spriteset sprset = Spriteset("ass/spritesheet1.png",SPRITE_32x48);
  Sprite_instance spr = Sprite_instance(&sprset);

  player.spriteset = &sprset;
  
  Player_inst avatar(&player);
  
  input.connect(&hub);
  avatar.connect(&hub);
  camera.connect(&hub);
  
  avatar.hp = 100;
  avatar.hit_radius = 128.0f;
  avatar.vel = vec3(0.0f);
  avatar.pos = vec3(3.0f);
  
  world.push(avatar);  
  avatar.disconnect();
  
  for(int i=0; i < 32; ++i){
    avatar.pos.x = rand()%10000;
    world.push(avatar);
  }

  const int w = 800, h = 600;
  oslayer::resize(w,h);
 
  for(SDL_Event e; e.type!=SDL_QUIT; ){
 
    uint32_t ticks = SDL_GetTicks();
    
    input.handle(e);
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);   
    
    world.draw_walls();
    
    world.update(1.0);
    
    camera.update();
    
    font.write("Hello",0,0,32.0f);
   
    oslayer::swap();
    
    uint32_t dt = SDL_GetTicks() - ticks;
    
    SDL_Delay(delay - (dt > delay? 0 : dt));

  }
  
}
