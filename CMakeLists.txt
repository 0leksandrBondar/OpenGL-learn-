cmake_minimum_required(VERSION 3.14)

project(OpenGl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DEPENDENCIES_DIR_NAME Dependencies)
set(DEPENDENCIES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${DEPENDENCIES_DIR_NAME})

add_subdirectory(Libs/glad)
add_subdirectory(Libs/glew)
add_subdirectory(Libs/glm)
add_subdirectory(Dependencies/glfw)
add_subdirectory(Source)

