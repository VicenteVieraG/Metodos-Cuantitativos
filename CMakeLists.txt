cmake_minimum_required(VERSION 3.24.1)

project(APLICACIONES_AVZ VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}\\bin)

# Libraries
set(RAND rand)
set(PLOTGLC plotGLC)

add_subdirectory(config)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(app)