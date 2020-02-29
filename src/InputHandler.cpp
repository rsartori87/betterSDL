#include "InputHandler.h"

#include <iostream>

#include "QuitEvent.h"
#include "JoystickEvent.h"
#include "cleanup.h"

InputHandler::InputHandler()
{
  if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
      std::cout << "Initializing joystick" << std::endl;
      SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

  if (SDL_NumJoysticks() > 0)
    {
      for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
	  SDL_Joystick* joy = SDL_JoystickOpen(i);
	  if (joy)
	    {
	      m_joystikcs.push_back(joy);
	    }
	}
      SDL_JoystickEventState(SDL_ENABLE);
    }
}

InputHandler::~InputHandler()
{
  for (auto j : m_joystikcs)
    {
      cleanup(j);
    }
}

bool InputHandler::update()
{
  bool run = true;
  SDL_Event event;
  //  std::unique_ptr<Event> result = std::make_unique<Event>();
  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  run = false;
	  break;

	// case SDL_JOYAXISMOTION:
	//   return InputHandler::onJoystickAxisMove(event);
	}
    }
  return run;
}

std::unique_ptr<Event> InputHandler::onJoystickAxisMove(const SDL_Event& evt)
{
  Vector2D right(0, 0), left(0, 0);

  if (evt.jaxis.axis == 0)
    {
      if (evt.jaxis.value > m_joystickDeadZone)
	{
	  right.setX(1);
	}
      else if (evt.jaxis.value < -m_joystickDeadZone)
	{
	  right.setX(-1);
	}
      else
	{
	  right.setX(0);
	}
    }

  if (evt.jaxis.axis == 1)
    {
      if (evt.jaxis.value > m_joystickDeadZone)
	{
	  right.setY(1);
	}
      else if (evt.jaxis.value < -m_joystickDeadZone)
	{
	  right.setY(-1);
	}
      else
	{
	  right.setY(0);
	} 
    }

  if (evt.jaxis.axis == 3)
    {
      if (evt.jaxis.value > m_joystickDeadZone)
	{
	  left.setX(1);
	}
      else if (evt.jaxis.value < -m_joystickDeadZone)
	{
	  left.setX(-1);
	}
      else
	{
	  left.setX(0);
	}
    }

  if (evt.jaxis.axis == 4)
    {
      if (evt.jaxis.value > m_joystickDeadZone)
	{
	  left.setY(1);
	}
      else if (evt.jaxis.value < -m_joystickDeadZone)
	{
	  left.setY(-1);
	}
      else
	{
	  left.setY(0);
	} 
    }  
  
  std::unique_ptr<JoystickEvent> event = std::make_unique<JoystickEvent>(right, left);

  return  event;
}
