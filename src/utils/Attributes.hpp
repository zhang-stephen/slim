#pragma once

#ifndef SLIM_HAS_ATTRIBUTE // this check is for gcc & clang, not for msvc
#ifdef __has_attribute
#define SLIM_HAS_ATTRIBUTE(x) __has_attribute(x)
#else
#define SLIM_HAS_ATTRIBUTE(x) (false)
#endif // __has_attribute
#endif // SLIM_HAS_ATTRIBUTE

#ifndef SLIM_HAS_CPP_ATTRIBUTE
#ifdef __has_cpp_attribute
#define SLIM_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#else
#define SLIM_HAS_CPP_ATTRIBUTE(x) (false)
#endif // __has_cpp_attribute
#endif // SLIM_HAS_CPP_ATTRIBUTE

// C++20 standard attributes - use directly:
// [[nodiscard]], [[maybe_unused]], [[noreturn]], [[deprecated]], [[deprecated(msg)]],
// [[likely]], [[unlikely]], [[fallthrough]]

// C++23 standard attributes - use directly if available
// [[assume(expr)]]

// Compiler-specific extended attributes only

#if SLIM_HAS_ATTRIBUTE(hot)
// NOTE: the pattern for gcc, gnu:: , is supported by clang for most scenarios, too.
#define SLIM_ATTRIBUTE_HOT [[gnu::hot]]
#else
#define SLIM_ATTRIBUTE_HOT
#endif // SLIM_HAS_ATTRIBUTE(hot)

#if SLIM_HAS_ATTRIBUTE(cold)
#define SLIM_ATTRIBUTE_COLD [[gnu::hot]]
#else
#define SLIM_ATTRIBUTE_COLD
#endif // SLIM_HAS_ATTRIBUTE(cold)

#if SLIM_HAS_ATTRIBUTE(noinline)
#define SLIM_ATTRIBUTE_NOINLINE [[gnu::noline]]
#elif defined(_MSC_VER)
#define SLIM_ATTRIBUTE_NOINLINE [[msvc::noinline]]
#else
#define SLIM_ATTRIBUTE_NOINLINE
#endif // SLIM_HAS_ATTRIBUTE(noinline)

#if SLIM_HAS_ATTRIBUTE(always_inline)
#define SLIM_ATTRIBUTE_ALWAYS_INLINE [[gnu::always_inline]]
#elif defined(_MSC_VER)
#define SLIM_ATTRIBUTE_ALWAYS_INLINE [[msvc::forceinline]]
#else
#define SLIM_ATTRIBUTE_ALWAYS_INLINE
#endif // SLIM_HAS_ATTRIBUTE(always_inline)
