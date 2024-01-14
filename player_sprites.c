void draw_player_health_meter()
{
  // draw health meter
  switch (BoxGuy1.health)
  {
  case 28:
    oam_meta_spr(0x16, 0x16, animate_meter28_data);
    break;
  case 27:
    oam_meta_spr(0x16, 0x16, animate_meter27_data);
    break;
  case 26:
    oam_meta_spr(0x16, 0x16, animate_meter26_data);
    break;
  case 25:
    oam_meta_spr(0x16, 0x16, animate_meter25_data);
    break;
  case 24:
    oam_meta_spr(0x16, 0x16, animate_meter24_data);
    break;
  case 23:
    oam_meta_spr(0x16, 0x16, animate_meter23_data);
    break;
  case 22:
    oam_meta_spr(0x16, 0x16, animate_meter22_data);
    break;
  case 21:
    oam_meta_spr(0x16, 0x16, animate_meter21_data);
    break;
  case 20:
    oam_meta_spr(0x16, 0x16, animate_meter20_data);
    break;
  case 19:
    oam_meta_spr(0x16, 0x16, animate_meter19_data);
    break;
  case 18:
    oam_meta_spr(0x16, 0x16, animate_meter18_data);
    break;
  case 17:
    oam_meta_spr(0x16, 0x16, animate_meter17_data);
    break;
  case 16:
    oam_meta_spr(0x16, 0x16, animate_meter16_data);
    break;
  case 15:
    oam_meta_spr(0x16, 0x16, animate_meter15_data);
    break;
  case 14:
    oam_meta_spr(0x16, 0x16, animate_meter14_data);
    break;
  case 13:
    oam_meta_spr(0x16, 0x16, animate_meter13_data);
    break;
  case 12:
    oam_meta_spr(0x16, 0x16, animate_meter12_data);
    break;
  case 11:
    oam_meta_spr(0x16, 0x16, animate_meter11_data);
    break;
  case 10:
    oam_meta_spr(0x16, 0x16, animate_meter10_data);
    break;
  case 9:
    oam_meta_spr(0x16, 0x16, animate_meter9_data);
    break;
  case 8:
    oam_meta_spr(0x16, 0x16, animate_meter8_data);
    break;
  case 7:
    oam_meta_spr(0x16, 0x16, animate_meter7_data);
    break;
  case 6:
    oam_meta_spr(0x16, 0x16, animate_meter6_data);
    break;
  case 5:
    oam_meta_spr(0x16, 0x16, animate_meter5_data);
    break;
  case 4:
    oam_meta_spr(0x16, 0x16, animate_meter4_data);
    break;
  case 3:
    oam_meta_spr(0x16, 0x16, animate_meter3_data);
    break;
  case 2:
    oam_meta_spr(0x16, 0x16, animate_meter2_data);
    break;
  case 1:
    oam_meta_spr(0x16, 0x16, animate_meter1_data);
    break;
  default:
    oam_meta_spr(0x16, 0x16, animate_meter0_data);
    break;
  }
}

void draw_player_sprites()
{

  draw_player_health_meter();

  // player stuff
  temp_x = BoxGuy1.x >> 8;
  temp_y = BoxGuy1.y >> 8;
  if (temp_x == 0)
    temp_x = 1;
  if (temp_y == 0)
    temp_y = 1;
  //

  ++sprite_frame_counter;

  if (player_in_hitstun)
  {
    player_in_hitstun--;
    if (direction == LEFT)
    {
      oam_meta_spr(temp_x, temp_y, animate_recoilleft_data);
    }
    else
    {
      oam_meta_spr(temp_x, temp_y, animate_recoilright_data);
    }
    return;
  }

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
    if (player_on_ladder)
    {
      if (BoxGuy1.vel_y != 0)
      {
        if (sprite_frame_counter < 10)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerclimb1_data);
          return;
        }
        else if (sprite_frame_counter < 20)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerclimb2_data);
          return;
        }
        else if (sprite_frame_counter < 30)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerclimb3_data);
          return;
        }
        else if (sprite_frame_counter < 40)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerclimb2_data);
          return;
        }
        if (sprite_frame_counter < 50)
        {
          oam_meta_spr(temp_x, temp_y, animate_playerclimb1_data);
          return;
        }
        else
        {
          sprite_frame_counter = 0;
          oam_meta_spr(temp_x, temp_y, animate_playerclimb1_data);
          return;
        }
      }
      else
      {
        oam_meta_spr(temp_x, temp_y, animate_playerclimb1_data);
        return;
      }
    }
    else if (player_in_air) // aka, falling
    {                       // jumping
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