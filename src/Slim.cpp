module;

#include "Exception.hpp"

module slim;

import slim.core;

// Note: import std requires compiler support and pre-compiled std module.
// On Clang with libc++, this is not yet widely available.
// For now, we use traditional includes which work reliably.
#ifdef SLIM_USE_MODULAR_STL
import std;
#endif

namespace slim
{
void log(const char* message)
{
    SLIM_THROW(SlimException("No implemented!"));
}
} // namespace slim
