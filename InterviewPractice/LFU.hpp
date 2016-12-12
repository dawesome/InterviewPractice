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

class LFU
{
public:
    LFU();

    void set(int key, int value);
    int  get(int key);
};


#endif /* LFU_hpp */
