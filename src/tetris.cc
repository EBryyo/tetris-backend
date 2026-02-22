#include "game.hh"

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/screen/screen.hpp>
#include <memory>
#include <tetris.h>
#include <thread>

int main() {
  auto tetris = game_init();
  auto Screen = ftxui::ScreenInteractive::Fullscreen();

  auto game = std::make_shared<Game>(tetris);

  auto renderer = ftxui::Renderer(game, [&] { return game->Render(); });

  std::thread tick_loop = std::thread([&] {
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      game_tick();
      Screen.PostEvent(ftxui::Event::Custom);
    }
  });

  Screen.Loop(renderer);

  // std::cout << "Hello World!" << std::endl;
  // std::cout << "Game pointer: " << game << std::endl;

  game_tick();

  game_free();
  return 0;
}
