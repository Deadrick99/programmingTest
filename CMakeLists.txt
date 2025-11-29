cmake_minimum_required(VERSION 3.15)

project(StrassenProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(strassen_lib
    src/matrix_utils.cpp
    src/standard.cpp
    src/strassen.cpp
)

target_include_directories(strassen_lib PUBLIC include)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE strassen_lib)

add_executable(validate src/validate.cpp)
target_link_libraries(validate PRIVATE strassen_lib)

add_executable(experiments src/experiments.cpp)
target_link_libraries(experiments PRIVATE strassen_lib)

enable_testing()
add_executable(tests src/tests.cpp)
target_link_libraries(tests PRIVATE strassen_lib)
add_test(NAME correctness COMMAND tests)
