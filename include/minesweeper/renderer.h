#pragma once

#include "minesweeper/board.h"
#include "minesweeper/cell.h"
#include "raylib.h"

namespace minesweeper {

class Renderer {
 public:
  Renderer(int cell_size);
  ~Renderer();

  Renderer(const Renderer&) = delete;
  Renderer& operator=(const Renderer&) = delete;
  Renderer(Renderer&&) = delete;
  Renderer& operator=(Renderer&&) = delete;

  void Draw(const Board& board) const;

 private:
  static CellType GetCellType(const Cell& cell);
  Rectangle GetCellSource(CellType type) const;

  Texture2D cell_sheet_;
  int cell_size_;
};

}  // namespace minesweeper
