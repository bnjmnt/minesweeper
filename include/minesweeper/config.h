#pragma once

namespace minesweeper {

struct Config {
  int rows = 16;
  int cols = 16;
  int mines = 40;
  int cell_size = 32;
};

}  // namespace minesweeper
