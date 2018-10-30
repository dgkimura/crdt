#ifndef __COUNTER_HPP_INCLUDED__
#define __COUNTER_HPP_INCLUDED__

#include <vector>


namespace crdt
{


class gcounter
{
public:

    gcounter(uint32_t id);

    virtual ~gcounter() = default;

    void increment(uint32_t value);

    int query();

    bool compare(const gcounter& other);

    void merge(const gcounter& other);

private:

    uint32_t _id;

    std::vector<uint32_t> _positive_counter;
};


class pncounter
{
public:

    pncounter(uint32_t id);

    virtual ~pncounter() = default;

    void increment(uint32_t value);

    void decrement(uint32_t value);

    int query();

    bool compare(const pncounter& other);

    void merge(const pncounter& other);

private:

    uint32_t _id;

    std::vector<uint32_t> _positive_counter;

    std::vector<uint32_t> _negative_counter;
};


}


#endif
