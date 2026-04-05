#pragma once

#ifdef SLIM_NO_EXCEPTIONS

#include <cstdio>  // IWYU pragma: keep for std::printf()
#include <cstdlib> // IWYU pragma: keep for std::abort()

#define SLIM_REQUIRE(expr, err)                                                     \
    do                                                                              \
    {                                                                               \
        if (!expr) [[unlikely]]                                                     \
        {                                                                           \
            std::printf("Slim fatal error: %s (%s:%u)\n", err, __FILE__, __LINE__); \
            std::abort();                                                           \
        }                                                                           \
    }                                                                               \
    while (false)

#define SLIM_TRY         if constexpr (true)
#define SLIM_THROW(ex)   SLIM_REQUIRE(false, ex.what())
#define SLIM_CATCH       (e) if constexpr (false)
#define SLIM_CATCH_ALL() if constexpr (false)

#else

#define SLIM_TRY         try
#define SLIM_THROW(ex)   throw(ex)
#define SLIM_CATCH       (e) catch (e)
#define SLIM_CATCH_ALL() catch (...)

#endif // SLIM_NO_EXCEPTIONS
