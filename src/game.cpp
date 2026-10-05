#include "minesweeper/game.h"

#include "minesweeper/board.h"
#include "minesweeper/renderer.h"
#include "minesweeper/window.h"
#include "raylib.h"

namespace minesweeper {

Game::Game(const Config& cfg)
    : cfg_(cfg),
      window_(cfg.cols * cfg.cell_size, cfg.rows * cfg.cell_size,
              "Minesweeper"),
      board_(cfg.cols, cfg.rows, cfg.mines),
      renderer_(cfg.cell_size) {}

void Game::Run() {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    renderer_.Draw(board_);
    EndDrawing();
  }
}

}  // namespace minesweeper
