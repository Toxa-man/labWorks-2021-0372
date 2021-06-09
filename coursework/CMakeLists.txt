cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

### Set Project name.
project(integer VERSION 0.1.0)

### Sets C++ 17 standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

### Add include compiler flags.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add Primary Generator source.
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hpp)

add_executable(carlos.out main.cpp ${sources} ${headers})
# target_link_libraries(exampleB1 <libraries>)
