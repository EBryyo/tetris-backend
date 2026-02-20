#pragma once

#include "directions.h"
#include "pieces.h"

typedef struct {
  piece type;
  direction direction;
  int x;
  int y;
} ActivePiece;
