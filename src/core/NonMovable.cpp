export module slim.core:nonmovable;

export namespace slim
{

class NonMovable {
public:
    NonMovable() = default;
    ~NonMovable() = default;

    NonMovable(const NonMovable&) = default;
    NonMovable& operator=(const NonMovable&) = default;

    NonMovable(NonMovable&&) = delete;
    NonMovable& operator=(NonMovable&&) = delete;
};

} // namespace slim
