#include "minesweeper/game.h"

#include "minesweeper/cell.h"
#include "minesweeper/renderer.h"
#include "raylib.h"

namespace minesweeper {

Game::Game(int rows, int cols, int mines, int cell_size)
    : rows_(rows), cols_(cols), mines_(mines), cell_size_(cell_size) {
  InitWindow(cols_ * cell_size_, rows_ * cell_size_, "Minesweeper");
  SetTargetFPS(60);
  renderer_.Init();
}

Game::~Game() { CloseWindow(); }

void Game::Run() {
  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    Draw();

    EndDrawing();
  }
}

void Game::Draw() {
  ClearBackground(RAYWHITE);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      int posX = j * cell_size_;
      int posY = i * cell_size_;
      renderer_.DrawCell(CellType::Hidden, posX, posY, cell_size_);
    }
  }
}

}  // namespace minesweeper
