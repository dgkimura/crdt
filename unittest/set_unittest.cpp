#include "crdt/set.hpp"
#include "gtest/gtest.h"


TEST(SetTest, testEmptyOrsetLookup)
{
    crdt::orset<uint32_t> _set(1);

    ASSERT_FALSE(_set.lookup(42));
}


TEST(SetTest, testNonemptyOrsetLookup)
{
    crdt::orset<uint32_t> _set(1);
    _set.add(42);

    ASSERT_TRUE(_set.lookup(42));
}


TEST(SetTest, testRemoveElementThenPerformOrsetLookup)
{
    crdt::orset<uint32_t> _set(1);
    _set.add(42);
    _set.remove(42);

    ASSERT_FALSE(_set.lookup(42));
}


TEST(SetTest, testCanAddPreviouslyRemovedElement)
{
    crdt::orset<uint32_t> _set(1);
    _set.add(42);
    _set.remove(42);
    _set.add(42);

    ASSERT_TRUE(_set.lookup(42));
}


TEST(SetTest, testMultipleAddAndRemoveThenMerge)
{
    crdt::orset<uint32_t> a_set(1);
    crdt::orset<uint32_t> another_set(2);
    a_set.add(42);
    a_set.remove(42);
    another_set.add(42);

    a_set.merge(another_set);

    ASSERT_TRUE(a_set.lookup(42));
}


TEST(SetTest, testMultipleAddThenMergeAndRemove)
{
    crdt::orset<uint32_t> a_set(1);
    crdt::orset<uint32_t> another_set(2);
    a_set.add(42);
    another_set.add(42);

    a_set.merge(another_set);
    a_set.remove(42);

    ASSERT_FALSE(a_set.lookup(42));
}
