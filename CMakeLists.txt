cmake_minimum_required(VERSION 3.20)
project(RaylibShader)

set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} main.cpp
        factory/player/Player.cpp
        factory/player/Player.h
        factory/input_listener/InputListener.cpp
        factory/input_listener/InputListener.h
        engine/Engine.cpp
        engine/Engine.h
        factory/camera/CameraEngine.cpp
        factory/camera/CameraEngine.h
        factory/glass/Glass.cpp
        factory/glass/Glass.h
        key_enum/Input.h
        factory/lamp/Lamp.cpp
        factory/lamp/Lamp.h)

target_include_directories(${PROJECT_NAME} PRIVATE dependencies/raylib/include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/raylib/lib/libraylib.a)
target_link_libraries(${PROJECT_NAME} PRIVATE
        m
        pthread
        dl
        rt
        X11
)