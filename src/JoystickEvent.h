#ifndef JOYSTICK_EVENT_H
#define JOYSTICK_EVENT_H

#include "Event.h"
#include "Vector2D.h"

class JoystickEvent : public Event
{
public:
	virtual EventType getType();
private:
	Vector2D m_rightVector;
	Vector2D m_leftVector;
};

#endif // !JOYSTICK_EVENT_H
