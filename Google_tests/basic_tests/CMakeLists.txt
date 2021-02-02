include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/MyMathLib/include)

add_executable(matrix_test MatrixTest.cpp)

target_link_libraries(matrix_test gtest gtest_main)
target_link_libraries(matrix_test MyMathLib)
