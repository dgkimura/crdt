#ifndef __SET_HPP_INCLUDED__
#define __SET_HPP_INCLUDED__

#include <set>
#include <string>
#include <tuple>
#include <vector>


namespace crdt
{


template <typename T>
class orset
{
public:

    orset(uint32_t id) : _id(id), _counter(0)
    {
    }

    bool
    lookup(T t)
    {
        for (const auto&i : _elements)
        {
            if (std::get<0>(i) == t)
            {
                return true;
            }
        }
        return false;
    }

    void
    add(T t)
    {
        auto unique_id = std::to_string(_id) + std::to_string(_counter++);
        _elements.insert(std::make_tuple(t, unique_id));
    }

    void
    remove(T t)
    {
        std::vector<std::tuple<T, std::string>> removed_elements;

        for (const auto&i : _elements)
        {
            if (std::get<0>(i) == t)
            {
                _tombstones.insert(i);
                removed_elements.push_back(i);
            }
        }

        for (const auto&i : removed_elements)
        {
            _elements.erase(i);
        }
    }

    bool
    compare(const orset& other)
    {
        for (const auto& e : _elements)
        {
            if (other._elements.find(e) == other._elements.end())
            {
                return false;
            }
        }

        for (const auto& e : _tombstones)
        {
            if (other._tombstones.find(e) == other._tombstones.end())
            {
                return false;
            }
        }
        return true;
    }

    void
    merge(const orset& other)
    {
        _elements.insert(other._elements.begin(), other._elements.end());
        _tombstones.insert(other._tombstones.begin(), other._tombstones.end());
    }

private:

    uint32_t _id;

    uint32_t _counter;

    std::set<std::tuple<T, std::string>> _elements;

    std::set<std::tuple<T, std::string>> _tombstones;
};


}


#endif
