//
// Created by WiktorW on 3/10/2018.
//
#include <fstream>
#include "Polybius.h"
using namespace std;


int main(int agrc, char** argv)
{
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    char line[256];

    while(!inFile.eof())
    {
        inFile.getline(line,256);
        if(argv[3] == "1")
            outFile<<PolybiusCrypt(line);
        else if(argv[3]=="0")
            outFile<<PolybiusDecrypt(line);
    }

    inFile.close();
    outFile.close();
    return 0;
}