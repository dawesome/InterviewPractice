//
//  BinaryHeap.hpp
//  BinaryHeap
//
//  Created by Michael Dawe on 12/18/16.
//
//

#ifndef BinaryHeap_hpp
#define BinaryHeap_hpp

#include <stdio.h>
#include <vector>

class BinaryHeap {
private:
    std::vector<int> heap;

    int GetParentIndex(int index) const;
    int GetLeftChildIndex(int index) const;
    int GetRightChildeIndex(int index) const;
    
    void PushDown(int index);
public:
    BinaryHeap();
    
    void Insert(int value);
    int  PopMin();
    
    int AtIndex(int index);
};

#endif /* BinaryHeap_hpp */
