#include "TextureManager.h"

#include <SDL_image.h>

#include "cleanup.h"

TextureManager::TextureManager(SDL_Renderer* renderer) : m_pRenderer(renderer)
{};

TextureManager::~TextureManager()
{
  for (auto const& [key, val] : m_textureMap)
    {
      cleanup(val);
    }
}

bool TextureManager::load(std::string&& fileName, std::string&& id)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

  if (pTempSurface == nullptr)
    {
      return false;
    }

  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

  cleanup(pTempSurface);

  if (pTexture != nullptr)
    {
      m_textureMap[id] = pTexture;
      return true;
    }

  return false;
}

void TextureManager::draw(std::string& id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(m_pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string& id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;
  srcRect.x = width * currentFrame;
  srcRect.y = height * (currentRow - 1);
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(m_pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
