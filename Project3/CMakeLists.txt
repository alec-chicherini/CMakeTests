cmake_minimum_required(VERSION 3.8)

cmake_policy(SET CMP0074 OLD)

project(PROJECT_3)

find_package(Boost)

if(NOT Boost_FOUND)
	message(SEND_ERROR "Boost not found.")
	return()
else() 
	message(NOTICE "Boost_INCLUDE_DIRS = ")
	message(NOTICE ${Boost_INCLUDE_DIRS})	
	include_directories(${Boost_INCLUDE_DIRS})
endif()

set(SOURCE_EXE boost_example.cpp)

add_executable(project3 ${SOURCE_EXE})

