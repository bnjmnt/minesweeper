#include "minesweeper/board.h"

namespace minesweeper {

Board::Board(int rows, int cols, int mines)
    : rows_(rows), cols_(cols), mines_(mines), cells_(rows * cols) {}

const Cell& Board::GetCell(int row, int col) const {
  return cells_[row * cols_ + col];
}

int Board::GetRows() const { return rows_; }
int Board::GetCols() const { return cols_; }

}  // namespace minesweeper
