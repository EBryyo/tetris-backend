#include "activepiece.h"
#include "colors.h"
#include <pieces.h>
#include <stdio.h>
#include <stdlib.h>
#include <tetris.h>
#include <time.h>

#define HEIGHT 20;
#define WIDTH 10;

Tetris *game_state = NULL;

color *board(int8_t x, int8_t y) {
  if (game_state == NULL || game_state->board == NULL) {
    perror("tried to access board before game state was initialized.");
  }

  return (color *)game_state->board + x + game_state->width * y;
}

void get_new_piece() {
  if (game_state == NULL) {
    perror("tried to modify active piece before game state was initialized.");
  }

  ActivePiece new_piece = {
      .direction = UP,
      .type = random_piece(), // TODO: fetch piece type from queue instead.
      .x = game_state->width / 2,
      .y = 0,
  };
  set_piece_blocks(&new_piece);

  game_state->active_piece = new_piece;
}

uint8_t validate_translation(int8_t x, int8_t y) { return 1; }

Tetris *game_init() {
  srand(time(NULL));
  puts("initializing game...");
  // only one instance permitted per game
  if (game_state) {
    game_free();
  }

  game_state = malloc(sizeof(Tetris));

  if (game_state == NULL)
    return NULL;

  game_state->width = WIDTH;
  game_state->height = HEIGHT;
  game_state->board =
      calloc(game_state->width * game_state->height, sizeof(color));
  game_state->can_store = 1;
  game_state->queue = NULL; // TODO: implement queue initialization
  game_state->store = NONE;

  for (size_t i = 0; i < game_state->width * game_state->height; i++) {
    game_state->board[i] = EMPTY;
  }

  get_new_piece();

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

void game_tick() {
  ActivePiece *active_piece = &game_state->active_piece;
  const pair *blocks = active_piece->blocks;

  int falls = 1;
  // determine if the piece should fall or be set in place
  for (size_t i = 0; i < 4; i++) {
    const pair block = blocks[i];
    int8_t x = block.x + active_piece->x;
    int8_t y = block.y + active_piece->y;
    if (x >= 0 && y >= 0 && x < game_state->width &&
        ((y + 1 < game_state->height && *board(x, y + 1) != EMPTY) ||
         y == game_state->height - 1)) {
      falls = 0;
      break;
    }
  }

  // drop piece by 1
  if (falls) {
    active_piece->y += 1;
    return;
  }

  // cement piece into board;
  for (size_t i = 0; i < 4; i++) {
    const pair block = blocks[i];
    int8_t x = block.x + active_piece->x;
    int8_t y = block.y + active_piece->y;
    if (*board(x, y) != EMPTY) {
      perror("block conflict.");
    }
    *board(x, y) = get_piece_color(active_piece->type);
  }

  // get new piece
  // TODO: implement popping a piece off the queue
  get_new_piece();
}

void game_move_left() {
  if (validate_translation(-1, 0)) {
    game_state->active_piece.x -= 1;
  }
}

void game_move_right() {
  if (validate_translation(1, 0)) {
    game_state->active_piece.x += 1;
  }
}

void game_rotate_cw() {}

void game_rotate_ccw() {}

void game_drop() { game_tick(); }

void game_fast_drop() {}

void game_store() {
  if (!game_state->can_store) {
    return;
  }

  const piece new_piece = game_state->store;
  game_state->store = game_state->active_piece.type;

  get_new_piece();
  game_state->active_piece.type = new_piece;
}
