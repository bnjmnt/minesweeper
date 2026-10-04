#include "minesweeper/game.h"

#include "raylib.h"

namespace minesweeper {

Game::Game(int rows, int cols, int mines, int cell_size)
    : rows_(rows), cols_(cols), mines_(mines), cell_size_(cell_size) {
  InitWindow(cols_ * cell_size_, rows_ * cell_size_, "Minesweeper");
  SetTargetFPS(60);
  tile_texture_ = LoadTexture("assets/tile.png");
}

Game::~Game() {
  UnloadTexture(tile_texture_);
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
      DrawTexture(tile_texture_, posX, posY, WHITE);
    }
  }
}

}  // namespace minesweeper
