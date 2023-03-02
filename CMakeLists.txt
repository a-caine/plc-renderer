# Define the cmake version
cmake_minimum_required(VERSION 3.20)

# Set the project name and version
project(PLCRenderer VERSION 0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SFML shared libraries
find_package(SFML 2.5
    COMPONENTS
        system window graphics network audio REQUIRED    
)

# Add the main executable
add_executable(PLCRenderer src/main.cpp src/filereader.cpp)

# Link the executable to required SFML libraries
target_link_libraries(PLCRenderer sfml-graphics)

# Add the binary tree to the search path for include files
target_include_directories(PLCRenderer PRIVATE
    "${PROJECT_BINARY_DIR}/src"                            
)