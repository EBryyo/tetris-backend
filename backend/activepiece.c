#include "directions.h"
#include <activepiece.h>
#include <pieces.h>
#include <stdlib.h>

void set_line_piece(pair *coordinates, direction direction) {
  switch (direction) {
  case UP:
  case DOWN:
    /*
      0
      X
      0
      0
    */
    coordinates[1].x = 0;
    coordinates[1].y = -1;
    coordinates[2].x = 0;
    coordinates[2].y = 1;
    coordinates[3].x = 0;
    coordinates[3].y = 2;
    break;
  case RIGHT:
  case LEFT:
    /*
      0 X 0 0
    */
    coordinates[1].x = -1;
    coordinates[1].y = 0;
    coordinates[2].x = 1;
    coordinates[2].y = 0;
    coordinates[3].x = 2;
    coordinates[3].y = 0;
    break;
  }
}

void set_l_piece(pair *coordinates, direction direction) {
  switch (direction) {
  case UP:
    /*
      0
      0
      X 0
    */
    coordinates[1].x = 0;
    coordinates[1].y = -2;
    coordinates[2].x = 0;
    coordinates[2].y = -1;
    coordinates[3].x = 1;
    coordinates[3].y = 0;
    break;
  case DOWN:
    /*
      0 X
        0
        0
    */
    coordinates[1].x = 0;
    coordinates[1].y = 2;
    coordinates[2].x = 0;
    coordinates[2].y = 1;
    coordinates[3].x = -1;
    coordinates[3].y = 0;
    break;
  case RIGHT:
    /*
          0
      0 0 X
    */
    coordinates[1].x = 0;
    coordinates[1].y = -1;
    coordinates[2].x = -1;
    coordinates[2].y = 0;
    coordinates[3].x = -2;
    coordinates[3].y = 0;
    break;
  case LEFT:
    /*
      X 0 0
      0
    */
    coordinates[1].x = 0;
    coordinates[1].y = 1;
    coordinates[2].x = 1;
    coordinates[2].y = 0;
    coordinates[3].x = 2;
    coordinates[3].y = 0;
    break;
  }
}

void set_reverse_l_piece(pair *coordinates, direction direction) {
  switch (direction) {
  case UP:
    /*
        0
        0
      0 X
     */
    coordinates[1].x = 0;
    coordinates[1].y = -2;
    coordinates[2].x = 0;
    coordinates[2].y = -1;
    coordinates[3].x = -1;
    coordinates[3].y = 0;
    break;
  case DOWN:
    /*
      X 0
      0
      0
     */
    coordinates[1].x = 0;
    coordinates[1].y = 2;
    coordinates[2].x = 0;
    coordinates[2].y = 1;
    coordinates[3].x = 1;
    coordinates[3].y = 0;
    break;
  case RIGHT:
    /*
      0
      X 0 0
     */
    coordinates[1].x = 0;
    coordinates[1].y = -1;
    coordinates[2].x = 1;
    coordinates[2].y = 0;
    coordinates[3].x = 2;
    coordinates[3].y = 0;
    break;
  case LEFT:
    /*
      0 0 X
          0
    */
    coordinates[1].x = 0;
    coordinates[1].y = 1;
    coordinates[2].x = -1;
    coordinates[2].y = 0;
    coordinates[3].x = -2;
    coordinates[3].y = 0;
    break;
  }
}

void set_t_piece(pair *coordinates, direction direction) {
  switch (direction) {
  case UP:
    /*
        0
      0 X 0
     */
    coordinates[1].x = -1;
    coordinates[1].y = 0;
    coordinates[2].x = 0;
    coordinates[2].y = -1;
    coordinates[3].x = 1;
    coordinates[3].y = 0;
    break;
  case DOWN:
    /*
      0 X 0
        0
     */
    coordinates[1].x = -1;
    coordinates[1].y = 0;
    coordinates[2].x = 1;
    coordinates[2].y = 0;
    coordinates[3].x = 0;
    coordinates[3].y = 1;
    break;
  case RIGHT:
    /*
      0
      X 0
      0
     */
    coordinates[1].x = 0;
    coordinates[1].y = -1;
    coordinates[2].x = 1;
    coordinates[2].y = 0;
    coordinates[3].x = 0;
    coordinates[3].y = 1;
    break;
  case LEFT:
    /*
        0
      0 X
        0
    */
    coordinates[1].x = 0;
    coordinates[1].y = -1;
    coordinates[2].x = -1;
    coordinates[2].y = 0;
    coordinates[3].x = 0;
    coordinates[3].y = 1;
    break;
  }
}

void set_s_piece(pair *coordinates, direction direction) {
  switch (direction) {
  case UP:
  case DOWN:
    /*
        X 0
      0 0
     */
    coordinates[1].x = 1;
    coordinates[1].y = 0;
    coordinates[2].x = 0;
    coordinates[2].y = 1;
    coordinates[3].x = -1;
    coordinates[3].y = 1;
    break;
  case RIGHT:
  case LEFT:
    /*
      0
      X 0
        0
    */
    coordinates[1].x = 0;
    coordinates[1].y = -1;
    coordinates[2].x = 1;
    coordinates[2].y = 0;
    coordinates[3].x = 1;
    coordinates[3].y = 1;
    break;
  }
}

void set_z_piece(pair *coordinates, direction direction) {
  switch (direction) {
  case UP:
  case DOWN:
    /*
      0 X
        0 0
    */
    coordinates[1].x = -1;
    coordinates[1].y = 0;
    coordinates[2].x = 1;
    coordinates[2].y = 1;
    coordinates[3].x = 0;
    coordinates[3].y = 1;
    break;
  case RIGHT:
  case LEFT:
    /*
        0
      X 0
      0
    */
    coordinates[1].x = 1;
    coordinates[1].y = -1;
    coordinates[2].x = 1;
    coordinates[2].y = 0;
    coordinates[3].x = 0;
    coordinates[3].y = 1;
    break;
  }
}

void set_square_piece(pair *coordinates, direction direction) {
  /*
    0 0
    X 0
  */
  coordinates[1].x = 1;
  coordinates[1].y = 0;
  coordinates[2].x = 1;
  coordinates[2].y = -1;
  coordinates[3].x = 0;
  coordinates[3].y = -1;
}

void set_piece_blocks(ActivePiece *piece) {
  pair *coordinates = piece->blocks;

  // initialize root block
  coordinates[0].x = 0;
  coordinates[0].y = 0;

  switch (piece->type) {
  case SQUARE_PIECE:
    set_square_piece(coordinates, piece->direction);
    break;
  case L_PIECE:
    set_l_piece(coordinates, piece->direction);
    break;
  case REVERSE_L_PIECE:
    set_reverse_l_piece(coordinates, piece->direction);
    break;
  case S_PIECE:
    set_s_piece(coordinates, piece->direction);
    break;
  case T_PIECE:
    set_t_piece(coordinates, piece->direction);
    break;
  case Z_PIECE:
    set_z_piece(coordinates, piece->direction);
    break;
  case LINE_PIECE:
    set_line_piece(coordinates, piece->direction);
  default:
    break;
  }
}
