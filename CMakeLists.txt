cmake_minimum_required(VERSION 3.16)
project(my_clean_game CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp service_code/Player.h
        service_code/Ground.h
        service_code/Listener.h
        service_code/btGravitate.h
        service_code/BodyCollision.h
        service_code/Cor.h)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)