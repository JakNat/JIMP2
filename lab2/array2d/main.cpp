//
// Created by wronwikt on 09.03.18.
//

#include "Array2D.h"

int main()
{
    int** a = Array2D(5,5);
    DeleteArray2D(a, 5, 5);
    return 0;
}