module;

#include "Exception.hpp"

module slim;

import slim.core;

#ifdef SLIM_USE_MODULAR_STL
import std;
#endif

namespace slim
{
void log(const char* message) { SLIM_THROW(SlimException("No implemented!")); }
} // namespace slim
