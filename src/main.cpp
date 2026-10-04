#include <string>

#include "raylib.h"

int main() {
  constexpr int WIDTH = 1072;
  constexpr int HEIGHT = WIDTH / 16 * 9;
  constexpr std::string TITLE = "Minesweeper";

  InitWindow(WIDTH, HEIGHT, TITLE.c_str());

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("MINESWEEPER", 10, 10, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
