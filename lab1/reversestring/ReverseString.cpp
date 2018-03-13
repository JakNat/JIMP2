//
// Created by wronwikt on 02.03.18.
//

#include "ReverseString.h"

std::string Reverse(std::string str)
{
    if (str.empty())
        return std::string();
    char c = str[0];
    return Reverse(str.substr(1)) + c;

}