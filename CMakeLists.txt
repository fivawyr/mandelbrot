cmake_minimum_required(VERSION 3.16)
project(mandelbrot_simulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(SDL2 REQUIRED)

add_executable(main code.c)
target_link_libraries(main SDL2::SDL2)
target_include_directories(main PUBLIC /opt/homebrew/include)
