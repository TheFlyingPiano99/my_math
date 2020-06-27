cmake_minimum_required(VERSION 3.16)
project(my_math)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_math main.cpp my_matrix.cpp my_functions.cpp Analise.cpp my_math.h my_vectors.cpp)