#include <SDL.h>

#include "Window.h"
#include "InputHandler.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main()
{
  Uint32 frameStart, frameTime;
  Window window("Test Window", 100, 100, 640, 480);
  InputHandler inputHandler;

  Event event;
  while (event.type != EventType::QUIT) {
    if (auto readInput = inputHandler.update()) {
      event = *readInput;
    }
    frameStart = SDL_GetTicks();
    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < DELAY_TIME)
      {
	SDL_Delay((int) (DELAY_TIME - frameTime));
      }
  };
  
  return 0;
}
