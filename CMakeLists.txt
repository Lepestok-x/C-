cmake_minimum_required(VERSION 4.3)
project(Raylib)
set(CMAKE_CXX_STANDARD 20)
add_executable(Raylib main.cpp
        configurations/SettingsCamera.h
        configurations/Box.h
        configurations/Floor.h
        configurations/Collision.h
)
target_include_directories(Raylib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/raylib/include)

target_link_libraries(Raylib PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/raylib/lib/libraylib.a
        GL
        m
        pthread
        dl
        rt
        X11)
