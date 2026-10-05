#include "minesweeper/game.h"

#include "raylib.h"

namespace minesweeper {

Game::Game(int rows, int cols, int mines, int cell_size)
    : rows_(rows), cols_(cols), mines_(mines), cell_size_(cell_size) {
  InitWindow(cols_ * cell_size_, rows_ * cell_size_, "Minesweeper");
  SetTargetFPS(60);
  tile_sheet_ = LoadTexture("assets/tile_sheet.png");
}

Game::~Game() {
  UnloadTexture(tile_sheet_);
  CloseWindow();
}

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
      int posX = i * cell_size_;
      int posY = j * cell_size_;
      Rectangle src = {static_cast<float>(posX), 0,
                       static_cast<float>(cell_size_),
                       static_cast<float>(cell_size_)};
      Rectangle dst = {static_cast<float>(posX), static_cast<float>(posY),
                       static_cast<float>(cell_size_),
                       static_cast<float>(cell_size_)};
      DrawTexturePro(tile_sheet_, src, dst, {0, 0}, 0, WHITE);
    }
  }
}

}  // namespace minesweeper
