#ifndef LOADER_PARAM_H
#define LOADER_PARAM_H

#include <string>

struct LoaderParams
{
LoaderParams(int x, int y, int width, int height, std::string id)
    : x(x), y(y), width(width), height(height), id(id) {}
  int x, y, width, height;
  std::string id;
};

#endif
