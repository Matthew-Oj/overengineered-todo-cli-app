cmake_minimum_required(VERSION 3.15)

# Project name and language
project(todo LANGUAGES CXX)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files (create target FIRST)
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/todoapp.cpp
    src/task.cpp
)

# Include directory for headers
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Enable warnings (compiler-independent)
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Optional: set output name
set_target_properties(${PROJECT_NAME}
    PROPERTIES OUTPUT_NAME "todo"
)