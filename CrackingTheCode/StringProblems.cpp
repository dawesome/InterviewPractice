//
//  StringProblems.cpp
//  CrackingTheCode
//
//  Created by Michael Dawe on 12/18/16.
//
//

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include <iostream>

std::string Compress(std::string input)
{
    int count = 0;
    std::string output = "";
    
    for (int i = 0; i < input.length(); i++) {
        ++count;
        if (i + 1 == input.length() || input[i] != input[i + 1]) {
            output += input[i];
            output += std::to_string(count);
            count = 0;
        }
    }
    
    if (input.length() <= output.length()) {
        return input;
    } else {
        return output;
    }
}




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "aaabcccccddd compressed = " << Compress("aaabcccccddd") << "\n";
    return 0;
}

