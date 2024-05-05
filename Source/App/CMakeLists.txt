cmake_minimum_required(VERSION 3.14)

set(SOURCES
        Singleton/ISingleton.cpp
        Singleton/ISingleton.h
        Windows/MainWindow.h
        Windows/MainWindow.cpp
        Managers/ShaderManager.cpp
        Managers/ShaderManager.h
        Game/Game.cpp
        Game/Game.h
        main.cpp)

add_executable(OpenGl ${SOURCES})

target_link_libraries(
        OpenGl
        Glm
        Glew
        glfw
        Glad
)

