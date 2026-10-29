cmake_minimum_required(VERSION 4.3)
project(Raylib)

set(CMAKE_CXX_STANDARD 20)

add_executable(Raylib main.cpp tags/Tags.h
        engine/Engine.cpp
        engine/Engine.h
        components/Components.h
        systems/PlayerSystem.h
        systems/PlayerSystem.cpp
        systems/RenderSystem.cpp
        systems/RenderSystem.h
        systems/GlassSystem.cpp
        systems/GlassSystem.h
        systems/LampSystem.cpp
        systems/LampSystem.h
        entities/Entity.cpp
        entities/Entity.h
        systems/CameraSystem.cpp
        systems/CameraSystem.h
        systems/CameraSystem.cpp
        entities/Entity.cpp
        systems/GravitySystem.cpp
        systems/GravitySystem.h
        systems/PhysicsSystem.cpp
        systems/PhysicsSystem.h)

target_include_directories(${PROJECT_NAME} PRIVATE dependencies/raylib/include)
target_include_directories(${PROJECT_NAME} PRIVATE dependencies/entt)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/raylib/lib/libraylib.a)

target_link_libraries(${PROJECT_NAME} PRIVATE
        m
        pthread
        dl
        rt
        X11
)