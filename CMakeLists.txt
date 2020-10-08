cmake_minimum_required(VERSION 3.16)
project(my_math)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_math main.cpp my_matrix.cpp my_functions.cpp Analise.cpp my_math.h my_vector.cpp my_graph.cpp my_graph.h my_gauss.cpp my_gauss.h my_binary.cpp my_binary.h)