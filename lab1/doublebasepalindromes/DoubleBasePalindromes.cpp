//
// Created by WiktorW on 3/6/2018.
//

#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    uint64_t sum =0;
    for(int i=0; i<max_vaule_exculsive; i++)
    {
        string decString = to_string(i);
        int itr1=0, itr2=decString.size()-1;
        bool decPal=true, binPal=true;

        //check if decimal number is a palindrome
        while(itr1<itr2)
        {
            if(decString[itr1]!=decString[itr2])
            {
                decPal= false;
                break;
            }
            itr1++; itr2--;
        }

        if(decPal)
        {
            //calculate the binary form
            string binString;
            int tmp = i;
            while(tmp>0)
            {
                binString.append(to_string(tmp % 2));
                tmp /= 2;
            }

            //check if binary number is a palindrome
            itr1=0; itr2=binString.size()-1;
            while(itr1<itr2)
            {
                if(binString[itr1]!=binString[itr2])
                {
                    binPal= false;
                    break;
                }
                itr1++; itr2--;
            }

            if(binPal)
                sum+=i;
        }
    }
    return sum;
}