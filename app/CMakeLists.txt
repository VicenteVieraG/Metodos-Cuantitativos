add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE ${RAND}
    PRIVATE ${PLOTGLC}
    # PRIVATE ${MUSIC}
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ./)