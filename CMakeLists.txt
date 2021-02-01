cmake_minimum_required(VERSION 3.16)
project(my_math)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_math main.cpp lib/matrix/my_matrix.cpp lib/functions/my_functions.cpp lib/analise/Analise.cpp lib/my_math.h lib/vector/my_vector.cpp lib/graph/my_graph.cpp lib/graph/my_graph.h lib/gauss/my_gauss.cpp lib/gauss/my_gauss.h lib/binary/my_binary.cpp lib/binary/my_binary.h lib/geometry/my_geometry.cpp lib/geometry/my_geometry.h lib/relativity/my_special_relativity.cpp lib/relativity/my_special_relativity.h lib/current/current.cpp lib/current/current.h)