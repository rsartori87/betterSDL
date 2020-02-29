#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

/**
 * @file
 * @author Riccardo Sartori <riccardo.sartori87@gmail.com>
 * @version 1.0
 * @section DESCRIPTION
 * A SDL_Window wrapper
 */

/**
* @brief Window Class
* @author Riccardo Sartori
*
* This is a wrapper around SDL_Window for use inside c++ codebases.
*/
class Window
{
public:
  Window(const char* title, int xpos, int ypos, int width, int height);
  ~Window();

  SDL_Renderer* getRenderer();

  void clear();
  void render();

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
};

#endif
