#include "cam.h"

extern vec3 global_scale;

Camera::Camera(){

  hub = &deadhub;
  pos = vec3(0,0,1.0);
  move_speed = 6.0;
  orientation = glm::angleAxis(0.0f,vec3(0.0f,0.0f,1.0f));
  
  glClearColor(0.00,0.0,0.05,1.00);
  
  program.bind();
    
  projection_matrix = glm::frustum<GLfloat>(-160.0f,160.0f,120.0f,-120.0f,1.0f,300.0f);
  program.set_matrix(projection,1,GL_FALSE,glm::value_ptr(projection_matrix));  
 
  vbo.point(texcoord_in,0);
  program.set(color,0.6,0.6,1.0,1.0);
  
  program.unbind();
  
}

void Camera::update(){

  draw_sky();
  
  float yrv = (float)(*hub)[CAM_YR_PORT];
  float zrv = (float)(*hub)[CAM_ZR_PORT];
  float xv = (float)(*hub)[CAM_X_PORT];
  float yv = (float)(*hub)[CAM_Y_PORT];
  float zv = (float)(*hub)[CAM_Z_PORT];
  
  if(yrv){
    orientation = glm::rotate(orientation, yrv*0.1f, vec3(0.0f,1.0f,0.0f));
    orientation = glm::normalize(orientation);
  }
  if(zrv){
    orientation = glm::rotate(orientation, zrv*0.1f, vec3(0.0f,0.0f,1.0f));
    orientation = glm::normalize(orientation);
  }
  
  pos -= vec3(xv*move_speed, yv*move_speed, zv*0.05f) * orientation;
  
  
  mat4 m;
  m = glm::rotate(mat4(),glm::angle(orientation),glm::axis(orientation));
  m = glm::translate(m,pos * global_scale);
  modelview_matrix = m;
  
  (*hub)[CAM_FOLLOW_PORT] = !(xv||yv);
  if((*hub)[CAM_FOLLOW_PORT]) scan_to(hub->vecmsg);
  
}

void Camera::draw(const Sprite_instance& spr){
  
  program.bind();
  program.enable(vs_position);
  program.enable(texcoord_in);
  
  mat4 m = mat4();
  
  vec3 p = vec3(spr.pos.x,spr.pos.y,-spr.pos.z) * global_scale;
  m = glm::translate(m,p);
  m = glm::rotate(m,spr.rotation,vec3(0.0f,0.0f,1.0f));
  if(spr.flip_y) m = glm::rotate(m,180.0f,vec3(0.0f,1.0f,0.0f));
  if(spr.flip_x) m = glm::rotate(m,180.0f,vec3(1.0f,0.0f,0.0f));
  
  m = glm::scale(m,spr.scale * global_scale);
  
  m = modelview_matrix * m;
  program.set_matrix(modelview,1,GL_FALSE,glm::value_ptr(m));
  
  vbo.point(vs_position,(4 + spr.set->mode) * sizeof(float)*8);
  
  glBindTexture(GL_TEXTURE_2D,spr.get());
  glDrawArrays(GL_TRIANGLE_STRIP,0,4);
  
  program.disable(vs_position);
  program.disable(texcoord_in);
  program.unbind();
  
}

void Camera::scan_to(vec3 t){

  float dx = t.x - pos.x;
  float dy = t.y - pos.y;
  float z = tan(-1.0) * (t.z - pos.z) * 18.0f;
  pos = vec3(-dx/2.0f,-dy/2.0f - z,pos.z);

}

void Camera::draw_sky(){
  
}

bool Camera::sees(const Sprite_instance& s){
  
  // cone slice radius
  float csr = 300.0f * (s.pos.z - pos.z);
  float dx = -s.pos.x - pos.x;
  float dy = -s.pos.y - pos.y;
  return bool((dx*dx+dy*dy) < (csr*csr));
  
}
