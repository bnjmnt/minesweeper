#include "minesweeper/renderer.h"

#include <optional>

#include "minesweeper/cell.h"
#include "raylib.h"

namespace minesweeper {

Renderer::Renderer(int cell_size) : cell_size_(cell_size) {
  cell_sheet_ = LoadTexture(
      TextFormat("%sassets/cell_sheet.png", GetApplicationDirectory()));
}

Renderer::~Renderer() { UnloadTexture(cell_sheet_); }

void Renderer::Draw(const Board& board) const {
  for (int row = 0; row < board.GetRows(); ++row) {
    for (int col = 0; col < board.GetCols(); ++col) {
      Rectangle src = GetCellSource(GetCellType(board.GetCell(row, col)));
      Vector2 pos{static_cast<float>(col * cell_size_),
                  static_cast<float>(row * cell_size_)};
      DrawTextureRec(cell_sheet_, src, pos, WHITE);
    }
  }
}

std::optional<CellPosition> Renderer::GetCellPosition(
    Vector2 mouse, const Board& board) const {
  if (mouse.x < 0 || mouse.y < 0) {
    return std::nullopt;
  }
  CellPosition pos{static_cast<int>(mouse.y) / cell_size_,
                   static_cast<int>(mouse.x) / cell_size_};
  if (pos.row >= board.GetRows() || pos.col >= board.GetCols()) {
    return std::nullopt;
  }
  return pos;
}

CellType Renderer::GetCellType(const Cell& cell) {
  if (!cell.is_revealed) {
    return cell.is_flagged ? CellType::Flag : CellType::Hidden;
  }
  if (cell.is_mine) {
    return CellType::Mine;
  }
  return static_cast<CellType>(static_cast<int>(CellType::Zero) +
                               cell.num_adjacent_mines);
}

Rectangle Renderer::GetCellSource(CellType type) const {
  return {static_cast<float>(static_cast<int>(type)) *
              static_cast<float>(cell_size_),
          0, static_cast<float>(cell_size_), static_cast<float>(cell_size_)};
}

}  // namespace minesweeper
