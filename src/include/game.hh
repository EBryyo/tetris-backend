#pragma once
#include "tetris.h"
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/elements.hpp>

class Game : public ftxui::ComponentBase {
public:
  Game(Tetris *tetris) : tetris_(tetris) {}

  ftxui::Element OnRender() override;

  bool OnEvent(ftxui::Event event) override;

private:
  Tetris *tetris_;
};
