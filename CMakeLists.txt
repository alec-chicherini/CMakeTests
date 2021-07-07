# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#

cmake_minimum_required (VERSION 3.8)

project ("CMAKE_SOLUTION")

include_directories("include")

set(P1_DIR "CMakeProject1")
set(P2_DIR "CMakeProject2")
set(P3_DIR "Project3")
set(P4_DIR "Project4")
set(PT_DIR "ProjectTimedelay")
set(PM_DIR "ProjectMulty")
set(PTUT_DIR "ProjectTutorial")

# Include sub-projects.
add_subdirectory(${P1_DIR} ${P1_DIR}/build)
add_subdirectory(${P2_DIR} ${P2_DIR}/build)
add_subdirectory(${P3_DIR} ${P3_DIR}/build)
add_subdirectory(${P4_DIR} ${P4_DIR}/build)
add_subdirectory(${PT_DIR} ${PT_DIR}/build)
add_subdirectory(${PM_DIR} ${PM_DIR}/build)
add_subdirectory(${PTUT_DIR} ${PTUT_DIR}/build)

#tests
include(CTest)
add_test(NAME test1 COMMAND project1.exe WORKING_DIRECTORY ${P1_DIR}/build)
add_test(NAME test2 COMMAND project2.exe WORKING_DIRECTORY ${P2_DIR}/build)
add_test(NAME test3 COMMAND project3.exe WORKING_DIRECTORY ${P3_DIR}/build)
add_test(NAME test4 COMMAND project4.exe WORKING_DIRECTORY ${P4_DIR}/build)
add_test(NAME testM COMMAND project_m.exe WORKING_DIRECTORY ${PM_DIR}/build)
add_test(NAME testT COMMAND project_timedelay.exe WORKING_DIRECTORY ${PT_DIR}/build)
add_test(NAME testTUT COMMAND project_tutorial.exe WORKING_DIRECTORY ${PTUT_DIR}/build)
set_tests_properties(testTUT PROPERTIES
PASS_REGULAR_EXPRESSION "CMAKE TUTORIAL")