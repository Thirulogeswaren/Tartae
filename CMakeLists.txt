cmake_minimum_required(VERSION 3.16...3.30)

project(Tartae LANGUAGES CXX)

add_subdirectory(Engine)

add_executable(${PROJECT_NAME} Game/Game.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} TartaeEngine)