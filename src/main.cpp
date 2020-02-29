#include <SDL.h>

#include "Window.h"
#include "InputHandler.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
  Uint32 frameStart, frameTime;
  Window window("Test Window", 100, 100, 640, 480);
  InputHandler inputHandler;

  std::unique_ptr<Event> event = std::make_unique<Event>();

  while (event->getType() != EventType::QUIT) {
    if (auto readInput = inputHandler.update()) {
      event = std::move(*readInput);
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
