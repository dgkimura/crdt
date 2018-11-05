#ifndef __REGISTER_HPP_INCLUDED__
#define __REGISTER_HPP_INCLUDED__

#include <set>


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
    }

    T
    value()
    {
    }

    bool
    compare(const lwwregister& other)
    {
        return true;
    }

    void
    merge(const lwwregister& other)
    {
    }

private:

    uint32_t _id;

    T t;
};


}


#endif
