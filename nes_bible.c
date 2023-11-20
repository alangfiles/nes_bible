/*	example code for cc65, for NES
 *  draw a BG with metatile system
 *	, also sprite collisions with BG
 *  ...testing 256 metatiles (240 actually)
 *	using neslib
 *	Doug Fraker 2018
 */

#include "LIB/neslib.h"
#include "LIB/nesdoug.h"
#include "Sprites.h" // holds our metasprite data
#include "nes_bible.h"
#include "old_collision.c"

void main(void)
{
	// test

	ppu_off(); // screen off

	ppu_mask(0); // grayscale mode
	// load the palettes
	pal_bg(palette_bg);
	pal_spr(palette_sp);

	// use the second set of tiles for sprites
	// both bg and sprites are set to 0 by default
	bank_spr(0);
	bank_bg(1);

	set_vram_buffer(); // do at least once, sets a pointer to a buffer

	load_room();

	set_scroll_y(0xff); // shift the bg down 1 pixel

	ppu_on_all(); // turn on screen

	room = 0;

	while (1)
	{
		// infinite loop
		ppu_wait_nmi(); // wait till beginning of the frame

		pad1 = pad_poll(0); // read the first controller
		pad1_new = get_pad_new(0);

		movement();
		set_scroll_x(scroll_x);
		set_scroll_y(scroll_y);

		handle_scrolling();

		draw_sprites();
	}
}

void handle_scrolling(void)
{
	// how to do scrolling:
	// if the hero is facing right, put an attribute column in front of the current nametable window
	// (4 frames = 1 column of 4 metatiles = 1 attribute column)
	// if the hero is facing left, put an attribute column in behind the current nametable window

	// figure out if we're drawing to the right or left
	if (!r_scroll_frames && !l_scroll_frames)
	{
		if (direction == RIGHT)
		{
			r_scroll_frames = 4;
		}
		else
		{
			l_scroll_frames = 4;
		}
	}

	if (r_scroll_frames)
	{
		draw_screen_R();
		--r_scroll_frames;
	}
	else if (l_scroll_frames)
	{
		draw_screen_L();
		--l_scroll_frames;
	}
}

void load_room(void)
{
	set_data_pointer(busylevel_list[0]);
	set_mt_pointer(metatiles1);
	for (y = 0;; y += 0x20)
	{
		for (x = 0;; x += 0x20)
		{
			address = get_ppu_addr(0, x, y);
			index = (y & 0xf0) + (x >> 4);
			buffer_4_mt(address, index); // ppu_address, index to the data
			flush_vram_update2();
			if (x == 0xe0)
				break;
		}
		if (y == 0xe0)
			break;
	}

	// a little bit in the next room
	set_data_pointer(busylevel_list[1]);
	for (y = 0;; y += 0x20)
	{
		x = 0;
		address = get_ppu_addr(1, x, y);
		index = (y & 0xf0);
		buffer_4_mt(address, index); // ppu_address, index to the data
		flush_vram_update2();
		if (y == 0xe0)
			break;
	}

	// copy the room to the collision map
	// the second one should auto-load with the scrolling code
	memcpy(c_map, busylevel_0, 240);
	temp_cmap1 = 0;
}

void draw_sprites(void)
{
	// clear all sprites from sprite buffer
	oam_clear();

	temp_x = BoxGuy1.x >> 8;
	temp_y = BoxGuy1.y >> 8;
	if (temp_x == 0)
		temp_x = 1;
	if (temp_y == 0)
		temp_y = 1;
	//

	++sprite_frame_counter;

	if (player_jumping && BoxGuy1.vel_y > 0) // aka, falling
	{																				 // jumping
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

	if (debug)
	{
		// SCROLL_X SPRITES
		oam_spr(20, 010, 0x58, 1); // 0xfe = X
		temp1 = (scroll_x) >> 8;
		oam_spr(28, 010, temp1 + 0x30, 1);
		temp1 = (scroll_x & 0xff) >> 4;
		oam_spr(36, 010, temp1 + 0x30, 1);
		temp1 = (scroll_x & 0x0f);
		oam_spr(44, 010, temp1 + 0x30, 1);

		// CURRENT ROOM # SPRITE
		temp1 = room;
		// temp1 = (scroll_x) >> 8;	 // high byte of scroll_x
		oam_spr(58, 010, 0x52, 1); // 0xfd = R
		oam_spr(66, 010, temp1 + 0x30, 1);

		// PLAYER X LOCATION SPRITES
		oam_spr(20, 20, 0x58, 2); // 0xfe = X
		temp1 = (BoxGuy1.x >> 8 & 0xff) >> 4;
		oam_spr(28, 20, temp1 + 0x30, 2);
		temp1 = (BoxGuy1.x >> 8 & 0x0f);
		oam_spr(36, 20, temp1 + 0x30, 2);

		// PLAYER Y LOCATION SPRITES
		oam_spr(50, 20, 0xff, 2); // 0xff = Y
		oam_spr(58, 20, temp_cmap1 + 0x30, 2);
		oam_spr(80, 20, temp_cmap2 + 0x30, 2);
	}
}

void movement(void)
{

	// handle x

	old_x = BoxGuy1.x;

	if (pad1 & PAD_LEFT)
	{
		direction = LEFT;

		if (BoxGuy1.vel_x >= DECEL)
		{
			BoxGuy1.vel_x -= DECEL;
		}
		else if (BoxGuy1.vel_x > 0)
		{
			BoxGuy1.vel_x = 0;
		}
		else
		{
			BoxGuy1.vel_x -= ACCEL;
			if (BoxGuy1.vel_x < -MAX_SPEED)
				BoxGuy1.vel_x = -MAX_SPEED;
		}
	}
	else if (pad1 & PAD_RIGHT)
	{

		direction = RIGHT;

		if (BoxGuy1.vel_x <= DECEL)
		{
			BoxGuy1.vel_x += DECEL;
		}
		else if (BoxGuy1.vel_x < 0)
		{
			BoxGuy1.vel_x = 0;
		}
		else
		{
			BoxGuy1.vel_x += ACCEL;
			if (BoxGuy1.vel_x >= MAX_SPEED)
				BoxGuy1.vel_x = MAX_SPEED;
		}
	}
	else
	{ // nothing pressed
		if (BoxGuy1.vel_x >= ACCEL)
			BoxGuy1.vel_x -= ACCEL;
		else if (BoxGuy1.vel_x < -ACCEL)
			BoxGuy1.vel_x += ACCEL;
		else
			BoxGuy1.vel_x = 0;
	}

	BoxGuy1.x += BoxGuy1.vel_x;

	if (BoxGuy1.x > 0xf000)
	{ // too far, don't wrap around

		if (old_x >= 0x8000)
		{
			BoxGuy1.x = 0xf000; // max right
		}
		else
		{
			BoxGuy1.x = 0x0000; // max left
		}

		BoxGuy1.vel_x = 0;
	}

#pragma region Collision
	Generic.x = high_byte(BoxGuy1.x); // this is much faster than passing a pointer to BoxGuy1
	Generic.y = high_byte(BoxGuy1.y);
	Generic.width = HERO_WIDTH;
	Generic.height = HERO_HEIGHT;

	if (BoxGuy1.vel_x < 0)
	{
		if (bg_coll_L())
		{ // check collision left
			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) - eject_L;
			BoxGuy1.vel_x = 0;
			if (BoxGuy1.x > 0xf000)
			{
				// no wrap around
				BoxGuy1.x = 0xf000;
			}
		}
	}
	else if (BoxGuy1.vel_x > 0)
	{
		if (bg_coll_R())
		{ // check collision right
			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) - eject_R;
			BoxGuy1.vel_x = 0;
			if (BoxGuy1.x > 0xf000)
			{
				// no wrap around
				BoxGuy1.x = 0x0000;
			}
		}
	}
	// skip collision if vel = 0

	// handle y

	// gravity

	// BoxGuy1.vel_y is signed
	if (BoxGuy1.vel_y < 0x300)
	{
		BoxGuy1.vel_y += GRAVITY;
	}
	else
	{
		BoxGuy1.vel_y = 0x300; // consistent
	}
	BoxGuy1.y += BoxGuy1.vel_y;

	Generic.x = high_byte(BoxGuy1.x);
	Generic.y = high_byte(BoxGuy1.y);

	if (BoxGuy1.vel_y > 0)
	{
		if (bg_coll_D())
		{ // check collision below
			high_byte(BoxGuy1.y) = high_byte(BoxGuy1.y) - eject_D;
			BoxGuy1.y &= 0xff00;
			if (BoxGuy1.vel_y > 0)
			{
				BoxGuy1.vel_y = 0;
			}
			player_jumping = 0;
		}
	}
	else if (BoxGuy1.vel_y < 0)
	{
		if (bg_coll_U())
		{ // check collision above
			high_byte(BoxGuy1.y) = high_byte(BoxGuy1.y) - eject_U;
			BoxGuy1.vel_y = 0;
		}
	}

	// check collision down a little lower than hero
	Generic.y = high_byte(BoxGuy1.y); // the rest should be the same

	if (pad1_new & PAD_A)
	{
		if (bg_coll_D2())
		{
			BoxGuy1.vel_y = JUMP_VEL; // JUMP
			// sfx_play(SFX_JUMP, 0);
			short_jump_count = 1;
			player_jumping = 1;
		}
	}
	if (pad1_new & PAD_B)
	{
		if (debug)
		{
			debug = 0;
			ppu_off();
			ppu_mask(0);
			ppu_on_all();
		}
		else
		{
			debug = 1;
			ppu_wait_nmi();
			ppu_off();
			ppu_mask(1);
			ppu_on_all();
		}
	}

#pragma endregion

	// allow shorter jumps
	if (short_jump_count)
	{
		++short_jump_count;
		if (short_jump_count > 30)
			short_jump_count = 0;
	}
	if ((short_jump_count) && ((pad1 & PAD_A) == 0) && (BoxGuy1.vel_y < -0x200))
	{
		BoxGuy1.vel_y = -0x200;
		short_jump_count = 0;
	}

	// when the player is in the middle of the screen, reset the map loaded
	temp5 = low_byte(scroll_x) + high_byte(BoxGuy1.x);
	if (temp5 > 0x98 && temp5 < 0xa4) // middle of the screen
	{
		map_loaded = 0;
	}

	// scroll
	temp5 = BoxGuy1.x; // store his x before we check the scrolling

	if (BoxGuy1.x < MAX_LEFT)
	{

		if (!map_loaded)
		{
			if (room >= 1)
			{
				room = ((scroll_x >> 8) - 1); // high byte = room, one to the left
			}
			new_cmap();
			map_loaded = 1; // only do once
		}

		if (room == 0)
		{
			if (scroll_x > 0)
			{
				temp1 = (MAX_LEFT - BoxGuy1.x) >> 8;
				if (temp1 > 3)
					temp1 = 3; // max scroll change
				if (scroll_x < 3)
				{
					temp1 = scroll_x;
				}
				scroll_x -= temp1;																	 // scroll the window
				high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) + temp1; // add the offset to the guy
			}
			else
			{
				BoxGuy1.x = temp5;
			}
		}

		if (room >= 1)
		{
			// I think there's some overflow here. gotta make sure scroll_x doesn't go bonkers.
			temp1 = (MAX_LEFT - BoxGuy1.x) >> 8;
			if (temp1 > 3)
				temp1 = 3;																				 // max scroll change
			scroll_x -= temp1;																	 // scroll the window
			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) + temp1; // add the offset to the guy
		}
	}

	if (BoxGuy1.x > MAX_RIGHT)
	{
		if (!map_loaded)
		{

			room = ((scroll_x >> 8) + 1); // high byte = room, one to the right
			new_cmap();
			map_loaded = 1; // only do once
		}
		if (room <= MAX_ROOMS)
		{
			temp1 = (BoxGuy1.x - MAX_RIGHT) >> 8;
			if (temp1 > 3)
				temp1 = 3;																				 // max scroll change
			scroll_x += temp1;																	 // scroll the window
			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) - temp1; // sub the offet from the guy
		}
	}

	if (scroll_x >= MAX_SCROLL)
	{
		scroll_x = MAX_SCROLL; // stop scrolling right, end of level
		BoxGuy1.x = temp5;		 // but allow the x position to go all the way right
		if (high_byte(BoxGuy1.x) >= 0xe0)
		{
			BoxGuy1.x = 0xe000;
		}
	}
}

void draw_screen_L(void)
{
	// scrolling to the left, draw metatiles as we go
	pseudo_scroll_x = scroll_x - 0x20; // Modify the scroll offset for left scroll

	temp1 = pseudo_scroll_x >> 8;
	// if (temp1 > 0)
	// {
	// 	temp1 = temp1 - 1;
	// }

	set_data_pointer(busylevel_list[temp1]);
	nt = temp1 & 1;
	x = pseudo_scroll_x & 0xff;

	switch (scroll_count)
	{
	case 0:
		address = get_ppu_addr(nt, x, 0);
		index = 0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0x20);
		index = 0x20 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	case 1:
		address = get_ppu_addr(nt, x, 0x40);
		index = 0x40 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0x60);
		index = 0x60 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	case 2:
		address = get_ppu_addr(nt, x, 0x80);
		index = 0x80 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0xa0);
		index = 0xa0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	default:
		address = get_ppu_addr(nt, x, 0xc0);
		index = 0xc0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0xe0);
		index = 0xe0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
	}

	--scroll_count;		 // Reverse the increment to scroll in the opposite direction
	scroll_count &= 3; // mask off top bits, keep it 0-3
}

void draw_screen_R(void)
{
	// scrolling to the right, draw metatiles as we go
	pseudo_scroll_x = scroll_x + 0x120;

	temp1 = pseudo_scroll_x >> 8;

	set_data_pointer(busylevel_list[temp1]);
	nt = temp1 & 1;
	x = pseudo_scroll_x & 0xff;

	switch (scroll_count)
	{
	case 0:
		address = get_ppu_addr(nt, x, 0);
		index = 0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0x20);
		index = 0x20 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	case 1:
		address = get_ppu_addr(nt, x, 0x40);
		index = 0x40 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0x60);
		index = 0x60 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	case 2:
		address = get_ppu_addr(nt, x, 0x80);
		index = 0x80 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0xa0);
		index = 0xa0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	default:
		address = get_ppu_addr(nt, x, 0xc0);
		index = 0xc0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0xe0);
		index = 0xe0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
	}

	++scroll_count;
	scroll_count &= 3; // mask off top bits, keep it 0-3
}

// copy a new collision map to one of the 2 c_map arrays
void new_cmap(void)
{
	// ppu_off();
	// ppu_wait_nmi();
	// ppu_on_all();
	// todo: figure out which cmap we need
	//  if ((scroll_x & 0xff) < 4)
	//  {
	//  	new_cmap_r();
	//  }

	// if ((scroll_x & 0xff) > 0xfb)
	// {
	// 	new_cmap_l();
	// }

	// do we need to load a new collision map? (scrolled into a new room)
	// copy a new collision map to one of the 2 c_map arrays
	// room = ((scroll_x >> 8) + 1); // high byte = room, one to the right

	map = room & 1; // even or odd?
	if (!map)
	{
		memcpy(c_map, busylevel_list[room], 240);
		temp_cmap1 = room;
	}
	else
	{
		memcpy(c_map2, busylevel_list[room], 240);
		temp_cmap2 = room;
	}
}