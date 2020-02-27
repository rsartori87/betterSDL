#include "Window.h"

#include <iostream>

#include "cleanup.h"

Window::Window(const char* title, int xpos, int ypos, int width, int height)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
      m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
      if (m_pWindow != nullptr)
	{
	  std::cout << "window creation succes" << std::endl;
	  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	  if (m_pRenderer != nullptr)
	    {
	      std::cout << "renderer creation success" << std::endl;
	      SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	    }
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
  cleanup(m_pRenderer, m_pWindow);
  SDL_Quit();
}
