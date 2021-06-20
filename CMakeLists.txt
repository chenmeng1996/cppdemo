cmake_minimum_required(VERSION 3.17)

# set the project name
project(cppdemo)
# set the c++ standard
set(CMAKE_CXX_STANDARD 11)

add_library(cppdemo_lib
        empty.cpp vector.h function_object.h)
add_executable(cppdemo_exec
        main.cpp)

#############################################
# Unit tests
add_subdirectory(3rd_party/google-test)
# enable CTest testing
enable_testing()
# Add a testing executable
add_executable(unit_tests unit_tests.cpp base_tests.cpp init_tests.cpp vector_tests.cpp function_object_tests.cpp)

target_link_libraries(unit_tests
        cppdemo_lib
        GTest::GTest
        GTest::Main
)
add_test(test_all unit_tests)