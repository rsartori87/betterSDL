#include "InputHandler.h"

#include <SDL.h>

std::optional<Event> InputHandler::update()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  Event event;
	  event.type = EventType::QUIT;
	  return event;
	}
    }
  return {};
}
