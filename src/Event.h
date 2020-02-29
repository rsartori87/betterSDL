#ifndef EVENT_H
#define EVENT_H

enum EventType
  {
   QUIT,
   EMPTY
  };

class Event
{
public:
  virtual EventType getType();
};

#endif
