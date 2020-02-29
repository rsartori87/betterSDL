#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>
#include <string>
#include <map>

class TextureManager
{
public:
  TextureManager(SDL_Renderer* renderer);
  ~TextureManager();

  bool load(std::string&& fileName, std::string&& id);
  void draw(std::string& id, int x, int y, int width, int height, SDL_RendererFlip flip);
  void drawFrame(std::string& id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
  SDL_Renderer* m_pRenderer;
  std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif
