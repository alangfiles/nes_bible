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
    if (player_shooting < 20)
    {
      if (direction == LEFT)
      {
        if (player_jumping)
        {
          oam_meta_spr(temp_x, temp_y, mosesjumpleftshoot);
        }
        else
        {
          if (BoxGuy1.vel_x)
          {
            if (sprite_frame_counter < 8)
            {
              oam_meta_spr(temp_x, temp_y, mosesrunshoot1left);
            }
            else if (sprite_frame_counter < 15)
            {
              oam_meta_spr(temp_x, temp_y, mosesrunshoot2left);
            }
            else
            {
              sprite_frame_counter = 0;
              oam_meta_spr(temp_x, temp_y, mosesrunshoot2left);
            }
          }
          else
          {
            oam_meta_spr(temp_x, temp_y, mosesstandshootleft);
          }
        }
      }
      else
      {
        if (player_jumping)
        {
          oam_meta_spr(temp_x, temp_y, mosesjumprightshoot);
        }
        else
        {
          if (BoxGuy1.vel_x)
          {
            if (sprite_frame_counter < 8)
            {
              oam_meta_spr(temp_x, temp_y, mosesrunshoot1right);
            }
            else if (sprite_frame_counter < 15)
            {
              oam_meta_spr(temp_x, temp_y, mosesrunshoot2right);
            }
            else
            {
              sprite_frame_counter = 0;
              oam_meta_spr(temp_x, temp_y, mosesrunshoot2right);
            }
          }
          else
          {
            oam_meta_spr(temp_x, temp_y, mosesstandshootright);
          }
        }
      }
    }
    else
    {
      player_shooting = 0;
    }
  }
  else
  {

    if (player_jumping && BoxGuy1.vel_y > 0) // aka, falling
    {                                        // jumping
      if (direction == LEFT)
      {
        if (sprite_frame_counter < 8)
        {
          oam_meta_spr(temp_x, temp_y, mosesfallwiggle1left);
        }
        else if (sprite_frame_counter < 15)
        {
          oam_meta_spr(temp_x, temp_y, mosesfallwiggle2left);
        }
        else
        {
          sprite_frame_counter = 0;
          oam_meta_spr(temp_x, temp_y, mosesfallwiggle2left);
        }
      }
      else
      {
        if (sprite_frame_counter < 8)
        {
          oam_meta_spr(temp_x, temp_y, mosesfallwiggle1right);
        }
        else if (sprite_frame_counter < 15)
        {
          oam_meta_spr(temp_x, temp_y, mosesfallwiggle2right);
        }
        else
        {
          sprite_frame_counter = 0;
          oam_meta_spr(temp_x, temp_y, mosesfallwiggle2right);
        }
      }
    }
    else if (direction == LEFT)
    {

      if (BoxGuy1.vel_x)
      {
        if (sprite_frame_counter < 4)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun1left);
        }
        else if (sprite_frame_counter < 8)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun2left);
        }
        else if (sprite_frame_counter < 12)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun3left);
        }
        else if (sprite_frame_counter < 16)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun4left);
        }
        else if (sprite_frame_counter < 20)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun5left);
        }
        else if (sprite_frame_counter < 24)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun4left);
        }
        else if (sprite_frame_counter < 28)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun3left);
        }
        else if (sprite_frame_counter < 32)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun2left);
        }
        else if (sprite_frame_counter < 35)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun1left);
        }
        else
        {
          sprite_frame_counter = 0;
          oam_meta_spr(temp_x, temp_y, mosesrun1left);
        }
      }
      else
      {
        sprite_frame_counter = 0;
        oam_meta_spr(temp_x, temp_y, mosesstandleft);
      }
    }
    else
    {
      if (BoxGuy1.vel_x)
      {
        if (sprite_frame_counter < 4)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun1right);
        }
        else if (sprite_frame_counter < 8)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun2right);
        }
        else if (sprite_frame_counter < 12)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun3right);
        }
        else if (sprite_frame_counter < 16)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun4right);
        }
        else if (sprite_frame_counter < 20)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun5right);
        }
        else if (sprite_frame_counter < 24)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun4right);
        }
        else if (sprite_frame_counter < 28)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun3right);
        }
        else if (sprite_frame_counter < 32)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun2right);
        }
        else if (sprite_frame_counter < 35)
        {
          oam_meta_spr(temp_x, temp_y, mosesrun1right);
        }
        else
        {
          sprite_frame_counter = 0;
          oam_meta_spr(temp_x, temp_y, mosesrun1right);
        }
      }
      else
      {
        sprite_frame_counter = 0;
        oam_meta_spr(temp_x, temp_y, mosesstandright);
      }
    }
  }
}