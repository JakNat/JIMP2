#include <iostream>
#include "Matrix.h"
using namespace std;
using namespace algebra;

int main(){
    Matrix m1("[1 2; 3 4]");
    Matrix m2("[1 1; 2 2]");
    Matrix m3{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};

    cout << "Macierz pierwsza: \n" << m1.Print() << endl;
    cout << "Macierz druga: \n" << m2.Print() << endl;

  //  cout << "Dodawanie" << m1.Add(m2).Print() << endl;
    cout << "Odejmowanie\n" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie\n" << (m1.Mul(m2)).Print() << endl;
    cout << "Dzielenie\n" << (m1.Div(m2)).Print() << endl;
    cout << "Potęgowanie\n" << (m1.Pow(2)).Print() << endl;
    cout << "Potęgowanie\n" << (m2.Pow(2)).Print() << endl;
    cout << "m3: \n" << m3.Print();
}