cmake_minimum_required(VERSION 3.24.1)

project(APLICACIONES_AVZ VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}\\bin)

# Libraries
set(RAND rand)
set(PLOTGLC plotGLC)
set(MUSIC music)

find_package(Boost REQUIRED)

if(Boost_FOUND)
    message(STATUS "BOOST VERSION: " ${Boost_VERSION})

    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARIES})
endif()

add_subdirectory(config)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(app)