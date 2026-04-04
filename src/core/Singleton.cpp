export module slim.core:singleton;

export namespace slim
{

template <typename T>
class Singleton {
public:
    T& instance()
    {
        static Instance instance;

        return instance;
    }

private:
    struct Instance : public T
    {
        using T::T;
    };
};

} // namespace slim
