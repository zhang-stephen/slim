add_subdirectory(core)

add_library(slim STATIC)

target_sources(slim
    PUBLIC
        FILE_SET slim_module_top_if
        TYPE CXX_MODULES
        FILES slim.ixx
    PRIVATE
        slim.cpp
)

target_link_libraries(slim
    PRIVATE
        fmt::fmt
        slim_core
)

if (SLIM_EXPORT_HEADERS)
    target_link_libraries (slim
        PUBLIC
            slim_if
    )
endif ()
