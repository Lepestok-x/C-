cmake_minimum_required(VERSION 3.20)
project(RaylibShader)

set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} main.cpp
        component/Component.h
        tag/Tags.h
        engine/EnginePhysics.cpp
        engine/EnginePhysics.h
        system/render_system/RenderSystem.cpp
        system/render_system/RenderSystem.h
        factory/Factory.cpp
        factory/Factory.h
        system/player_system/PlayerSystem.cpp
        system/player_system/PlayerSystem.h
        system/movement_system/MovementSystem.cpp
        system/movement_system/MovementSystem.h
        system/camera_system/CameraSystem.cpp
        system/camera_system/CameraSystem.h)

target_include_directories(${PROJECT_NAME} PRIVATE dependencies/raylib/include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/raylib/lib/libraylib.a)
target_include_directories(${PROJECT_NAME} PRIVATE dependencies/entt)
target_link_libraries(${PROJECT_NAME} PRIVATE
        m
        pthread
        dl
        rt
        X11
)