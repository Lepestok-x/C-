cmake_minimum_required(VERSION 3.16)
project(My3DSurvivalGame CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# Настройки Bullet Physics
set(INSTALL_LIBS ON CACHE BOOL "" FORCE)
set(BUILD_BULLET3 OFF CACHE BOOL "" FORCE)
set(BUILD_EXTRAS OFF CACHE BOOL "" FORCE)
set(BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)

# 1. Подключаем физику Bullet
add_subdirectory(external/bullet3)

# Добавляем только наше приложение
add_executable(survival_game main.cpp
        entity/Ball2D.h
        entity/Bullet.h
        entity/Weapon.h
        entity/Ball.h)

# 2. Пути к заголовочным файлам Bullet
target_include_directories(survival_game PRIVATE external/bullet3/src)

# 3. Линковка всех системных зависимостей графики и сети
target_link_libraries(survival_game PRIVATE
        BulletDynamics
        BulletCollision
        LinearMath
        raylib
        GL
        asound
        X11
        Xrandr
        Xinerama
        Xi
        Xcursor
        pthread
        m
        dl
)
