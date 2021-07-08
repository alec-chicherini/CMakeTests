cmake_minimum_required(VERSION 3.20)

project(project_generation VERSION 1.0.0 LANGUAGES CXX)



option(use_hello "Build the main source file with word 'Hello'" NO)
option(use_world "Build the main source file with word 'World'" NO)

file(GENERATE OUTPUT generated_src/main.cpp CONTENT
"
#include <iostream>
#define USE_HELLO_${use_hello}
#define USE_WORLD_${use_world}

int main()
{
std::cout<<\"Result message:\"<<
#ifdef USE_HELLO_YES
\"Hello \"<<
#endif
#ifdef USE_WORLD_YES
\"World\"<<
#endif
std::endl;
return 1;
}
"
)

add_executable(proj_gen generated_src/main.cpp)

#cmake . -Duse_hello=YES -Duse_world=YES; cmake --build .;
