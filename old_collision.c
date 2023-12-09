#define COL_DOWN 0x80
#define COL_ALL 0x40
#define COL_LADDER 0x20

const unsigned char is_solid[] = {
    COL_DOWN,
    COL_DOWN,
    COL_ALL + COL_DOWN,
    COL_DOWN,
    COL_DOWN,
    COL_DOWN,
    COL_DOWN,
    COL_DOWN,
    COL_DOWN,
    COL_DOWN, // 9
    COL_DOWN,
    COL_DOWN,
    COL_DOWN,
    COL_DOWN,
    COL_DOWN,
    COL_DOWN,
    0,
    0,
    0,
    0, // 19
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0, // 29
    0,
    0,
    COL_LADDER, // 32
    0,
    0,
    0,
    0,
    0,
    0,
};

char bg_coll_L(void)
{
  // check 2 points on the left side
  temp5 = Generic.x + scroll_x;
  temp_x = (char)temp5;   // low byte
  temp_room = temp5 >> 8; // high byte

  eject_L = temp_x | 0xf0;
  temp_y = Generic.y + 2;
  if (bg_collision_sub())
    return 1;

  temp_y = Generic.y + Generic.height;
  temp_y -= 2;
  if (bg_collision_sub())
    return 1;

  return 0;
}

char bg_coll_R(void)
{
  // check 2 points on the right side
  temp5 = Generic.x + scroll_x + Generic.width;
  temp_x = (char)temp5;   // low byte
  temp_room = temp5 >> 8; // high byte

  eject_R = (temp_x + 1) & 0x0f;
  temp_y = Generic.y + 2;
  if (bg_collision_sub())
    return 1;

  temp_y = Generic.y + Generic.height;
  temp_y -= 2;
  if (bg_collision_sub())
    return 1;

  return 0;
}

char bg_coll_U(void)
{
  // check 2 points on the top side
  temp5 = Generic.x + scroll_x;
  temp5 += 2;
  temp_x = (char)temp5;   // low byte
  temp_room = temp5 >> 8; // high byte

  temp_y = Generic.y;
  eject_U = temp_y | 0xf0;
  if (bg_collision_sub())
    return 1;

  temp5 = Generic.x + scroll_x + Generic.width;
  temp5 -= 2;
  temp_x = (char)temp5;   // low byte
  temp_room = temp5 >> 8; // high byte

  if (bg_collision_sub())
    return 1;

  return 0;
}

char bg_coll_D(void)
{
  // check 2 points on the bottom side
  temp5 = Generic.x + scroll_x;
  temp5 += 2;
  temp_x = (char)temp5;   // low byte
  temp_room = temp5 >> 8; // high byte

  temp_y = Generic.y + Generic.height;

  if ((temp_y & 0x0f) > 3)
    return 0; // bug fix
  // so we don't snap to those platforms
  // don't fall too fast, or might miss it.

  eject_D = (temp_y + 1) & 0x0f;

  if (bg_collision_sub())
    return 1;

  temp5 = Generic.x + scroll_x + Generic.width;
  temp5 -= 2;
  temp_x = (char)temp5;   // low byte
  temp_room = temp5 >> 8; // high byte

  if (bg_collision_sub())
    return 1;

  return 0;
}

char bg_coll_D2(void)
{
  // check 2 points on the bottom side
  // a little lower, for jumping
  temp5 = Generic.x + scroll_x;
  temp5 += 2;
  temp_x = (char)temp5;   // low byte
  temp_room = temp5 >> 8; // high byte

  temp_y = Generic.y + Generic.height;
  temp_y += 2;
  temp6 = bg_collision_sub();
  if (temp6)
  {
    return temp6;
  }

  temp5 = Generic.x + scroll_x + Generic.width;
  temp5 -= 2;
  temp_x = (char)temp5;   // low byte
  temp_room = temp5 >> 8; // high byte

  temp6 = bg_collision_sub();
  return temp6;
}

char bg_collision_sub(void)
{
  // debug:
  // return 0;

  if (temp_y >= 0xf0)
    return 0;

  coordinates = (temp_x >> 4) + (temp_y & 0xf0);
  // we just need 4 bits each from x and y

  map = temp_room & 1; // high byte
  if (!map)
  {
    collision = c_map[coordinates];
  }
  else
  {
    collision = c_map2[coordinates];
  }

  return is_solid[collision];
}