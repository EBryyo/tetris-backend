add_executable(tetris
  tetris.cc
)

target_link_libraries(tetris PRIVATE
  tetris-backend
)

target_include_directories(tetris PUBLIC
  ${CMAKE_SOURCE_DIR}/backend/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
