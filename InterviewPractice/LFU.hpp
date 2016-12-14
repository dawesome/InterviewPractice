//
//  LFU.hpp
//  InterviewPractice
//
//  Created by Michael Dawe on 12/12/16.
//
//

#ifndef LFU_hpp
#define LFU_hpp

#include <stdio.h>
#include <unordered_map>

class LFU
{
private:
    int capacity;
    std::unordered_map<int, std::pair<int, int>> keysToValueFrequency;
    
public:
    LFU(int capacity);
    

    void set(int key, int value);
    int  get(int key);
    
private:
    void IncrementFrequency(const std::unordered_map<int, std::pair<int, int>>::iterator iter);
};


#endif /* LFU_hpp */
