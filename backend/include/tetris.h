#pragma once

#include <colors.h>
#include <stddef.h>

#define HEIGHT 20;
#define WIDTH 10;

#define STORE_HEIGHT 4;
#define STORE_WIDTH 2;

typedef struct {
  colors *board; // the board. to access [x,y] -> board[x + y * WIDTH];
  colors *
      store; // the stored piece. to access [x,y] -> store[x + y * STORE_WIDTH];
  size_t x;
  size_t y;
} Game;

Game *game_init();

void game_tick();

void game_move_left();

void game_move_right();

void game_rotate_cw();

void game_rotate_ccw();

void game_drop();

void game_fast_drop();

void game_store();
