//
// Created by bobo on 06.04.18.
//



#include <complex>
#include "Matrix.h"

using ::algebra::Matrix;

    int main() {
        int a = 2;
        Matrix matrix{a, a};
        matrix.setValue(0,0,1.);
        matrix.setValue(0,1,2.);
        matrix.setValue(1,0,3.);
        matrix.setValue(1,1,4.);
        matrix.print();
    }
