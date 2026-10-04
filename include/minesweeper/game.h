#pragma once

namespace minesweeper {

class Game {
 public:
  Game(int rows = 16, int cols = 16, int mines = 40, int cell_len = 32);
  ~Game();

  Game(const Game&) = delete;
  Game& operator=(const Game&) = delete;
  Game(Game&&) = delete;
  Game& operator=(Game&&) = delete;

  void Run();

 private:
  int rows_;
  int cols_;
  int mines_;
  int cell_len_;
};

}  // namespace minesweeper
