#include "Window.h"

#include <iostream>

Window::Window(const char* title, int xpos, int ypos, int width, int height)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
      m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
      if (m_pWindow != 0)
	{
	  std::cout << "window creation succes" << std::endl;
	}
      else
	{
	  std::cout << "window creation failed" << std::endl;
	}
    }
  else
    {
      std::cout << "SDL initialization failed" << std::endl;
    }
}

Window::~Window()
{
  std::cout << "Cleaning Window" << std::endl;
  if (m_pWindow != nullptr)
    {
      SDL_DestroyWindow(m_pWindow);
    }
  SDL_Quit();
}
