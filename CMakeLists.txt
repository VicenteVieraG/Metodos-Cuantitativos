cmake_minimum_required(VERSION 3.24.1)

project(APLICACIONES_AVZ VERSION 0.0.0 LANGUAGES C CXX)

# set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}\\bin)
set(CMAKE_PREFIX_PATH C:\\root\\root_install\\cmake) # ROOT Configuration file path

# Libraries
set(RAND rand)
set(PLOTGLC plotGLC)

find_package(ROOT REQUIRED COMPONENTS RIO Hist Gui)

if(${ROOT_FOUND})
    include(${ROOT_USE_FILE})

    set(CMAKE_CXX_STANDARD ${ROOT_CXX_STANDARD})
    message(STATUS CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD})
    message(STATUS ROOT_CXX_STANDARD: ${ROOT_CXX_STANDARD})
endif()

add_subdirectory(config)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(app)