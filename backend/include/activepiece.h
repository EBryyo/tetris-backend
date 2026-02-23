#pragma once

#include "directions.h"
#include "pieces.h"

/*
 * a struct to depict a pair of relative coordinates.
 */
typedef struct {
  int8_t x;
  int8_t y;
} pair;

typedef struct {
  piece type;
  direction direction;
  int8_t x;
  int8_t y;
  pair blocks[4];
} ActivePiece;

/*
 * @brief returns a heap allocated array of four coordinates.
 */
void set_piece_blocks(ActivePiece *piece);
