#pragma once

namespace minesweeper {

class Window {
 public:
  Window(int width, int height, const char* title);
  ~Window();
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(Window&&) = delete;
};

}  // namespace minesweeper
