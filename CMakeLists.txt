cmake_minimum_required(VERSION 3.16...3.30)

project(GameJam LANGUAGES CXX)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(Engine)
add_subdirectory(Game)
