#include <iostream>

#include <tetris.h>

int main() {
  auto game = game_init();

  std::cout << "Hello World!" << std::endl;

  std::cout << "Game pointer: " << game << std::endl;

  game_free();
  return 0;
}
