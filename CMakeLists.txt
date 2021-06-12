cmake_minimum_required(VERSION 3.17)

# set the project name
project(c__demo)
# set the c++ standard
set(CMAKE_CXX_STANDARD 11)

add_library(c__demo
        demo.cpp)

#############################################
# Unit tests
add_subdirectory(3rd_party/google-test)
# enable CTest testing
enable_testing()
# Add a testing executable
add_executable(unit_tests unit_tests.cpp base_tests.cpp 3.h)

target_link_libraries(unit_tests
        c__demo
        GTest::GTest
        GTest::Main
)
add_test(test_all unit_tests)