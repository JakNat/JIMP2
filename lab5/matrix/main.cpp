#include <iostream>
#include "Matrix.h"
using namespace std;
using namespace algebra;

int main(){

    Matrix pauli{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};
    cout << pauli.Pow(1).Print();


    //  cout << m1.Print();
}