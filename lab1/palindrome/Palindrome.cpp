//
// Created by WiktorW on 3/6/2018.
//

#include "Palindrome.h"



bool IsPalindrome(std::string str)
{
    bool pal=true;
    int itr1=0,itr2=str.size()-1;
    while (itr1<itr2)
    {
        if(str[itr1]!=str[itr2])
        {
            pal=false;
            break;
        }
        itr1++; itr2--;
    }

    return pal;
}
