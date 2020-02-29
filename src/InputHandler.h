#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <optional>
#include <memory>

#include "Vector2D.h"
#include "Event.h"

class InputHandler
{
public:
  InputHandler();
  std::optional<std::unique_ptr<Event>> update();
};

#endif
