#pragma once

#include <random>
#include <vector>

#include "minesweeper/cell.h"

namespace minesweeper {

class Board {
 public:
  Board(int rows, int cols, int mines);

  const Cell& GetCell(int row, int col) const;
  void Reveal(int row, int col);
  void ToggleFlag(int row, int col);

  int GetRows() const;
  int GetCols() const;

 private:
  void PlaceMines(int safe_row, int safe_col);

  int rows_;
  int cols_;
  int mines_;
  std::vector<Cell> cells_;
  bool has_placed_mines_;
  std::mt19937 rng_{std::random_device{}()};
};

}  // namespace minesweeper
