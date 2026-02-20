add_executable(tetris
  tetris.cc
)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG main
)


FetchContent_MakeAvailable(ftxui)

target_link_libraries(tetris PRIVATE
  tetris-backend
  ftxui::screen
  ftxui::dom
  ftxui::component
)

target_include_directories(tetris PUBLIC
  ${CMAKE_SOURCE_DIR}/backend/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
