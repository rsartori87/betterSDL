cmake_minimum_required(VERSION 3.0)
project(betterSDL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(betterSDL
  src/main.cpp
  src/Window.h
  src/Window.cpp)

target_include_directories(betterSDL PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(betterSDL PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
