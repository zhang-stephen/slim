module;

#ifndef SLIM_USE_MODULAR_STL
#include <atomic>
#endif // SLIM_USE_MODULAR_STL

export module utils:spinlock;

#ifdef SLIM_USE_MODULAR_STL
import std;
#endif // SLIM_USE_MODULAR_STL

import :noncopyable;

export namespace slim::utils
{
class SpinLock : public NonCopyable {
    std::atomic_flag flag_;

public:
    SpinLock() = default;

    bool try_lock() { return flag_.test_and_set(std::memory_order_acquire); }

    void lock()
    {
        while (try_lock()) { flag_.wait(true, std::memory_order_relaxed); }
    }

    void unlock()
    {
        flag_.clear(std::memory_order_release);
        flag_.notify_one();
    }
};
} // namespace slim::utils
