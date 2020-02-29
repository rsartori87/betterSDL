#include "Window.h"

#include <iostream>

#include "cleanup.h"

Window::Window(const char* title, int xpos, int ypos, int width, int height)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
      m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
      if (m_pWindow != nullptr)
	{
	  std::cout << "window creation succes" << std::endl;
	  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	  if (m_pRenderer != nullptr)
	    {
	      std::cout << "renderer creation success" << std::endl;
	      // Set the backround color
	      SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	    }
	}
      else
	{
	  std::cout << "window creation failed " << SDL_GetError() << std::endl;
	}
    }
  else
    {
      std::cout << "SDL initialization failed " << SDL_GetError() << std::endl;
    }
}

void Window::clear()
{
  SDL_RenderClear(m_pRenderer);
}

void Window::render()
{
  SDL_RenderPresent(m_pRenderer);
}

Window::~Window()
{
  std::cout << "Cleaning Window" << std::endl;
  cleanup(m_pRenderer, m_pWindow);
  SDL_Quit();
}


SDL_Renderer* Window::getRenderer()
{
  return m_pRenderer;
}
