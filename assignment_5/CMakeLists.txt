cmake_minimum_required(VERSION 3.15)
project(assignment_5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_CFLAGS} -fopenmp")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")

add_executable(assignment_5 main.cpp Matrix.h Matrix.tpp GameObject.cpp GameObject.h)

target_link_libraries(assignment_5 sfml-graphics sfml-audio sfml-window sfml-system)