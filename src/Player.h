#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "LoaderParams.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "JoystickEvent.h"

class Player
{
public:
  Player(LoaderParams params);

  void draw(TextureManager& textureManager);
  void update(JoystickEvent* event);
private:
  int m_width, m_height, m_currentRow, m_currentFrame;
  Vector2D m_position, m_velocity, m_acceleration;
  std::string id;
};

#endif
