#include "Window.h"

int main(int argc, char* argv[])
{
  Window window("Test Window", 100, 100, 640, 480);

  SDL_Delay(10000);
  
  return 0;
}
