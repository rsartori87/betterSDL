#include <iostream>

#include "Window.h"

int main(int argc, char* argv[])
{
  std::cout << "First line" << std::endl;

  Window window("Test Window", 100, 100, 640, 480);

  SDL_Delay(10000);
  
  return 0;
}
