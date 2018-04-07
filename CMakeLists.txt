cmake_minimum_required(VERSION 2.8)

project("Socket Test Code")

# Set the executable output directory
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")

# Grab all of the source code
file(GLOB_RECURSE C_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# Set compilation flags and compilers
set(CMAKE_C_FLAGS "-std=c11 -O3 -Wextra")
set(CMAKE_C_COMPILER gcc)

# Add executables
add_executable(server.out ${C_SRC})

# Link static library
target_link_libraries(server.out)
