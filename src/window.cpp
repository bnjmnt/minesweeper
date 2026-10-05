#include "minesweeper/window.h"

#include <raylib.h>

namespace minesweeper {

Window::Window(int width, int height, const char* title) {
  InitWindow(width, height, title);
}

Window::~Window() { CloseWindow(); }

}  // namespace minesweeper
