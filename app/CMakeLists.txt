add_executable(${CMAKE_PROJECT_NAME} main.cpp)

find_package(sciplot CONFIG REQUIRED)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE ${RAND}
    PRIVATE sciplot::sciplot
)