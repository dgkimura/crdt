#include <functional>
#include <numeric>

#include "crdt/counter.hpp"


namespace crdt
{


gcounter::gcounter(uint32_t id)
    : _id(id),
      _positive_counter(id + 1)
{
}


void
gcounter::increment(uint32_t value)
{
    _positive_counter[_id] += value;
}


int
gcounter::query()
{
    return std::accumulate(_positive_counter.begin(), _positive_counter.end(),
                           0);
}


bool
gcounter::compare(const gcounter& other)
{
    for (int i=0; i<_positive_counter.size(); i++)
    {
        if (other._positive_counter[i] < _positive_counter[i])
        {
            return false;
        }
    }

    return true;
}


void
gcounter::merge(const gcounter& other)
{
    if (_positive_counter.size() < other._positive_counter.size())
    {
        _positive_counter.resize(other._positive_counter.size());
    }

    for (int i=0; i< _positive_counter.size(); i++)
    {
        _positive_counter[i] = std::max<uint32_t>(_positive_counter[i],
                                                  other._positive_counter[i]);
    }
}


pncounter::pncounter(uint32_t id)
    : _id(id),
      _positive_counter(id + 1),
      _negative_counter(id + 1)
{
}


void
pncounter::increment(uint32_t value)
{
    _positive_counter[_id] += value;
}


void
pncounter::decrement(uint32_t value)
{
    _negative_counter[_id] += value;
}


int
pncounter::query()
{
    return std::accumulate(_positive_counter.begin(),
                           _positive_counter.end(), 0) -
           std::accumulate(_negative_counter.begin(),
                           _negative_counter.end(), 0);
}


bool
pncounter::compare(const pncounter& other)
{
    for (int i=0; i<_positive_counter.size(); i++)
    {
        if (other._positive_counter[i] < _positive_counter[i] ||
            other._negative_counter[i] < _negative_counter[i])
        {
            return false;
        }
    }

    return true;
}


void
pncounter::merge(const pncounter& other)
{
    if (_positive_counter.size() < other._positive_counter.size())
    {
        _positive_counter.resize(other._positive_counter.size());
    }

    for (int i=0; i< _positive_counter.size(); i++)
    {
        _positive_counter[i] = std::max<uint32_t>(_positive_counter[i],
                                                  other._positive_counter[i]);
        _negative_counter[i] = std::max<uint32_t>(_negative_counter[i],
                                                  other._negative_counter[i]);
    }
}


}
