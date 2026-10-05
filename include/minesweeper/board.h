#pragma once

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
  int rows_;
  int cols_;
  int mines_;
  std::vector<Cell> cells_;
};

}  // namespace minesweeper
