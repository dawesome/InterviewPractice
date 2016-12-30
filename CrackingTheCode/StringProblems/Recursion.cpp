//
//  Recursion.cpp
//  CrackingTheCode
//
//  Created by Michael Dawe on 12/30/16.
//
//

#include "Recursion.hpp"

std::list<std::string> AddPerms(std::string str)
{
    std::list<std::string> perms;
    if (str.length() == 0) {
        perms.push_back("");
    } else {
        for (int l = 0; l < str.length(); ++l) {
            char first = str[0];
            std::string rest = str.substr(1);
            
            std::list<std::string> substrings = AddPerms(rest);
            
            for (auto i = substrings.begin(); i != substrings.end(); ++i) {
                perms.push_back(i->insert(l, &first));
            }

        }
    }
    
    return perms;
    
}
