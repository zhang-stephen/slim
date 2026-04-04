# -----------------------------------------------------------------------------
# options for features
# -----------------------------------------------------------------------------
option (SLIM_NO_EXCEPTIONS "Enable C++ Exceptions or not, off in default" off)
option (SLIM_NO_THREAD_NAME_SUPPORT "Disable Thread Name supports, off in default" off)
option (SLIM_USE_ASSERTIONS "Enable C++ Assertions in Release Building, off in default" off)
option (SLIM_USE_SEQUENTIAL_THREAD_ID "Use Sequential thread ID instead of fetching by system APIs, off in default" off)
option (SLIM_USE_MODULAR_STL "Use modularized STL or not if C++23 and newer enabled, off in default" off)
option (SLIM_USE_VCPKG_FMTLIB "Use default fmtlib installed in system, off in default" off)
option (SLIM_USE_SYSTEM_FMTLIB "Use system installed fmtlib instead of vcpkg, off in default" off)
option (SLIM_USE_SYSTEM_GTEST "Use system install GTest instead of vcpkg, off in default" off)

# -----------------------------------------------------------------------------
# convert features to global C++ macros
# -----------------------------------------------------------------------------
add_compile_definitions (
    $<$<BOOL:${SLIM_NO_EXCEPTIONS}>:SLIM_NO_EXCEPTIONS>
    $<$<BOOL:${SLIM_USE_ASSERTIONS}>:SLIM_USE_ASSERTIONS>
    $<$<BOOL:${SLIM_NO_THREAD_NAME_SUPPORT}>:SLIM_NO_THREAD_NAME_SUPPORT>
    $<$<BOOL:${SLIM_USE_SEQUENTIAL_THREAD_ID}>:SLIM_USE_SEQUENTIAL_THREAD_ID>
    $<$<BOOL:${SLIM_USE_MODULAR_STL}>:SLIM_USE_MODULAR_STL>
    # SLIM_USE_STL_FMTLIB would be defined if fmtlib installed from system or vcpkg is both disabled.
    # but there would be an error occurred if C++20 was enabled
    $<$<NOT:$<OR:$<BOOL:${SLIM_USE_SYSTEM_FMTLIB}>,$<BOOL:${SLIM_USE_VCPKG_FMTLIB}>>>:SLIM_USE_STL_FMTLIB>
)

# -----------------------------------------------------------------------------
# options for building
# -----------------------------------------------------------------------------
option (SLIM_EXPORT_HEADERS "Export Headers for alternative way integrated, off in default" off)
option (SLIM_BUILD_TESTS "Build Unit Test or not, off in default" off)
option (SLIM_BUILD_EXAMPLES "Build Examples or not, off in default" off)
option (SLIM_CODE_COVERAGE "Build and Report code coverage, off in default" off)

# -----------------------------------------------------------------------------
# options for checkers (llvm required, or false-positive results would be fetched)
# -----------------------------------------------------------------------------
option (SLIM_ENABLE_VALGRIND "Use valgrind as default checker of memory usage" off)
option (SLIM_ENABLE_ASAN "Use AddrSanitizer as default checker of memory usage" off)
option (SLIM_ENABLE_TSAN "Use ThreadSanitizer to check thread-related issues" off)

# -----------------------------------------------------------------------------
# print SLIM options
# -----------------------------------------------------------------------------
message (STATUS "Slim Options:")
message (STATUS "  CMAKE_CXX_STANDARD: C++${CMAKE_CXX_STANDARD}")
message (STATUS "  SLIM_NO_EXCEPTIONS: ${SLIM_NO_EXCEPTIONS}")
message (STATUS "  SLIM_USE_ASSERTIONS: ${SLIM_USE_ASSERTIONS}")
message (STATUS "  SLIM_NO_THREAD_NAME_SUPPORT: ${SLIM_NO_THREAD_NAME_SUPPORT}")
message (STATUS "  SLIM_USE_SEQUENTIAL_THREAD_ID: ${SLIM_USE_SEQUENTIAL_THREAD_ID}")
message (STATUS "  SLIM_USE_MODULAR_STL: ${SLIM_USE_MODULAR_STL}")
message (STATUS "  SLIM_USE_VCPKG_FMTLIB: ${SLIM_USE_VCPKG_FMTLIB}")
message (STATUS "  SLIM_USE_SYSTEM_GTEST: ${SLIM_USE_SYSTEM_GTEST}")
message (STATUS "  SLIM_USE_SYSTEM_FMTLIB: ${SLIM_USE_SYSTEM_FMTLIB}")
message (STATUS "  SLIM_EXPORT_HEADERS: ${SLIM_EXPORT_HEADERS}")
message (STATUS "  SLIM_BUILD_TESTS: ${SLIM_BUILD_TESTS}")
message (STATUS "  SLIM_BUILD_EXAMPLES: ${SLIM_BUILD_EXAMPLES}")
message (STATUS "  SLIM_CODE_COVERAGE: ${SLIM_CODE_COVERAGE}")
message (STATUS "  SLIM_ENABLE_VALGRIND: ${SLIM_ENABLE_VALGRIND}")
message (STATUS "  SLIM_ENABLE_ASAN: ${SLIM_ENABLE_ASAN}")
message (STATUS "  SLIM_ENABLE_TSAN: ${SLIM_ENABLE_TSAN}")
