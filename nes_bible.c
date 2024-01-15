/*	Unnamed NES BIBLE Game

	An attempt at making the best Bible game for the NES
	By BrianAndAlanGames

	Based off work by NESDoug
 */

/*
TODO List:

	[] fix the scrolling (1st screen glitch)
	[] enemy collision with ground (not just walls)
	[] enemies colide with each other
	[] reeling animation / hitstun action for player
	[] reeling animation / hitstun action for enemies
	[] ladder climbing
	[] full level
	[] change death to be a certain collision, not just over screen edge?
	[/] game modes
*/

#include "LIB/neslib.h"
#include "LIB/nesdoug.h"
#include "Sprites.h" // holds our metasprite data
#include "nes_bible.h"
#include "collision.c"
#include "player_sprites.c"

void main(void)
{
	// test

	reset();

	while (1)
	{
		while (game_mode == MODE_TITLE)
		{
			// unused for title screen
			ppu_wait_nmi();

			pad1 = pad_poll(0); // read the first controller
			pad1_new = get_pad_new(0);
			if (pad1_new & PAD_START)
			{
				pal_fade_to(4, 0); // fade to black
				ppu_off();
				// load game mode
				game_mode = MODE_GAME;
				// song = SONG_GAME;
				// music_play(song); //no music yet
				ppu_on_all();
				pal_bright(4); // back to normal brightness
			}
		}
		while (game_mode == MODE_GAME)
		{
			gray_line();
			++frame_counter;
			// infinite loop
			ppu_wait_nmi(); // wait till beginning of the frame

			pad1 = pad_poll(0); // read the first controller
			pad1_new = get_pad_new(0);

			if (pad1_new & PAD_START)
			{
				game_mode = MODE_PAUSE;
				// song = SONG_PAUSE;
				// music_play(song);
				// color_emphasis(0x01);
				ppu_mask(0b00011001); // grayscale mode

				break; // out of the game loop
			}

			movement();
			check_spr_objects();
			projectile_movement();

			set_scroll_x(scroll_x);
			set_scroll_y(scroll_y);

			handle_scrolling();

			draw_sprites();

			if (level_up)
			{
				pal_fade_to(4, 0); // fade to black
				game_mode = MODE_SWITCH;
				level_up = 0;
				room = 0;
				scroll_x = 0;
				++level;
				ppu_off();
			}
			else if (death)
			{
				pal_fade_to(4, 0); // fade to black
				reset();
			}
		}
		while (game_mode == MODE_PAUSE)
		{
			ppu_wait_nmi();

			pad1 = pad_poll(0); // read the first controller
			pad1_new = get_pad_new(0);

			// draw_sprites();

			if (pad1_new & PAD_START)
			{
				game_mode = MODE_GAME;
				// song = SONG_GAME;
				// music_play(song);
				// color_emphasis(COL_EMP_NORMAL);
				ppu_mask(0b00011000); // grayscale mode
			}
		}
		while (game_mode == MODE_SWITCH)
		{
			ppu_wait_nmi();
			++bright_count;
			if (bright_count >= 0x10)
			{ // fade out
				bright_count = 0;
				--bright;
				if (bright != 0xff)
					pal_bright(bright); // fade out
			}
			set_scroll_x(scroll_x);

			if (bright == 0xff)
			{ // now switch rooms
				ppu_off();
				oam_clear();
				scroll_x = 0;
				set_scroll_x(scroll_x);
				if (level < 9)
				{
					load_room();
					game_mode = MODE_GAME;
					ppu_on_all();
					pal_bright(4); // back to normal brighness
					BoxGuy1.x = 0x4000;
					BoxGuy1.y = 0x2400;
				}
			}
		}
	}
}

void reset(void)
{
	ppu_wait_nmi();
	ppu_off();		 // screen off
	pal_bright(4); // back to normal brightness
	scroll_x = 0;
	scroll_y = 0;
	room = 0;
	map_loaded = 0;
	player_in_air = 0;
	player_on_ladder = 0;
	player_jumping = 0;
	short_jump_count = 0;
	projectile_cooldown = 0;
	projectile_count = 0;
	projectile_index = 0;
	player_shooting = 0;
	direction = 1;
	frame_counter = 0;
	sprite_frame_counter = 0;
	r_scroll_frames = 0;
	l_scroll_frames = 0;
	collision = 0;
	player_shooting = 0;
	death = 0;
	BoxGuy1.x = 0x4000;
	BoxGuy1.y = 0x8400;
	BoxGuy1.health = 28;
	invul_frames = 0;
	game_mode = MODE_GAME;
	level = 0;

	// clear all projectiles
	for (temp1 = 0; temp1 < MAX_PROJECTILES; ++temp1)
	{
		projectiles_list[temp1] = OFF;
	}

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
}

void projectile_movement(void)
{
	for (temp1 = 0; temp1 < 3; ++temp1)
	{
		if (projectiles_list[temp1] != TURN_OFF)
		{
			if (projectiles_x[temp1] > 250)
			{
				projectiles_list[temp1] = TURN_OFF;
			}
			else
			{

				temp2 = 2; // projectile speed

				if (projectiles_list[temp1] == RIGHT)
				{

					// TODO, i think this doesn't get called.
					if (BoxGuy1.x > (MAX_RIGHT - 4) && pad1_new & PAD_RIGHT)
					{
						// max scroll change
						temp3 = (BoxGuy1.x - MAX_RIGHT - 4) >> 8;
						if (temp3 > 3)
							temp3 = 3; // max scroll change
						temp2 += temp3;
					}
					if (BoxGuy1.x < (MAX_LEFT + 4) && pad1_new & PAD_LEFT)
					{
						temp3 = (MAX_LEFT + 4 - BoxGuy1.x) >> 8;
						if (temp3 > 3)
							temp3 = 3;

						temp2 += temp3;
					}

					projectiles_x[temp1] += temp2;
				}
				else if (projectiles_list[temp1] == LEFT)
				{
					if (BoxGuy1.x > (MAX_RIGHT - 4) && pad1_new & PAD_RIGHT)
					{
						temp2 += 3;
					}
					if (BoxGuy1.x < (MAX_LEFT + 4) && pad1_new & PAD_LEFT)
					{
						temp2 -= 1;
					}

					projectiles_x[temp1] -= temp2;
				}
			}
		}
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
	offset = Level_offsets[level];
	offset += room;
	set_data_pointer(stage1_levels_list[offset]);
	set_mt_pointer(metatile);
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
	set_data_pointer(stage1_levels_list[offset + 1]);
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
	memcpy(c_map, stage1_levels_list[offset], 240);
	temp_cmap1 = 0;

	// init the max_room and max_scroll
	max_rooms = Level_max_rooms[level] - 1;
	max_scroll = (max_rooms * 0x100) - 1;

	sprite_obj_init();
}

void draw_sprites(void)
{
	// clear all sprites from sprite buffer
	oam_clear();

	draw_player_sprites();

	// draw projectiles
	for (temp1 = 0; temp1 < MAX_PROJECTILES; ++temp1)
	{
		if (projectiles_list[temp1] != OFF)
		{
			temp6 = projectiles_y[temp1]; //+ sine_wave[frame_counter % 10];
			oam_meta_spr(projectiles_x[temp1], temp6, animate_orb0_data);
		}
	}

	// draw enemy sprites
	offset = get_frame_count() & 3;
	offset = offset << 4; // * 16, the size of the shuffle array
	for (index = 0; index < MAX_ENEMY; ++index)
	{
		index2 = shuffle_array[offset];
		++offset;
		temp_y = enemy_y[index2];
		if (enemy_health[index2] == 0)
			continue;
		if (temp_y == TURN_OFF)
			continue;
		if (!enemy_active[index2])
			continue;
		temp_x = enemy_x[index2];
		if (temp_x == 0)
			temp_x = 1; // problems with x = 0
		if (temp_x > 0xf0)
			continue;
		if (temp_y < 0xf0)
		{
			oam_meta_spr(temp_x, temp_y, enemy_anim[index2]);
		}
	}

	debug = 1;
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

	if (player_in_hitstun > 0)
	{
		if (direction == LEFT)
		{
			BoxGuy1.vel_x += DECEL;
		}
		else
		{
			BoxGuy1.vel_x -= DECEL;
		}
	}

	// handle x

	old_x = BoxGuy1.x;

	if (pad1 & PAD_LEFT && !player_in_hitstun)
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
	else if (pad1 & PAD_RIGHT && !player_in_hitstun)
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

	if (BoxGuy1.y > 0xf000)
	{
		++level_up;
	}

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
	if (player_on_ladder && bg_coll_ladder())
	{
		if (pad1 & PAD_DOWN)
		{
			BoxGuy1.vel_y += ACCEL;
			if (BoxGuy1.vel_y > MAX_LADDER_SPEED)
			{
				BoxGuy1.vel_y = MAX_LADDER_SPEED;
			}
		}
		else if (pad1 & PAD_UP)
		{
			BoxGuy1.vel_y -= ACCEL;
			if (BoxGuy1.vel_y < -MAX_LADDER_SPEED)
			{
				BoxGuy1.vel_y = -MAX_LADDER_SPEED;
			}
		}
		else
		{
			BoxGuy1.vel_y = 0;
		}
	}
	else
	{
		player_on_ladder = 0;
		if (BoxGuy1.vel_y < 0x300)
		{

			if (BoxGuy1.vel_y < 0)
			{
				player_jumping = 1;
			}
			else
			{
				player_jumping = 0;
			}
			BoxGuy1.vel_y += GRAVITY;
		}
		else
		{
			BoxGuy1.vel_y = 0x300; // consistent
		}
	}
	BoxGuy1.y += BoxGuy1.vel_y; // add gravity to y; (make him go up or down)

	Generic.x = high_byte(BoxGuy1.x);
	Generic.y = high_byte(BoxGuy1.y);

	if (BoxGuy1.vel_y > 0) // he's falling
	{
		// player_in_air = 1;
		if (bg_coll_D()) // if he's collising below
		{								 // check collision below
			player_in_air = 0;
			player_on_ladder = 0;
			high_byte(BoxGuy1.y) = high_byte(BoxGuy1.y) - eject_D;
			BoxGuy1.y &= 0xff00;
			if (BoxGuy1.vel_y > 0)
			{
				BoxGuy1.vel_y = 0;
			}
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

	if (projectile_cooldown > 0)
	{
		--projectile_cooldown;
	}

	if (pad1_new & PAD_UP)
	{
		if (bg_coll_ladder())
		{
			player_on_ladder = 1;
			BoxGuy1.vel_y = 0;
			BoxGuy1.vel_x = 0;
		}
	}

	if (pad1_new & PAD_A)
	{
		if (bg_coll_D2())
		{
			BoxGuy1.vel_y = JUMP_VEL; // JUMP
			// sfx_play(SFX_JUMP, 0);
			short_jump_count = 1;
			player_in_air = 1;
			player_jumping = 1;
		}
	}
	if (pad1_new & PAD_B && projectile_cooldown == 0) // shooting
	{

		// check if there's an empty shot spot
		for (temp1 = 0; temp1 < MAX_PROJECTILES; ++temp1)
		{
			if (projectiles_list[temp1] == OFF)
			{
				temp2 = 1;
				break;
			}
		}
		if (temp2)
		{
			projectile_cooldown = PROJECTILE_COOLDOWN_FRAMES;
			player_shooting = 1;
			projectile_index = temp1;

			// if player is facing right:
			if (direction == RIGHT)
			{
				projectiles_list[projectile_index] = RIGHT;
			}
			else
			{
				projectiles_list[projectile_index] = LEFT;
			}

			projectiles_x[projectile_index] = high_byte(BoxGuy1.x) + 10;
			projectiles_y[projectile_index] = high_byte(BoxGuy1.y) - 8;
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

		// temp5 is the NEXT x location.
		// if (room == 0)
		// {
		// 	if (scroll_x > 0)
		// 	{
		// 		temp1 = (MAX_LEFT - BoxGuy1.x) >> 8;
		// 		if (temp1 > 3)
		// 			temp1 = 3; // max scroll change
		// 		if (scroll_x < 3)
		// 		{
		// 			temp1 = scroll_x;
		// 		}
		// 		if (max_rooms > 1)
		// 		{
		// 			scroll_x -= temp1;																	 // scroll the window
		// 			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) + temp1; // add the offset to the guy
		// 		}
		// 	}
		// 	else
		// 	{
		// 		BoxGuy1.x = temp5;
		// 	}
		// }

		// I think there's some overflow here. gotta make sure scroll_x doesn't go bonkers.
		temp1 = (MAX_LEFT - BoxGuy1.x) >> 8;
		if (temp1 > 3)
			temp1 = 3; // max scroll change
		if (max_rooms > 1 && room != 0)
		{
			scroll_x -= temp1;																	 // scroll the window
			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) + temp1; // add the offset to the guy
		}
	}

	if (BoxGuy1.x > MAX_RIGHT)
	{
		if (!map_loaded) // gets reset whenever the player's in the middle of the level
		{

			room = ((scroll_x >> 8) + 1); // high byte = room, one to the right
			new_cmap();
			map_loaded = 1; // only do once
		}
		// if (room <= Level_max_rooms[level])
		// {
		temp1 = (BoxGuy1.x - MAX_RIGHT) >> 8;
		if (temp1 > 3)
			temp1 = 3; // max scroll change
		if (max_rooms > 1)
		{
			scroll_x += temp1;																	 // scroll the window
			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) - temp1; // sub the offet from the guy
		}
		// }
	}

	if (scroll_x >= max_scroll)
	{
		scroll_x = max_scroll;						// stop scrolling right, end of level
		BoxGuy1.x = temp5;								// but allow the x position to go all the way right
		if (high_byte(BoxGuy1.x) >= 0xe0) // but limit how far right he can go
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

	offset = Level_offsets[level];
	offset += temp1; // in place of room?!?

	set_data_pointer(stage1_levels_list[offset]);
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

	// TODO might need to put in offset here?
	temp1 = pseudo_scroll_x >> 8;

	offset = Level_offsets[level];
	offset += temp1; // in place of room?!?

	set_data_pointer(stage1_levels_list[offset]);
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

	offset = Level_offsets[level];
	offset += room;

	map = room & 1; // even or odd?
	if (!map)
	{
		memcpy(c_map, stage1_levels_list[offset], 240);
		temp_cmap1 = room;
	}
	else
	{
		memcpy(c_map2, stage1_levels_list[offset], 240);
		temp_cmap2 = room;
	}
}

char get_position(void)
{
	// is it in range ? return 1 if yes

	temp5 -= scroll_x;
	temp_x = temp5 & 0xff;
	if (high_byte(temp5))
		return 0;
	return 1;
}

void check_spr_objects(void)
{
	++enemy_frames;
	Generic2.x = high_byte(BoxGuy1.x);
	// mark each object "active" if they are, and get the screen x

	for (index = 0; index < MAX_ENEMY; ++index)
	{
		enemy_active[index] = 0; // default to zero
		if (enemy_y[index] != TURN_OFF)
		{
			high_byte(temp5) = enemy_room[index];
			low_byte(temp5) = enemy_actual_x[index];
			temp1 = enemy_active[index] = get_position();
			if (temp1 == 0 || enemy_health[index] == 0)
				continue;
			enemy_x[index] = temp_x; // screen x coords

			enemy_moves(); // if active, do it's moves now
		}
	}
}

void enemy_moves(void)
{
	if (invul_frames > 0)
	{
		--invul_frames;
	}
	// if enemy and player are touching, reduce health
	if (enemy_x[index] == Generic2.x && invul_frames == 0)
	{
		--BoxGuy1.health;
		player_in_hitstun = 15;
		invul_frames = 30;
		if (BoxGuy1.health == 0)
		{
			death = 1;
		}
	}

	// check enemy collision with projectiles
	for (temp1 = 0; temp1 < MAX_PROJECTILES; ++temp1)
	{
		if (projectiles_list[temp1] != TURN_OFF)
		{
			if (
					(enemy_x[index] > projectiles_x[temp1] - 5 && enemy_x[index] < projectiles_x[temp1] + 5) &&
					(enemy_y[index] > projectiles_y[temp1] - 30 && enemy_y[index] < projectiles_y[temp1] + 30))
			{
				projectiles_list[temp1] = TURN_OFF;
				--enemy_health[index];
			}
		}
	}

	if (enemy_type[index] == ENEMY_SNAIL)
	{
		// for bg collisions
		Generic.x = enemy_x[index];
		Generic.y = enemy_y[index] + 6; // mid point
		Generic.width = 13;
		Generic.height = 15;

		// note, Generic2 is the hero's x position

		if (enemy_frames < 10)
		{
			enemy_anim[index] = animate_snail1left_data;
		}
		else if (enemy_frames < 20)
		{
			enemy_anim[index] = animate_snail2left_data;
		}
		else if (enemy_frames < 30)
		{
			enemy_anim[index] = animate_snail3left_data;
		}
		else
		{
			enemy_anim[index] = animate_snail3left_data;
			enemy_frames = 0;
		}
		if (frame_counter % 3 == 0)
		{

			if (enemy_x[index] > Generic2.x)
			{

				Generic.x -= 1;

				Generic.x -= 1; // test going left
				bg_collision_fast();
				if (collision_L)
					return;
				// else, no collision, do the move.
				if (enemy_actual_x[index] == 0)
					--enemy_room[index];
				--enemy_actual_x[index];
			}
			else if (enemy_x[index] < Generic2.x)
			{

				Generic.x += 1; // test going right

				bg_collision_fast();
				if (collision_R)
					return;
				++enemy_actual_x[index];
				if (enemy_actual_x[index] == 0)
					++enemy_room[index];
			}
		}
	}
}

// cc65 is very slow if 2 arrays/pointers are on the same line, so I
// broke them into 2 separate lines with temp1 as a passing variable
void sprite_obj_init(void)
{

	pointer = Enemy_list[level];
	for (index = 0, index2 = 0; index < MAX_ENEMY; ++index)
	{

		enemy_x[index] = 0;

		temp1 = pointer[index2]; // get a byte of data
		enemy_y[index] = temp1;

		if (temp1 == TURN_OFF)
			break;

		++index2;

		enemy_active[index] = 0;

		temp1 = pointer[index2]; // get a byte of data
		enemy_room[index] = temp1;

		++index2;

		temp1 = pointer[index2]; // get a byte of data
		enemy_actual_x[index] = temp1;

		++index2;

		temp1 = pointer[index2]; // get a byte of data
		enemy_health[index] = temp1;

		++index2;

		temp1 = pointer[index2]; // get a byte of data
		enemy_type[index] = temp1;

		++index2;
	}

	for (++index; index < MAX_ENEMY; ++index)
	{
		enemy_y[index] = TURN_OFF;
	}
}
