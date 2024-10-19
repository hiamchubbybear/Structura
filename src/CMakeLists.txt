# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.0)

# Define the project name
project(Structura)

# Set the C++ standard version (optional, recommended for modern C++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable by specifying the source file
add_executable(main.cpp)

# Optionally, you can link libraries if needed
# target_link_libraries(Structura <library_name>)
