#include <gtest/gtest.h>

#include "crdt/counter.hpp"


TEST(CounterTest, testGCounterInitialCounterHasZeroValue)
{
    crdt::gcounter counter(1);

    ASSERT_EQ(0, counter.query());
}


TEST(CounterTest, testGCounterIncrementingCounterIncrementsValue)
{
    crdt::gcounter counter(1);

    counter.increment(5);
    ASSERT_EQ(5, counter.query());
}


TEST(CounterTest, testGCounterMergingCounterCombinesValue)
{
    crdt::gcounter a_counter(1);
    crdt::gcounter another_counter(2);

    a_counter.increment(5);
    another_counter.increment(10);

    a_counter.merge(another_counter);

    ASSERT_EQ(15, a_counter.query());
}


TEST(CounterTest, testGCounterCompareBetweenMergedAndUnmergedCounters)
{
    crdt::gcounter a_counter(1);
    crdt::gcounter another_counter(2);

    a_counter.increment(5);
    another_counter.increment(10);

    a_counter.merge(another_counter);

    // a_counter:       [5, 10]
    // another_counter: [0 ,10]
    ASSERT_FALSE(a_counter.compare(another_counter));
    ASSERT_TRUE(another_counter.compare(a_counter));
}
