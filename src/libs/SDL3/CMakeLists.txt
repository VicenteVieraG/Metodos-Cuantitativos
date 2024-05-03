add_library(SDL STATIC IMPORTED GLOBAL)

set_target_properties(SDL PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/libs/SDL3/SDL3.lib
)