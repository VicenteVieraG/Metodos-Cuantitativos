set(SDL_INCLUDES
    ${CMAKE_SOURCE_DIR}/include/SDL3/include
)

set_target_properties(SDL PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${SDL_INCLUDES}
)