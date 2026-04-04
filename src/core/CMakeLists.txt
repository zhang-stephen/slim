add_library(slim_core STATIC)

target_sources(slim_core
    PUBLIC
        FILE_SET module_slim_core
        TYPE CXX_MODULES
        FILES
            Core.ixx
            Execption.cpp
            NonCopyable.cpp
            NonMovable.cpp
            Singleton.cpp
)

target_include_directories(slim_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
