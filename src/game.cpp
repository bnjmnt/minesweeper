#include "minesweeper/game.h"

#include "raylib.h"

namespace minesweeper {

Game::Game(int rows, int cols, int mines, int cell_len)
    : rows_(rows), cols_(cols), mines_(mines), cell_len_(cell_len) {
  InitWindow(cols_ * cell_len_, rows_ * cell_len_, "Minesweeper");

  SetTargetFPS(60);
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

void Game::Draw() const {
  ClearBackground(RAYWHITE);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      int posX = i * cell_len_;
      int posY = j * cell_len_;
      DrawRectangleLines(posX, posY, cell_len_, cell_len_, LIGHTGRAY);
    }
  }
}

}  // namespace minesweeper
