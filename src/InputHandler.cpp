#include "InputHandler.h"

#include <SDL.h>

#include "QuitEvent.h"

InputHandler::InputHandler()
{
  if (SDL_WasInit(SDL_INIT_JOYSTICK))
    {
      SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }
}

std::optional<std::unique_ptr<Event>> InputHandler::update()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  return std::make_unique<QuitEvent>();
	}
    }
  return {};
}
