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


TEST(LFUTest, CanCreateLFU) {
    LFU lfu;
}

TEST(LFUTest, CanCallSet) {
    LFU lfu;
    lfu.set(1,1);
}

TEST(LFUTest, CanCallGet) {
    LFU lfu;
    lfu.get(1);
}
