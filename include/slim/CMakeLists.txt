if (NOT SLIM_EXPORT_HEADERS)
    return ()
endif ()

add_library(slim_if INTERFACE)

target_include_directories(slim_if
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(slim_if
    INTERFACE
        FILE_SET slim_pub_headers
        TYPE HEADERS
        FILES slim.hpp
)
