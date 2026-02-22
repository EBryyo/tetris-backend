#include <colors.h>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>
#include <game.hh>
#include <pieces.h>
#include <tetris.h>

namespace {
ftxui::Color get_color(color color) {
  switch (color) {
  case DARK_BLUE:
    return ftxui::Color::DarkBlue;
  case LIGHT_BLUE:
    return ftxui::Color::LightSkyBlue1;
  case RED:
    return ftxui::Color::Red;
  case YELLOW:
    return ftxui::Color::Yellow;
  case PURPLE:
    return ftxui::Color::Purple;
  case ORANGE:
    return ftxui::Color::Orange1;
  case GREEN:
    return ftxui::Color::Green;
  default:
    return ftxui::Color::Black;
  }
}
}; // namespace

ftxui::Element Game::OnRender() {
  ftxui::Elements lines;

  for (int i = 0; i < tetris_->height; i++) {
    ftxui::Elements blocks;

    for (int j = 0; j < tetris_->width; j++) {
      auto color = get_color(tetris_->board[j + i * tetris_->width]);

      auto active_piece = tetris_->active_piece;
      for (size_t k = 0; k < 4; k++) {
        auto block = active_piece.blocks[k];
        if (i == block.y + active_piece.y && j == block.x + active_piece.x) {
          color = get_color(get_piece_color(active_piece.type));
          break;
        }
      }

      blocks.push_back(ftxui::text("  ") | ftxui::bgcolor(color));
    }

    lines.push_back(ftxui::hbox(blocks));
  }

  return ftxui::window(ftxui::text("TETRIS"),
                       ftxui::vbox(lines) | ftxui::center) |
         ftxui::center;
}

bool Game::OnEvent(ftxui::Event event) {
  if (event == ftxui::Event::ArrowLeft) {
    game_move_left();
    return true;
  } else if (event == ftxui::Event::ArrowRight) {
    game_move_right();
    return true;
  } else if (event == ftxui::Event::ArrowUp) {
    game_rotate_cw();
    return true;
  } else if (event == ftxui::Event::ArrowDown) {
    game_drop();
    return true;
  } else if (event == ftxui::Event::Character('c')) {
    game_store();
    return true;
  } else if (event == ftxui::Event::Character(' ')) {
    game_fast_drop();
    return true;
  }
  return false;
}
