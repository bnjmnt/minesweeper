#include "minesweeper/renderer.h"

#include <raylib.h>

#include "minesweeper/cell.h"

namespace minesweeper {

Renderer::~Renderer() { UnloadTexture(cell_sheet_); }

void Renderer::Init() { cell_sheet_ = LoadTexture("assets/cell_sheet.png"); }

void Renderer::DrawCell(CellType type, int posX, int posY, int cell_size) {
  int cell_index = static_cast<int>(type);
  Rectangle src = {static_cast<float>(cell_index * cell_size), 0,
                   static_cast<float>(cell_size),
                   static_cast<float>(cell_size)};
  Vector2 dst = {static_cast<float>(posX), static_cast<float>(posY)};
  DrawTextureRec(cell_sheet_, src, dst, WHITE);
}

}  // namespace minesweeper
