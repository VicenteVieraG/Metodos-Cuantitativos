add_library(${MUSIC} STATIC music.cpp)

target_link_libraries(${MUSIC} PRIVATE SDL)