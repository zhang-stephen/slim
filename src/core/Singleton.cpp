export module slim.core:singleton;

export namespace slim
{

template <typename T>
class Singleton
{
public:
    static T& instance()
    {
        static Instance inst;
        return inst;
    }

private:
    struct Instance : public T {
        using T::T;
    };
};

} // namespace slim
