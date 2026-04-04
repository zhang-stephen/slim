cmake_minimum_required (VERSION 3.30)

# -----------------------------------------------------------------------------
# local cmake modules
# -----------------------------------------------------------------------------
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")
include (SlimOptions)

# -----------------------------------------------------------------------------
# options should be processed before project()
# -----------------------------------------------------------------------------
set (CMAKE_CXX_STANDARD_REQUIRED on)

if (NOT CMAKE_CXX_STANDARD)
    set (CMAKE_CXX_STANDARD 23)
endif ()

if (CMAKE_CXX_STANDARD LESS 20)
    message (FATAL_ERROR "Slim requires C++20 at least, please enable C++20 or newer before building")
elseif (CMAKE_CXX_STANDARD LESS 23)
    if (SLIM_USE_MODULAR_STL)
        message (FATAL_ERROR "Modularized STL could be enabled for C++23 at least, please enable C++23 or newer before building")
    endif ()
endif ()

if (SLIM_USE_VCPKG_FMTLIB)
    list (APPEND VCPKG_MANIFEST_FEATURES "fmt")
endif ()

if (SLIM_BUILD_TESTS AND (NOT SLIM_USE_SYSTEM_GTEST))
    list (APPEND VCPKG_MANIFEST_FEATURES "test")
endif ()

# -----------------------------------------------------------------------------
# determine if it is built as subproject e.g. add_subdirectory in other repo
# -----------------------------------------------------------------------------
project (slim)
set (SLIM_BUILT_TOP_LEVEL false CACHE BOOL "built as subdirectory or not" FORCE)
if (${PROJECT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(SLIM_BUILT_TOP_LEVEL true CACHE BOOL "built as subdirectory or not" FORCE)
endif ()

# -----------------------------------------------------------------------------
# project declarations
# -----------------------------------------------------------------------------
project (slim
    VERSION 0.0.1
    LANGUAGES CXX # C # C++ enabled only
    DESCRIPTION
        "Slim: Logging In Modern! A light-weighted & high-performance C++ logging lib, based on C++20 and newer"
)


# -----------------------------------------------------------------------------
# check for module supports
# -----------------------------------------------------------------------------
message (STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
if (SLIM_USE_MODULAR_STL)
    if (APPLE)
        if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
            # see https://github.com/llvm/llvm-project/issues/109895
            # see https://github.com/Homebrew/homebrew-core/issues/226050
            message (FATAL_ERROR "Modularized STL is not supported on Apple MacOS with Clang yet!")
        # elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        #     # FIXME: not working with the workaroud
        #     # in fact, the gcc 15.1+ on apple, installed by homebrew, cannot work with modularized STL
        #     # see https://gcc.gnu.org/bugzilla/show_bug.cgi?id=116827
        #     message (WARNING "Disable module scanning for gcc on Apple MacOS!")
        #     set (CMAKE_CXX_SCAN_FOR_MODULES off)
        endif ()
    endif ()

    if (LINUX AND (CMAKE_CXX_COMPILER_ID STREQUAL GNU))
        # HACK: the way to check should be verified in the near future
        find_program (LSB_RELEASE lsb_release)
        if (LSB_RELEASE)
            execute_process (COMMAND ${LSB_RELEASE} -is OUTPUT_VARIABLE DISTRO OUTPUT_STRIP_TRAILING_WHITESPACE)
            execute_process (COMMAND ${LSB_RELEASE} -rs OUTPUT_VARIABLE DISTRO_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
            if (DISTRO STREQUAL "Ubuntu" AND DISTRO_VERSION VERSION_LESS "26.04")
                message (FATAL_ERROR "Modularized STL is not supported on Ubuntu ${DISTRO_VERSION}. Please use Ubuntu 26.04 or newer.")
            endif ()
        endif ()
    endif ()
endif ()

# -----------------------------------------------------------------------------
# option processing after project()
# -----------------------------------------------------------------------------
if (SLIM_BUILD_TESTS)
    include (CTest)
    find_package (GTest 1.15.0 REQUIRED)

    if (SLIM_ENABLE_ASAN OR SLIM_ENABLE_LSAN OR SLIM_ENABLE_MSAN OR SLIM_ENABLE_TSAN OR SLIM_ENABLE_UBSAN)
        if (NOT (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")) # use sanitizers for LLVM only
            message (FATAL_ERROR "Sanitizers can be enabled for LLVM toolchain!")
        endif ()
    endif ()
endif ()

# -----------------------------------------------------------------------------
# required packages
# -----------------------------------------------------------------------------
find_package (Threads REQUIRED)

if (SLIM_USE_SYSTEM_FMTLIB OR SLIM_USE_VCPKG_FMTLIB)
    find_package (fmt 11.0.2 REQUIRED)
endif ()

# -----------------------------------------------------------------------------
# subdirectrios
# -----------------------------------------------------------------------------
add_subdirectory ("include/slim")
add_subdirectory (src)
