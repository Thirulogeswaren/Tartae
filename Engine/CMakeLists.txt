cmake_minimum_required(VERSION 3.16...3.30)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_library(TartaeEngine STATIC
	Base/Main.cpp
	Renderer/Renderer.cpp
)

target_include_directories(TartaeEngine PRIVATE ${CMAKE_SOURCE_DIR}/Engine)
target_compile_features(TartaeEngine PUBLIC cxx_std_20)

target_link_libraries(TartaeEngine PUBLIC SDL2::SDL2 SDL2_image::SDL2_image fmt::fmt)