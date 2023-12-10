cmake_minimum_required(VERSION 3.13)

# project(unitTests)

enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(unitTests src/unitTests.cpp)
target_link_libraries(unitTests PUBLIC libRational GTest::GTest GTest::Main)
target_compile_features(unitTests PRIVATE cxx_std_17)

gtest_discover_tests(unitTests)


