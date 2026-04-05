export module utils:nonmovable;

export namespace slim::utils
{

class NonMovable {
public:
    NonMovable()  = default;
    ~NonMovable() = default;

    NonMovable(const NonMovable&)            = default;
    NonMovable& operator=(const NonMovable&) = default;

    NonMovable(NonMovable&&)            = delete;
    NonMovable& operator=(NonMovable&&) = delete;
};

} // namespace slim::utils
