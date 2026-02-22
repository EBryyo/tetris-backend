#include "colors.h"
#include <pieces.h>
#include <stdlib.h>

#define PIECES_COUNT 7;

piece random_piece() { return rand() % PIECES_COUNT; }

color get_piece_color(piece piece) {
  switch (piece) {
  case L_PIECE:
    return ORANGE;
  case REVERSE_L_PIECE:
    return DARK_BLUE;
  case T_PIECE:
    return PURPLE;
  case S_PIECE:
    return GREEN;
  case Z_PIECE:
    return RED;
  case SQUARE_PIECE:
    return YELLOW;
  case LINE_PIECE:
    return LIGHT_BLUE;
  default:
    return EMPTY;
  }
}
