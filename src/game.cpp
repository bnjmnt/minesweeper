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
    DrawText("MINESWEEPER", 10, 10, 20, LIGHTGRAY);
    EndDrawing();
  }
}

}  // namespace minesweeper
