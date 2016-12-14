//
//  LFU.cpp
//  InterviewPractice
//
//  Created by Michael Dawe on 12/12/16.
//
//

#include "LFU.hpp"

LFU::LFU(int capacity) : capacity(capacity)
{
    
}

void LFU::set(int key, int value)
{
    if (keysToValueFrequency.size() <= capacity) {
        keysToValueFrequency[key] = std::pair<int, int>(value, 0);
    } else {
        // remove least-recently-used key
        
    }
}

int LFU::get(int key)
{
    std::unordered_map<int, std::pair<int, int>>::iterator i = keysToValueFrequency.find(key);
    if (i == keysToValueFrequency.end()) {
        return -1;
    } else {
        IncrementFrequency(i);
        return i->second.first;
    }
}

void LFU::IncrementFrequency(const std::unordered_map<int, std::pair<int, int>>::iterator iter)
{
    iter->second.second++;
}
