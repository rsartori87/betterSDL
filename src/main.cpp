#include "Window.h"
#include "InputHandler.h"

int main()
{
  Window window("Test Window", 100, 100, 640, 480);
  InputHandler inputHandler;

  while (inputHandler.update()) {};
  
  return 0;
}
