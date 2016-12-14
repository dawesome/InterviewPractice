//
//  LFUTest.cpp
//  InterviewPractice
//
//  Created by Michael Dawe on 12/12/16.
//
//

#include <stdio.h>
#include "gtest/gtest.h"
#include "LFU.hpp"


TEST(LFUTest, CanCreateLFUWithCapacity) {
    LFU lfu(2);
}

TEST(LFUTest, CanCallSet) {
    LFU lfu(2);
    lfu.set(1,1);
}

TEST(LFUTest, CanCallGet) {
    LFU lfu(2);
    lfu.get(1);
}

TEST(LFUTest, AfterSet1_GetReturns1) {
    LFU lfu(2);
    lfu.set(1, 1);
    ASSERT_EQ(1, lfu.get(1));
}

TEST(LFUTest, GetWithoutSet_ReturnsNeg1) {
    LFU lfu(2);
    ASSERT_EQ(-1, lfu.get(1));
}

TEST(LFUTest, WhenCapcityExceeded_LastKeyIsRemoved) {
    LFU lfu(2);
    lfu.set(1, 1);
    lfu.set(2, 2);
    ASSERT_EQ(1, lfu.get(1));       // returns 1
    lfu.set(3, 3);    // evicts key 2
    ASSERT_EQ(-1, lfu.get(2));       // returns -1 (not found)
}


//LFU lfu(2);
//lfu.set(1, 1);
//lfu.set(2, 2);
//ASSERT_EQ(1, lfu.get(1));       // returns 1
//lfu.set(3, 3);    // evicts key 2
//ASSERT_EQ(-1, lfu.get(2));       // returns -1 (not found)
//lfu.get(3);       // returns 3
