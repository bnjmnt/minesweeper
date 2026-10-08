#include "minesweeper/game.h"

#include "minesweeper/board.h"
#include "minesweeper/game_state.h"
#include "minesweeper/renderer.h"
#include "minesweeper/window.h"
#include "raylib.h"

namespace minesweeper {

Game::Game(const Config& cfg)
    : cfg_(cfg),
      window_(cfg.cols * cfg.cell_size, cfg.rows * cfg.cell_size,
              "Minesweeper"),
      board_(cfg.rows, cfg.cols, cfg.mines),
      renderer_(cfg.cell_size) {}

void Game::Run() {
  while (!WindowShouldClose()) {
    HandleInput();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    renderer_.Draw(board_);
    EndDrawing();
  }
}

void Game::HandleInput() {
  if (IsKeyPressed(KEY_R)) {
    board_ = Board(cfg_.rows, cfg_.cols, cfg_.mines);
    return;
  }
  if (board_.GetGameState() != GameState::Playing) {
    return;
  }
  auto pos = renderer_.GetCellPosition(GetMousePosition(), board_);
  if (!pos) {
    return;
  }
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    board_.Reveal(pos->row, pos->col);
  }
  if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
    board_.ToggleFlag(pos->row, pos->col);
  }
}

}  // namespace minesweeper
