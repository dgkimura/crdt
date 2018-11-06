#ifndef __REGISTER_HPP_INCLUDED__
#define __REGISTER_HPP_INCLUDED__


namespace crdt
{


template <typename T>
class lwwregister
{
public:

    lwwregister(uint32_t id) : _id(id), _time_point(0)
    {
    }

    void
    assign(T t)
    {
        _time_point += 1;
        _t = t;
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
            _time_point = other._time_point;
        }
    }

private:

    uint32_t _id;

    uint32_t _time_point;

    T _t;
};


}


#endif
