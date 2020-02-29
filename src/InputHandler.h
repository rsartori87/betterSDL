#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <optional>

enum EventType {
	    QUIT,
        EMPTY
};

struct Event {
  EventType type;
};

class InputHandler
{
public:
  std::optional<Event> update();
};

#endif
