module;

#ifndef SLIM_USE_MODULAR_STL
#include <exception>
#include <string>
#endif // SLIM_USE_MODULAR_STL

export module utils:exception;

#ifdef SLIM_USE_MODULAR_STL
import std;
#endif // SLIM_USE_MODULAR_STL

export namespace slim::utils
{

class SlimException : public std::exception {
public:
    explicit SlimException(const char* message)
        : message_(message)
    {
    }

    explicit SlimException(std::string message)
        : message_(std::move(message))
    {
    }

    [[nodiscard]] auto what() const noexcept -> const char* override { return message_.c_str(); }

private:
    std::string message_;
};

} // namespace slim::utils
