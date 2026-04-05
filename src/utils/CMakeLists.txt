add_library(slim_utils STATIC)

target_sources(slim_utils
    PUBLIC
        FILE_SET module_slim_utils
        TYPE CXX_MODULES
        FILES
            Utils.ixx
            Execption.cpp
            NonCopyable.cpp
            NonMovable.cpp
            Singleton.cpp
            SpinLock.cpp
)

target_include_directories(slim_utils
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
