#ifndef QUIT_EVENT_H
#define QUIT_EVENT_H

#include "Event.h"

class QuitEvent : public Event
{
public:
  EventType getType() override;
};

#endif
