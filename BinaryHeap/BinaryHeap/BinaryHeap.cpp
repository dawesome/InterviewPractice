//
//  BinaryHeap.cpp
//  BinaryHeap
//
//  Created by Michael Dawe on 12/18/16.
//
//

#include "BinaryHeap.hpp"

BinaryHeap::BinaryHeap()
{
    // Dummy value so heap starts at index 1
    heap.push_back(-1);
}

int BinaryHeap::GetParentIndex(int index) const
{
    return index / 2;
}

int BinaryHeap::GetLeftChildIndex(int index) const
{
    return 2*index;
}

int BinaryHeap::GetRightChildeIndex(int index) const
{
    return 2*index + 1;
}

void BinaryHeap::PushDown(int index)
{
    int value = heap[index];
    int child;
    
    for(; 2 * index <= heap.size(); index = child)
    {
        child = 2*index;
        
        if(child != heap.size() && heap[child] < (heap[child + 1])) {
            child++;
        }
        
        if(value < heap[child]) {
            heap[index] = heap[child];
        }
        else
            break;
    }
    heap[index] = value;
}

void BinaryHeap::Insert(int value)
{
    heap.push_back(value);
    int pos = heap.size() - 1;
    for (; pos > 1 && heap[pos / 2] > value; pos = pos/2) //min heap?
    {
        heap[pos] = heap[pos/2];
        heap[pos/2] = value;
    }
    
    heap[pos] = value;
}

int BinaryHeap::PopMin()
{
    int min = heap[1];
    heap[1] = heap[heap.size()];
    heap.pop_back();
    PushDown(1);
    
    return min;
}

int BinaryHeap::AtIndex(int index)
{
    return heap[index];
}
