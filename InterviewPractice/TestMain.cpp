//
//  TestMain.cpp
//  InterviewPractice
//
//  Created by Michael Dawe on 12/12/16.
//
//

#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char * argv[]) {
    // insert code here...
    std::cout << "Hello, Test!\n";
    
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
