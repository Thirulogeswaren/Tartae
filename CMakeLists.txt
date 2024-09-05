cmake_minimum_required(VERSION 3.16...3.30)

project(Tartae LANGUAGES CXX)

add_subdirectory(engine)

add_executable(${PROJECT_NAME} engine/game.cpp)

target_link_libraries(${PROJECT_NAME} engine-core)