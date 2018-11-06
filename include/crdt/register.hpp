#ifndef __REGISTER_HPP_INCLUDED__
#define __REGISTER_HPP_INCLUDED__

#include <chrono>


namespace crdt
{


template <typename T>
class lwwregister
{
public:

    lwwregister(uint32_t id) : _id(id)
    {
    }

    void
    assign(T t)
    {
        auto now = std::chrono::high_resolution_clock::now();
        if (_time_point < now)
        {
            _t = t;
            _time_point = now;
        }
    }

    T
    value()
    {
        return _t;
    }

    bool
    compare(const lwwregister& other)
    {
        return _time_point < other._time_point ||
               (_time_point == other._time_point  && _id < other._id);
    }

    void
    merge(const lwwregister& other)
    {
        if (compare(other))
        {
            _t = other._t;
        }
    }

private:

    uint32_t _id;

    std::chrono::time_point<std::chrono::high_resolution_clock> _time_point;

    T _t;
};


}


#endif
