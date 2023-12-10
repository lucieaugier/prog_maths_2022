cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(libRational)

# add myLib
message(STATUS "libRational cmake part ..." )
add_subdirectory(libRational INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/libRational/include) # important : other projects call by this cmake will know this include directory

# add myCode
message(STATUS "myExamples cmake part ..." )
add_subdirectory(myExamples)

# add myTest
find_package(GTest OPTIONAL_COMPONENTS)
if(GTEST_FOUND)
	message(STATUS "unitTests cmake part ..." )
	add_subdirectory(unitTests)
elseif()
	message(WARNING "google test not found, skipping unitTests ..." )
endif()