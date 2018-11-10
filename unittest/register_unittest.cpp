#include "gtest/gtest.h"

#include "crdt/register.hpp"


TEST(RegisterTest, testAssignValueToLWWRegister)
{
    crdt::lwwregister<int> lwwregister(1);
    lwwregister.assign(42);

    ASSERT_EQ(42, lwwregister.value());
}


TEST(RegisterTest, testOverwriteValueAssignedToLWWRegister)
{
    crdt::lwwregister<int> lwwregister(1);
    lwwregister.assign(42);
    lwwregister.assign(43);

    ASSERT_EQ(43, lwwregister.value());
}


TEST(RegisterTest, testMergeUpdatesWithLastWrittenRegisterValue)
{
    crdt::lwwregister<int> lwwregister1(1);
    lwwregister1.assign(42);

    crdt::lwwregister<int> lwwregister2(2);
    lwwregister2.assign(43);

    lwwregister1.merge(lwwregister2);

    ASSERT_EQ(43, lwwregister1.value());
}
