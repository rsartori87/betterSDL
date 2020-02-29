#include "JoystickEvent.h"

JoystickEvent::JoystickEvent(Vector2D right, Vector2D left) :
  m_rightVector(right), m_leftVector(left), Event()
{};

EventType JoystickEvent::getType()
{
	return EventType::JOYSTICK;
}


Vector2D JoystickEvent::getRightStick()
{
  return m_rightVector;
}
