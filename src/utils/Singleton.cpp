export module utils:singleton;

export namespace slim::utils
{

template <typename T>
class Singleton {
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

} // namespace slim::utils
