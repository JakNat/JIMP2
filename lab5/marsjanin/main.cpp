//
// Created by bobo on 06.04.18.
//

#include <iostream>
#include <list>
#include <cstdlib>
#include "Marsjanin.h"


int main(){
    int a = 30;
    std::list<Marsjanin> marsList;
    while(a > 1){

        int v1 = rand() % 2;
        if(v1 == 1 || marsList.size() == 0){

            marsList.emplace_back(Marsjanin());

        } else{


            marsList.pop_back();
        }

        if(Marsjanin::liczbaMarsjan > 5){
            std::cout << "atack!!\n";
        } else{
            std::cout << "hiding\n";
        }
        int liczba = Marsjanin::liczbaMarsjan;

        a--;
    }
    return 0;
};