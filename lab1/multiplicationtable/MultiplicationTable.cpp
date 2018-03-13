//
// Created by WiktorW on 3/6/2018.
//

#include "MultiplicationTable.h"
using namespace std;

void MultiplicationTable(int tab[][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            tab[i][j]=(i+1)*(j+1);
        }
    }
}

void PrintArray(int tab[][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<tab[i][j];
        }
        cout<<endl;
    }
}