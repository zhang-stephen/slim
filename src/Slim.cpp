module;

#include "Exception.hpp"

module slim;

import utils;

#ifdef SLIM_USE_MODULAR_STL
import std;
#endif

namespace slim
{
void log(const char* message) { SLIM_THROW(utils::SlimException("No implemented!")); }
} // namespace slim
