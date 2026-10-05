#pragma once

#include "minesweeper/renderer.h"

namespace minesweeper {

class Game {
 public:
  Game(int rows = 16, int cols = 16, int mines = 40, int cell_size = 32);
  ~Game();

  Game(const Game&) = delete;
  Game& operator=(const Game&) = delete;
  Game(Game&&) = delete;
  Game& operator=(Game&&) = delete;

  void Run();

 private:
  void Draw();

  int rows_;
  int cols_;
  int mines_;
  int cell_size_;
  Renderer renderer_;
};

}  // namespace minesweeper
