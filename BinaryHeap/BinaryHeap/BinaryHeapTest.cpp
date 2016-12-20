//
//  BinaryHeapTest.cpp
//  BinaryHeap
//
//  Created by Michael Dawe on 12/18/16.
//
//

#include <stdio.h>
#include "gtest/gtest.h"
#include "BinaryHeap.hpp"

TEST(HeapTest, InsertOneValue)
{
    BinaryHeap heap;
    heap.Insert(1);
}

TEST(HeapTest, InsertOneValue_GetsValue)
{
    BinaryHeap heap;
    heap.Insert(1);
    ASSERT_EQ(1, heap.PopMin());
}

TEST(HeapTest, AfterManyInserts_MaintainsHeap)
{
    BinaryHeap heap;
    heap.Insert(4);
    heap.Insert(7);
    heap.Insert(7);
    heap.Insert(7);
    heap.Insert(5);
    heap.Insert(0);
    heap.Insert(2);
    heap.Insert(3);
    heap.Insert(5);
    heap.Insert(1);
    
    for (int i = 1; i < 5; i++) {
        ASSERT_LE(heap.AtIndex(i), heap.AtIndex(i*2));
        ASSERT_LE(heap.AtIndex(i), heap.AtIndex(i*2 + 1));
    }
}
