#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <tetris.h>

#define HEIGHT 20;
#define WIDTH 10;

Game *game_state = NULL;

Game *game_init() {
  puts("initializing game...");
  // only one instance permitted per game
  if (game_state) {
    game_free();
  }

  game_state = malloc(sizeof(Game));

  if (game_state == NULL)
    return NULL;

  game_state->width = WIDTH;
  game_state->height = HEIGHT;
  game_state->board =
      calloc(game_state->width * game_state->height, sizeof(color));
  game_state->queue = NULL;
  game_state->store = NONE;

  return game_state;
}

void game_free() {
  puts("freeing game...");
  if (game_state == NULL)
    return;

  free(game_state->queue);
  free(game_state->board);

  free(game_state);
  game_state = NULL;
}

void game_tick() {}

void game_move_left() {}

void game_move_right() {}

void game_rotate_cw() {}

void game_rotate_ccw() {}

void game_drop() {}

void game_fast_drop() {}

void game_store() {}
