#include "minesweeper/board.h"

#include <algorithm>
#include <array>
#include <cstdlib>
#include <queue>
#include <vector>

#include "minesweeper/game_state.h"

namespace minesweeper {

Board::Board(int rows, int cols, int mines)
    : rows_(rows),
      cols_(cols),
      mines_(mines),
      cells_(rows * cols),
      has_placed_mines_(false),
      game_state_(GameState::Playing) {}

const Cell& Board::GetCell(int row, int col) const {
  return cells_[row * cols_ + col];
}

void Board::Reveal(int row, int col) {
  if (game_state_ != GameState::Playing) {
    return;
  }

  Cell& cell = cells_[row * cols_ + col];
  if (cell.is_flagged || cell.is_revealed) {
    return;
  }

  if (!has_placed_mines_) {
    PlaceMines(row, col);
    has_placed_mines_ = true;
  }

  if (cell.is_mine) {
    cell.is_exploded = true;
    game_state_ = GameState::Lost;
    RevealAllMines();
    return;
  }

  FloodFill(row, col);
  if (revealed_count_ == rows_ * cols_ - mines_) {
    game_state_ = GameState::Won;
  }
}

void Board::ToggleFlag(int row, int col) {
  Cell& cell = cells_[row * cols_ + col];
  if (!cell.is_revealed) {
    cell.is_flagged = !cell.is_flagged;
  }
}

int Board::GetRows() const { return rows_; }
int Board::GetCols() const { return cols_; }
GameState Board::GetGameState() const { return game_state_; }

void Board::PlaceMines(int safe_row, int safe_col) {
  std::vector<int> candidates;
  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      // make 3x3 area for initial reveal safe
      if (std::abs(row - safe_row) > 1 || std::abs(col - safe_col) > 1) {
        candidates.push_back(row * cols_ + col);
      }
    }
  }

  std::ranges::shuffle(candidates, rng_);
  for (int i = 0; i < mines_; ++i) {
    cells_[candidates[i]].is_mine = true;
  }

  constexpr std::array<std::array<int, 2>, 8> dirs{
      {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      if (cells_[row * cols_ + col].is_mine) {
        continue;
      }
      int mines = 0;
      for (const auto& dir : dirs) {
        int next_row = row + dir[0];
        int next_col = col + dir[1];
        if (next_row < 0 || next_row >= rows_ || next_col < 0 ||
            next_col >= cols_ || !GetCell(next_row, next_col).is_mine) {
          continue;
        }
        ++mines;
      }
      cells_[row * cols_ + col].num_adjacent_mines = mines;
    }
  }
}

void Board::FloodFill(int start_row, int start_col) {
  constexpr std::array<std::array<int, 2>, 8> dirs{
      {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

  std::queue<std::array<int, 2>> q;
  q.push({start_row, start_col});
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    Cell& cell = cells_[r * cols_ + c];
    if (cell.is_flagged || cell.is_revealed) {
      continue;
    }

    cell.is_revealed = true;
    ++revealed_count_;

    if (cell.num_adjacent_mines != 0) {
      continue;
    }

    for (const auto& dir : dirs) {
      int nr = r + dir[0];
      int nc = c + dir[1];
      if (nr < 0 || nr >= rows_ || nc < 0 || nc >= cols_) {
        continue;
      }
      Cell& neighbor = cells_[nr * cols_ + nc];
      if (!neighbor.is_revealed && !neighbor.is_flagged && !neighbor.is_mine) {
        q.push({nr, nc});
      }
    }
  }
}

void Board::RevealAllMines() {
  for (Cell& c : cells_) {
    if (c.is_mine) {
      c.is_revealed = true;
    }
  }
}

}  // namespace minesweeper
