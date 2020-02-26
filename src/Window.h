#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

class Window
{
public:
  Window(const char* title, int xpos, int ypos, int width, int height);
  ~Window();

private:
  SDL_Window* m_pWindow;
};

#endif
