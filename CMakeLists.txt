cmake_minimum_required(VERSION 3.24.1)

project(APLICACIONES_AVZ VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}\\bin)

# Libraries
set(RAND rand)
set(PLOTGLC plotGLC)

find_package(Boost REQUIRED)

if(${Boost_FOUND})
    message(STATUS "BOOST VERSION: " ${Boost_VERSION})
endif()

set(Python_NumPy_INCLUDE_DIR C:\\Users\\plant\\scoop\\apps\\python\\3.12.2\\Lib\\site-packages\\numpy\\core\\include)
find_package(Python COMPONENTS Interpreter Development NumPy REQUIRED)

if(${Python_FOUND})
    message(STATUS "PYHON VERSION: ${Python_VERSION}")

    if(${Python_Interpreter_FOUND})
        message(STATUS "PYTHON INTERPRETER FOUND")
    endif()

    if(${Python_Development_FOUND})
        message(STATUS "PYTHON DEVELOPMENT FOUND")
    endif()

    if(${Python_NumPy_FOUND})
        message(STATUS "NUMPY FOUND")
    endif()
endif()

add_subdirectory(config)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(app)