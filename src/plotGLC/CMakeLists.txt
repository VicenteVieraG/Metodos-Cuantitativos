add_library(${PLOTGLC} STATIC plotGLC.cpp)

target_link_libraries(${PLOTGLC}
    PRIVATE ${RAND}

    # PRIVATE ROOT::Hist
    # PRIVATE ROOT::Gui
    # PRIVATE ROOT::RIO
)