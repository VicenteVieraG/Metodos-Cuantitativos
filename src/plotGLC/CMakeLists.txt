add_library(${PLOTGLC} STATIC plotGLC.cpp)

target_link_libraries(${PLOTGLC}
    PRIVATE ${RAND}
    PRIVATE ${Boost_LIBRARIES}
    PRIVATE Python::Python
    PRIVATE Python::NumPy
)