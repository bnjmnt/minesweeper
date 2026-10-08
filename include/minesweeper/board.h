#pragma once

#include <random>
#include <vector>

#include "minesweeper/cell.h"
#include "minesweeper/game_state.h"

namespace minesweeper {

class Board {
 public:
  Board(int rows, int cols, int mines);

  const Cell& GetCell(int row, int col) const;
  void Reveal(int row, int col);
  void ToggleFlag(int row, int col);

  int GetRows() const;
  int GetCols() const;
  GameState GetGameState() const;

 private:
  void PlaceMines(int safe_row, int safe_col);
  void FloodFill(int start_row, int start_col);
  void RevealAllMines();

  int rows_;
  int cols_;
  GameState game_state_;

  int mines_;
  int revealed_count_;
  std::vector<Cell> cells_;

  bool has_placed_mines_;
  std::mt19937 rng_{std::random_device{}()};
};

}  // namespace minesweeper
