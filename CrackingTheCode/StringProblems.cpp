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
#include <unordered_set>

#include <iostream>

#include "gtest/gtest.h"

#include "Recursion.hpp"

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

bool IsUnique(std::string s) {
    std::unordered_set<char> set;
    for (char c : s) {
        if (set.find(c) != set.end()) {
            return false;
        }
        set.insert(c);
    }
    return true;
}

TEST(IsUniqueTests, SetTests) {
    ASSERT_EQ(true, IsUnique("abcdefghijklmnop"));
    ASSERT_EQ(false, IsUnique("abdcd"));
}

bool IsUniqueNoSet(std::string s) {
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; i < s.length(); ++j) {
            if (s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}
TEST(IsUniqueTests, NonSetTests) {
    ASSERT_EQ(true, IsUniqueNoSet("abcdefghijklmnop"));
    ASSERT_EQ(false, IsUniqueNoSet("abdcd"));
}

void ShiftBy2(char * str, int index, int len) {
    for (int cur = len; cur >= index; --cur) {
        *(str + cur + 2) = *(str + cur);
    }
}


void WritePercent(char *str) {
    *str = '%';
    *(str + 1) = '2';
    *(str + 2) = '0';
}
char* URLifyAttempt1(char * str, int len) {
    int index = len - 1;
    char *cur = str + index;
    while (cur > str) {
        if (*cur == ' ') {
            ShiftBy2(str, index, len - 1);
            len += 2;
            WritePercent(cur);
        }
        --cur;
        --index;
    }
    
    return str;
}

char* URLifyAttempt2(char* str, int len) {
    int spaceCount = 0;
    for (int cur = 0; cur < len; ++cur) {
        if (*(str + cur) == ' ') {
            ++spaceCount;
        }
    }
    
    int shiftIndex = spaceCount * 2;
    char* end = str + len - 1;
    while (end > str) {
        if (*end == ' ') {
            shiftIndex -= 2;
            WritePercent(end + shiftIndex);
        } else {
            *(end + shiftIndex) = *end;
        }
        --end;
    }
    return str;
}

TEST(URLifyTests, Attempt1Test) {
    char original[] = "Mr John Smith    ";
    char expected[] = "Mr%20John%20Smith";
    ASSERT_STREQ(expected, URLifyAttempt1(original, 13));
}
TEST(URLifyTests, Attempt2Test) {
    char original[] = "Mr John Smith    ";
    char expected[] = "Mr%20John%20Smith";
    ASSERT_STREQ(expected, URLifyAttempt2(original, 13));
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    
    auto stringList = AddPerms("abc");
    for (auto i = stringList.begin(); i != stringList.end(); ++i) {
        std::cout << *i << std::endl;
    }
    
    RUN_ALL_TESTS();
    std::cout << "aaabcccccddd compressed = " << Compress("aaabcccccddd") << "\n";
    return 0;
}

