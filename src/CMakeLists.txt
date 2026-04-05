add_subdirectory(utils)

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
        $<$<OR:$<BOOL:${SLIM_USE_SYSTEM_FMTLIB}>,$<BOOL:${SLIM_USE_VCPKG_FMTLIB}>>:"fmt::fmt">
        slim_utils
)

if (SLIM_EXPORT_HEADERS)
    target_link_libraries (slim
        PUBLIC
            slim_if
    )
endif ()
