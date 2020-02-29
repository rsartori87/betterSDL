#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <memory>
#include <vector>
#include <SDL.h>

#include "Vector2D.h"
#include "Event.h"

class InputHandler
{
public:
  InputHandler();
  ~InputHandler();
  bool update();
private:
  std::unique_ptr<Event> onJoystickAxisMove(const SDL_Event& evt);

  std::vector<SDL_Joystick*> m_joystikcs;
  const int m_joystickDeadZone = 10000;
};

#endif
