add_library(tetris-backend STATIC
  tetris.c
  pieces.c 
  activepiece.c
)

target_include_directories(tetris-backend PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
