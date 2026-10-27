cmake_minimum_required(VERSION 4.3)
project(Raylib)

set(CMAKE_CXX_STANDARD 20)

add_executable(Raylib main.cpp
        components/PositionComponent.h
        components/VelocityComponent.h
        systems/RenderSystem.h
        systems/PlayerSystem.h
        systems/RobotSystem.h
        components/ColorComponent.h
        components/ModelComponent.h
        components/SizeComponent.h
        tags/Tags.h
        systems/CameraSystem.h
        systems/PlayerSystem.cpp
        systems/RenderSystem.cpp)

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