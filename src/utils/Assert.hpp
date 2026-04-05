#pragma once

#if defined(SLIM_USE_ASSERTIONS) || !defined(NEBUG)

#include <cstdio>  // IWYU pragma: keep for std::printf()
#include <cstdlib> // IWYU pragma: keep for std::abort()

#define SLIM_ASSERT(expr, msg)                                                                               \
    do                                                                                                       \
    {                                                                                                        \
        if (!expr) [[unlikely]]                                                                              \
        {                                                                                                    \
            std::fprintf(stderr, "Slim assertion failed: %s (%s:%u). %s\n", #expr, __FILE__, __LINE__, msg); \
            std::abort();                                                                                    \
        }                                                                                                    \
    }                                                                                                        \
    while (false)

#else

#define SLIM_ASSERT(expr, msg) ((void)0u)

#endif // SLIM_USE_ASSERTIONS
