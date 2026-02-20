#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "activepiece.h"
#include <colors.h>
#include <pieces.h>
#include <stddef.h>
#include <stdint.h>

/*
  holds the current state of the game
 */
typedef struct {
  color *board; // the board. to access [x,y] -> board[x + y * WIDTH];
  piece *queue; // queue of pieces.

  uint8_t height;           // height of the board
  uint8_t width;            // width of the board
  piece store;              // contains the stored piece
  ActivePiece active_piece; // the active piece. not included in the board;
  int score;                // player score
} Game;

/*
 * @brief initiates the game. returns a pointer to the game state.
 */
Game *game_init();

/*
 * @uninitializes the game. frees all related resources.
 */
void game_free();

/*
 * @brief advances the game state by one tick. one tick corresponds to the
 * active piece dropping one row or settling in place.
 */
void game_tick();

/*
 * @brief moves the active piece to the left if possible.
 */
void game_move_left();

/*
 * @brief moves the active piece to the right if possible.
 */
void game_move_right();

/*
 * @brief rotates the active piece clockwise.
 */
void game_rotate_cw();

/*
 * @brief rotates the active piece counter clockwise.
 */
void game_rotate_ccw();

/*
 * @brief drops the active piece one row, or settles it in place.
 */
void game_drop();

/*
 * @brief snaps the active piece down and settles it.
 */
void game_fast_drop();

/*
 * @brief stores the active piece, and replaces it with the currently stored
 * piece if there is one. Otherwise, advances to the next piece.
 */
void game_store();

#ifdef __cplusplus
}
#endif
