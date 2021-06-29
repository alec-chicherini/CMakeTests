# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#

cmake_minimum_required (VERSION 3.8)

project ("CMAKE_SOLUTION")

include_directories("include")

# Include sub-projects.
add_subdirectory ("CMakeProject1")
add_subdirectory ("CMakeProject2")
add_subdirectory ("Project3")
add_subdirectory ("Project4")
add_subdirectory("ProjectTimedelay")
