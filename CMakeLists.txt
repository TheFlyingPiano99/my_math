cmake_minimum_required(VERSION 3.16)
project(MyMathDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

configure_file(Config.h.in Config.h)


add_subdirectory(MyMathLib)
add_subdirectory(Google_tests)

LIST(APPEND EXTRA_LIBS MyMathLib)
LIST(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/MyMathLib/include)

add_executable(MyMathDemo main.cpp)

target_link_libraries(MyMathDemo ${EXTRA_LIBS})

target_include_directories(MyMathDemo PUBLIC
        ${PROJECT_BINARY_DIR}
        ${EXTRA_INCLUDES}
)
