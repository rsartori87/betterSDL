cmake_minimum_required(VERSION 3.0)
project(betterSDL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)

add_executable(betterSDL
  src/main.cpp
  src/cleanup.h
  src/Window.h
  src/Window.cpp
  src/InputHandler.h
  src/InputHandler.cpp)

target_link_libraries(betterSDL PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_image)
