cmake_minimum_required(VERSION 3.10)
project(lynx_app_main)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compile flags
add_compile_options(-Wall -O2 -g)

# Source directories
set(SRC_DIRS
    00_application_software
    ../01_event_driven_kernel
)

# Collect all source files
file(GLOB_RECURSE SOURCES
    ${SRC_DIRS}/*.cpp
)

# Include directories
include_directories(${SRC_DIRS})

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME}
    pthread
    rt
)

# Optional: Custom build types
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -DDEBUG -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -Wextra -Werror")
