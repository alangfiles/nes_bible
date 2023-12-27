void draw_player_sprites()
{
  temp_x = BoxGuy1.x >> 8;
  temp_y = BoxGuy1.y >> 8;
  if (temp_x == 0)
    temp_x = 1;
  if (temp_y == 0)
    temp_y = 1;
  //

  ++sprite_frame_counter;

  if (player_shooting)
  {
    ++player_shooting;
    if (player_shooting > 15)
    {
      player_shooting = 0;
    }
    if (direction == LEFT)
    {
      if (player_in_air)
      {
        oam_meta_spr(temp_x, temp_y, animate_playerjumpleftshoot_data);
      }
      else
      {
        if (BoxGuy1.vel_x)
        {
          if (sprite_frame_counter < 8)
          {
            oam_meta_spr(temp_x, temp_y, animate_playerrunshoot1left_data);
          }
          else if (sprite_frame_counter < 15)
          {
            oam_meta_spr(temp_x, temp_y, animate_playerrunshoot2left_data);
          }
          else
          {
            sprite_frame_counter = 0;
            oam_meta_spr(temp_x, temp_y, animate_playerrunshoot2left_data);
          }
        }
        else
        {
          oam_meta_spr(temp_x, temp_y, animate_playerstandshootleft_data);
        }
      }
    }
    else
    {
      if (player_in_air)
      {
        oam_meta_spr(temp_x, temp_y, animate_playerjumprightshoot_data);
      }
      else
      {
        if (BoxGuy1.vel_x)
        {
          if (sprite_frame_counter < 8)
          {
            oam_meta_spr(temp_x, temp_y, animate_playerrunshoot1right_data);
          }
          else if (sprite_frame_counter < 15)
          {
            oam_meta_spr(temp_x, temp_y, animate_playerrunshoot2right_data);
          }
          else
          {
            sprite_frame_counter = 0;
            oam_meta_spr(temp_x, temp_y, animate_playerrunshoot2right_data);
          }
        }
        else
        {
          oam_meta_spr(temp_x, temp_y, animate_playerstandshootright_data);
        }
      }
    }
  }
  else
  {

    if (player_in_air) // aka, falling
    {                  // jumping
      if (player_jumping)
      {
        if (direction == LEFT)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerjumpleft_data);
        }
        else
        {
          oam_meta_spr(temp_x, temp_y, animate_playerjumpright_data);
        }
      }
      else
      { // player_falling

        if (direction == LEFT)
        {
          if (sprite_frame_counter < 8)
          {
            oam_meta_spr(temp_x, temp_y, animate_playerfallwiggle1left_data);
          }
          else if (sprite_frame_counter < 15)
          {
            oam_meta_spr(temp_x, temp_y, animate_playerfallwiggle2leftshoot_data);
          }
          else
          {
            sprite_frame_counter = 0;
            oam_meta_spr(temp_x, temp_y, animate_playerfallwiggle2leftshoot_data);
          }
        }
        else
        {
          if (sprite_frame_counter < 8)
          {
            oam_meta_spr(temp_x, temp_y, animate_playerfallwiggle1right_data);
          }
          else if (sprite_frame_counter < 15)
          {
            oam_meta_spr(temp_x, temp_y, animate_playerfallwiggle2right_data);
          }
          else
          {
            sprite_frame_counter = 0;
            oam_meta_spr(temp_x, temp_y, animate_playerfallwiggle2right_data);
          }
        }
      }
    }
    else if (player_on_ladder)
    {
      oam_meta_spr(temp_x, temp_y, animate_playerclimb1_data);
    }
    else if (direction == LEFT) // not jumping
    {

      if (BoxGuy1.vel_x)
      {
        if (sprite_frame_counter < 4)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun1left_data);
        }
        else if (sprite_frame_counter < 8)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun2left_data);
        }
        else if (sprite_frame_counter < 12)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun3left_data);
        }
        else if (sprite_frame_counter < 16)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun4left_data);
        }
        else if (sprite_frame_counter < 20)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun5left_data);
        }
        else if (sprite_frame_counter < 24)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun4left_data);
        }
        else if (sprite_frame_counter < 28)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun3left_data);
        }
        else if (sprite_frame_counter < 32)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun2left_data);
        }
        else if (sprite_frame_counter < 35)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun1left_data);
        }
        else
        {
          sprite_frame_counter = 0;
          oam_meta_spr(temp_x, temp_y, animate_playerrun1left_data);
        }
      }
      else
      {
        sprite_frame_counter = 0;
        oam_meta_spr(temp_x, temp_y, animate_playerstandleft_data);
      }
    }
    else
    {
      if (BoxGuy1.vel_x)
      {
        if (sprite_frame_counter < 4)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun1right_data);
        }
        else if (sprite_frame_counter < 8)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun2right_data);
        }
        else if (sprite_frame_counter < 12)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun3right_data);
        }
        else if (sprite_frame_counter < 16)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun4right_data);
        }
        else if (sprite_frame_counter < 20)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun5right_data);
        }
        else if (sprite_frame_counter < 24)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun4right_data);
        }
        else if (sprite_frame_counter < 28)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun3right_data);
        }
        else if (sprite_frame_counter < 32)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun2right_data);
        }
        else if (sprite_frame_counter < 35)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerrun1right_data);
        }
        else
        {
          sprite_frame_counter = 0;
          oam_meta_spr(temp_x, temp_y, animate_playerrun1right_data);
        }
      }
      else
      {
        sprite_frame_counter = 0;
        oam_meta_spr(temp_x, temp_y, animate_playerstandright_data);
      }
    }
  }
}