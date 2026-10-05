#pragma once

namespace minesweeper {

enum class CellType {
  Zero,
  One,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Hidden,
  Flag,
  Mine,
};

struct Cell {
  bool is_revealed = false;
  bool is_mine = false;
  bool is_flagged = false;
  int num_adjacent_mines = 0;
};

}  // namespace minesweeper
