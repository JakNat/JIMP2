#include <iostream>
#include "Matrix.h"
//using namespace std;
using namespace algebra;

int main(){
    string a;
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}};
    Matrix m2{{7. + 1.0i, 0.}, {0., 1.0i}, {15. + 2.0i, 0. + 3.0i}};
    Matrix pauli{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};
    Matrix pauli2{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};
    Matrix max{{2.,2.},{2,2}};
    Matrix max2{{2.,2.},{2.,2.}};
    //Matrix m3 = m2;
    Matrix m4 = m2.Mul(m1);
    Matrix max6 = m4.Mul(m1);
    Matrix  m3 = m4;
  //  Matrix m5 = pauli.Pow(2);
 //   Matrix m4 = m1.Mul(m1);

   //     cout << max.Mul(max2).Print() <<endl;
   // cout<<max6.Print()<<endl;
    //    cout << max.Mul(max2).Print() <<endl;
     //   cout << max.Pow(2).Print() <<endl;
     //   cout << pauli.Mul(pauli2).Print()<<endl;
        cout << pauli.Pow(2).Print();
 //   cout << m1.Mul(m2).Print()<<endl;
   // cout <<  m1.Mul(m2).Size();
//    cout <<  m1.Mul(m2).Print() <<endl;
 //   cout <<  m2.Print()<<endl;
   // cout <<  m3.Print()<<endl;
   // cout << m5.Print();

  //  cout << m1.Mul(m2).Print();


    //  cout << m1.Print();
}