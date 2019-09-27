cmake_minimum_required(VERSION 3.15)
project(assignment_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment_5 main.cpp Matrix.h Matrix.tpp GameObject.cpp GameObject.h)

target_link_libraries(assignment_5 sfml-graphics sfml-audio sfml-window sfml-system)