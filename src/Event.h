#ifndef EVENT_H
#define EVENT_H

enum EventType
  {
   QUIT,
   EMPTY,
   JOYSTICK
  };

class Event
{
public:
  virtual EventType getType();
};

#endif
