export module slim.core:noncopyable;

export namespace slim
{

class NonCopyable
{
public:
    NonCopyable()  = default;
    ~NonCopyable() = default;

    NonCopyable(const NonCopyable&)            = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;

    NonCopyable(NonCopyable&&)            = default;
    NonCopyable& operator=(NonCopyable&&) = default;
};

} // namespace slim
