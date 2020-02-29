cmake_minimum_required(VERSION 3.0)
project(betterSDL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 CONFIG REQUIRED)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  find_package(sdl2-image CONFIG REQUIRED)
else()
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
  find_package(SDL2_image REQUIRED)
endif()

add_executable(betterSDL
  src/main.cpp
  src/cleanup.h
  src/Window.h
  src/Window.cpp
  src/InputHandler.h
  src/InputHandler.cpp)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_link_libraries(betterSDL PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_image)
else()
  target_include_directories(betterSDL PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
  target_link_libraries(betterSDL PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
endif()
