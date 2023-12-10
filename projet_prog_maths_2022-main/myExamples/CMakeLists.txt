cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(myExamples)


add_executable(myExamples src/main.cpp)                # file to compile and name of the app
target_link_libraries(myExamples PRIVATE libRational)      # lib dependency

# compilation flags
target_compile_features(myExamples PRIVATE cxx_std_17) # use at least c++ 14
if (MSVC)
    target_compile_options(myExamples PRIVATE /W3)
else()
    target_compile_options(myExamples PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()


