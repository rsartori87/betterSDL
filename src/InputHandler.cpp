#include "InputHandler.h"

#include <SDL.h>

bool InputHandler::update()
{
  bool run = true;
  SDL_Event event;
  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  run = false;
	  break;
	}
    }
  return run;
}
