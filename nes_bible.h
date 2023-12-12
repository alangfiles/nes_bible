#define ACCEL 30
#define DECEL 50
#define OFF 0xff

#define COL_DOWN 0x80
#define COL_ALL 0x40
#define COL_LADDER 0x01


#define GRAVITY 0x3c
#define MAX_SPEED 0x240
#define JUMP_VEL -0x600
#define MAX_RIGHT 0x9000
#define MAX_LEFT 0x4000

#define MAX_PROJECTILES 3
#define PROJECTILE_COOLDOWN_FRAMES 10

#pragma bss-name(push, "ZEROPAGE")

// GLOBAL VARIABLES
unsigned char debug;
unsigned char pad1;
unsigned char pad1_new;
unsigned char short_jump_count;
unsigned char map_loaded;
unsigned char collision;
unsigned char player_jumping;
unsigned char collision_L;
unsigned char collision_R;
unsigned char collision_U;
unsigned char collision_D;
unsigned char coordinates;
unsigned char temp1;
unsigned char temp2;
unsigned char temp3;
unsigned char temp4;
unsigned int temp5;
unsigned int temp6;
unsigned int temp_playerlocation;
unsigned char temp_cmap1;
unsigned char temp_cmap2;
unsigned char eject_L;			 // from the left
unsigned char eject_R;			 // remember these from the collision sub routine
unsigned char eject_D;			 // from below
unsigned char eject_U;			 // from up
unsigned char direction = 1; // facing left or right?
unsigned char sprite_frame_counter;
unsigned char frame_counter;
#define LEFT 0
#define RIGHT 1

int address;
unsigned char x; // room loader code
unsigned char y;
unsigned char nt;
unsigned char index;
unsigned char room = 0;
unsigned char map;
unsigned int scroll_x;
unsigned int scroll_y;
unsigned char scroll_count;
unsigned int pseudo_scroll_x;
// unsigned int pseudo_scroll_y;
// unsigned char L_R_switch;
unsigned char l_scroll_frames;
unsigned char r_scroll_frames;
unsigned int old_x;
unsigned int old_y;
unsigned char temp_x;
unsigned char temp_y;
unsigned char temp_room;
unsigned char player_shooting;
unsigned char projectile_cooldown;
unsigned char projectile_count;
unsigned char projectile_index;
unsigned char projectiles_list[] = {OFF, OFF, OFF, OFF};
unsigned char projectiles_x[] = {0, 0, 0, 0};
unsigned char projectiles_y[] = {0, 0, 0, 0};

unsigned char sine_wave[] = {5,8,10,10,8,5,2,0,0,2};

#pragma bss-name(push, "BSS")

unsigned char c_map[240];
unsigned char c_map2[240]; // not used in this example

struct Base
{
	unsigned char x;
	unsigned char y;
	unsigned char width;
	unsigned char height;
};

struct Base Generic;

struct Hero
{
	unsigned int x; // low byte is sub-pixel
	unsigned int y;
	signed int vel_x; // speed, signed, low byte is sub-pixel
	signed int vel_y;
};

struct Hero BoxGuy1 = {0x4000, 0x8400}; // starting position
// the width and height should be 1 less than the dimensions (14x14)
// note, I'm using the top left as the 0,0 on x,y

#define HERO_WIDTH 19
#define HERO_HEIGHT 14

#define MAX_ROOMS (20-1)
#define MAX_SCROLL (MAX_ROOMS * 0x100)-1
#define MIN_SCROLL 0x0000
// data is exactly 240 bytes, 16 * 15
// doubles as the collision map data

const unsigned char palette_bg[] = {
		0x21, 0x10, 0x00, 0x0f, 0x21, 0x0f, 0x1a, 0x2a, 0x21, 0x0f, 0x16, 0x27, 0x21, 0x30, 0x27, 0x2a};

const unsigned char palette_sp[] = {
		0x0f, 0x06, 0x24, 0x36,
		0x0f, 0x21, 0x2a, 0x1a,
		0x0f, 0x20, 0x21, 0x26,
		0x0f, 0x21, 0x20, 0x10};

// 5 bytes per metatile definition, tile TL, TR, BL, BR, palette 0-3
// T means top, B means bottom, L left,R right
// 51 maximum # of metatiles = 255 bytes

/*const unsigned char metatiles1[]={
	2, 2, 2, 2,  3,
	4, 4, 4, 4,  1,
	9, 9, 9, 9,  2,
	5, 6, 8, 7,  1,
	5, 6, 8, 7,  0
};*/
// moved to this file...
#include "NES_ST/metatiles1.h"

#include "BG/busylevel.c"
// data is exactly 240 bytes, 16 * 15
// doubles as the collision map data

// PROTOTYPES
void load_room(void);
void draw_sprites(void);
void movement(void);
char bg_collision_sub(void);
void draw_screen_R(void);
void draw_screen_L(void);
void new_cmap(void);
void handle_scrolling(void);
void projectile_movement(void);

char bg_coll_L(void);
char bg_coll_R(void);
char bg_coll_U(void);
char bg_coll_D(void);
char bg_coll_D2(void);
