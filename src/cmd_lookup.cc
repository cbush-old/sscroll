const std::map<std::string const,cmd_pair const> cmd_lookup {
  
  char_cmd("up",    cmd_pair(PLAYER_Y_PORT,-1)),
  char_cmd("down",  cmd_pair(PLAYER_Y_PORT,+1)),
  char_cmd("left",  cmd_pair(PLAYER_X_PORT,-1)),
  char_cmd("right", cmd_pair(PLAYER_X_PORT,+1)),
  char_cmd("jump",  cmd_pair(PLAYER_JUMP_PORT,1)),
  char_cmd("shoot", cmd_pair(PLAYER_SHOOT_PORT,1)),
  char_cmd("whip",  cmd_pair(PLAYER_WHIP_PORT,1)),
  char_cmd("run",   cmd_pair(PLAYER_RUN_PORT,1)),
  char_cmd("camera_up",    cmd_pair(CAM_Y_PORT,-1)),
  char_cmd("camera_down",  cmd_pair(CAM_Y_PORT,+1)),
  char_cmd("camera_left",  cmd_pair(CAM_X_PORT,-1)),
  char_cmd("camera_right", cmd_pair(CAM_X_PORT,+1)),
  char_cmd("camera_in",    cmd_pair(CAM_Z_PORT,-1)),
  char_cmd("camera_out",   cmd_pair(CAM_Z_PORT,+1)),
  
};
