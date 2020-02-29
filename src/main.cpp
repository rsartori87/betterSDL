#include <SDL.h>
#include <iostream>

#include "Window.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "Player.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
  Uint32 frameStart, frameTime;
  Window window("Test Window", 100, 100, 640, 480);
  InputHandler inputHandler;
  TextureManager textureManager(window.getRenderer());
  if (textureManager.load("assets/animate-alpha.png", "animate"))
    {
      LoaderParams params(100, 100, 128, 82, "animate");
      Player player(params);

      bool run = true;

      while (run) {
	frameStart = SDL_GetTicks();
	run = inputHandler.update();

	window.clear();
	player.draw(textureManager);
	window.render();
    
	frameTime = SDL_GetTicks() - frameStart;
	if (frameTime < DELAY_TIME)
	  {
	    SDL_Delay((int) (DELAY_TIME - frameTime));
	  }
      };
      return 0;
    }

  std::cout << "Failed to load texture" << std::endl;
  return 1;
}
