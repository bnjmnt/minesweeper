#pragma once

#include "minesweeper/board.h"
#include "minesweeper/config.h"
#include "minesweeper/renderer.h"
#include "minesweeper/window.h"

namespace minesweeper {

class Game {
 public:
  explicit Game(const Config& cfg = {});

  ~Game() = default;
  Game(const Game&) = delete;
  Game& operator=(const Game&) = delete;
  Game(Game&&) = delete;
  Game& operator=(Game&&) = delete;

  void Run();

 private:
  void Draw();
  void HandleInput();

  Config cfg_;
  Window window_;
  Board board_;
  Renderer renderer_;
};

}  // namespace minesweeper
