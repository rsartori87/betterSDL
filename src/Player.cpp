#include "Player.h"

Player::Player(LoaderParams loaderParams) :
  m_position(loaderParams.x, loaderParams.y),
  m_velocity(0, 0),
  m_acceleration(0, 0),
  m_width(loaderParams.width),
  m_height(loaderParams.height),
  m_currentRow(1),
  m_currentFrame(1),
  id(loaderParams.id) {}

void Player::draw(TextureManager& textureManager)
{
  m_currentFrame = int (((SDL_GetTicks() / 100) % 6));
    
  // m_velocity += m_acceleration;
  // m_position += m_velocity;

  textureManager.drawFrame(id, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame);
}


void Player::update(JoystickEvent* event)
{
  m_velocity = event->getRightStick() * 2;
}
