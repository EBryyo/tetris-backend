#pragma once

#include "colors.h"
#include <stdint.h>

typedef enum {
  L_PIECE,         // orange
  REVERSE_L_PIECE, // dark blue
  T_PIECE,         // purple
  S_PIECE,         // green
  Z_PIECE,         // red
  SQUARE_PIECE,    // yellow
  LINE_PIECE,      // light blue
  NONE,            // none, dumdum!
} piece;

/*
 * @brief generates a random piece.
 * @return random member of the piece enum
 */
piece random_piece();

/*
   @brief gets color associated to a piece type
   @return the color enum member
 */
color get_piece_color(piece piece);
