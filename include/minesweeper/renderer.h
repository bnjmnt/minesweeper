#pragma once

#include "minesweeper/cell.h"
#include "raylib.h"

namespace minesweeper {

class Renderer {
 public:
  Renderer() = default;
  ~Renderer();

  Renderer(const Renderer&) = delete;
  Renderer& operator=(const Renderer&) = delete;
  Renderer(Renderer&&) = delete;
  Renderer& operator=(Renderer&&) = delete;

  void Init();
  void DrawCell(CellType type, int posX, int posY, int cell_size);

 private:
  Texture2D cell_sheet_;
};

}  // namespace minesweeper
