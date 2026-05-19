cmake_minimum_required(VERSION 3.16)

project(MatrixMultiplication VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)


set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(matrix_lib
    src/Matrix.cpp    
)


target_include_directories(matrix_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(matrix_app
    src/main.cpp
)

target_link_libraries(matrix_app PRIVATE matrix_lib)