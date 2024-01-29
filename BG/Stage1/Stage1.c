
#include "Leveltng.c"
#include "Leveltng2.c"
#include "Leveltng3.c"
#include "Leveltng4.c"
#include "Leveltng5.c"
#include "Leveltng6.c"
#include "Leveltng7.c"

const unsigned char *const stage1_levels_list[] = {
    leveltng_0, leveltng_1, leveltng_2, leveltng_3, leveltng_4, leveltng_5, leveltng_6, leveltng_7, leveltng_8, leveltng_9, leveltng_10,
    leveltng2_0,
    leveltng3_0, leveltng3_1, leveltng3_2, leveltng3_3,
    leveltng4_0,
    leveltng5_0, leveltng5_1, leveltng5_2, leveltng5_3, leveltng5_4,
    leveltng6_0,
    leveltng7_0};

const unsigned char level_max_rooms[] = {
    11, 1, 4, 1, 5, 1, 1};

const unsigned char level_offsets[] = {
    0, 11, 12, 16, 17, 22, 23, 24};

enum
{
    ENEMY_SNAIL,
    ENEMY_OWL,
    ENEMY_SNAKE,
    ENTITY_LEVEL_UP,
    ENTITY_PIT,
    ENTITY_LEVEL_DOWN
};

// NOTE MAX_ENEMY = 10

// NOTE, after testing, we can only handle 4 enemies on the same screen

// y, room, x, type,
// y = TURN_OFF end of list
const unsigned char level_1_enemies[] = {

    0xc0, 1, 0xc0, ENEMY_SNAIL,
    0x80, 2, 0xe0, ENEMY_SNAIL,
    0x80, 4, 0x30, ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_2_enemies[] = {
    TURN_OFF};
const unsigned char level_3_enemies[] = {
    TURN_OFF};
const unsigned char level_4_enemies[] = {
    TURN_OFF};
const unsigned char level_5_enemies[] = {
    TURN_OFF};
const unsigned char level_6_enemies[] = {
    TURN_OFF};
const unsigned char level_7_enemies[] = {
    TURN_OFF};

const unsigned char *const Enemy_list[] = {
    level_1_enemies, level_2_enemies, level_3_enemies,
    level_4_enemies, level_5_enemies, level_6_enemies,
    level_7_enemies};

const unsigned char level_1_entities[] = {
    0x00, 11, 0x10, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_2_entities[] = {
    TURN_OFF};
const unsigned char level_3_entities[] = {
    0xB0, 3, 0xE0, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_4_entities[] = {
    TURN_OFF};
const unsigned char level_5_entities[] = {
    TURN_OFF};
const unsigned char level_6_entities[] = {
    TURN_OFF};
const unsigned char level_7_entities[] = {
    TURN_OFF};

const unsigned char *const entity_list[] = {
    level_1_entities, level_2_entities, level_3_entities,
    level_4_entities, level_5_entities, level_6_entities,
    level_7_entities};
