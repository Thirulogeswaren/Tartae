cmake_minimum_required(VERSION 3.16...3.30)

add_library(TartaeEngine STATIC 
	${CMAKE_SOURCE_DIR}/Engine/Renderer/Renderer.cpp
	${CMAKE_SOURCE_DIR}/Engine/Handlers/ComponentHandler.cpp
)

target_include_directories(TartaeEngine PRIVATE ${PROJECT_SOURCE_DIR}/Engine)
target_include_directories(TartaeEngine PRIVATE ${PROJECT_SOURCE_DIR}/Editor)

target_compile_features(TartaeEngine PUBLIC cxx_std_20)

target_link_libraries(TartaeEngine
	PUBLIC SDL2::SDL2
	PUBLIC SDL2::SDL2main
	PUBLIC SDL2_image::SDL2_image
)
