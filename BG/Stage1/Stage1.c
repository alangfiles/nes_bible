
#include "Leveltng.c"
#include "Leveltng2.c"
#include "Leveltng3.c"
#include "Leveltng4.c"
#include "Leveltng5.c"
#include "Leveltng6.c"
#include "Leveltng7.c"

const unsigned char *const stage1_levels_list[] = {
    LEVELTNG_0, LEVELTNG_1, LEVELTNG_2, LEVELTNG_3, LEVELTNG_4, LEVELTNG_5, LEVELTNG_6, LEVELTNG_7, LEVELTNG_8, LEVELTNG_9, LEVELTNG_10,
    Leveltng2_0,
    Leveltng3_0, Leveltng3_1, Leveltng3_2, Leveltng3_3,
    Leveltng4_0,
    Leveltng5_0, Leveltng5_1, Leveltng5_2, Leveltng5_3, Leveltng5_4,
    Leveltng6_0,
    Leveltng7_0};

const unsigned char Level_offsets[] = {
    0, 12, 13, 17, 18, 23, 24, 25};

enum
{
    ENEMY_SNAIL,
    ENEMY_OWL,
    ENEMY_SNAKE
};

// NOTE MAX_ENEMY = 10

// NOTE, after testing, we can only handle 4 enemies on the same screen

// y, room, x, health, type,
// y = TURN_OFF end of list
const unsigned char stage_1_enemies[] = {

    0xc0, 1, 0xc0, 2, ENEMY_SNAIL,
    0x80, 2, 0xe0, 2, ENEMY_SNAIL,
    0x80, 3, 0x30, 2, ENEMY_SNAIL,
    TURN_OFF};

// list of transitions to the next room for vertical transitions
// y, room, x,
const unsigned char stage_1_transitions[] = {

    0xc0, 11, 0xc0,
    TURN_OFF};
