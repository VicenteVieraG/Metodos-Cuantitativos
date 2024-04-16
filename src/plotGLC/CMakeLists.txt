add_library(${PLOTGLC} STATIC plotGLC.cpp)

find_package(sciplot CONFIG REQUIRED)

target_link_libraries(${PLOTGLC}
    PRIVATE ${RAND}
    PRIVATE sciplot::sciplot
)