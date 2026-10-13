cmake_minimum_required(VERSION 3.16)
project(my_clean_game CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем ТОЛЬКО ваш main.cpp
add_executable(${PROJECT_NAME} main.cpp)

# Подключаем стандартный raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)