cmake_minimum_required(VERSION 3.16...3.40)

find_package(imgui CONFIG REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} Editor.cpp 
	${CMAKE_SOURCE_DIR}/Editor/Assets/EditorInit.cpp
	${CMAKE_SOURCE_DIR}/Editor/Inspector/Panel.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Engine)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Editor)

target_link_libraries(${CMAKE_PROJECT_NAME} TartaeEngine imgui::imgui)
