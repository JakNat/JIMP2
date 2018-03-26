//
// Created by natojaku on 23.03.18.
//

#include "Square.h"
namespace geometry{
Square::Square(Point a, Point b, Point c, Point d) {
    a_=a;
    b_=b;
    c_=c;
    d_=d;
}

double Square::Circumference(){
    double pierwszyBok = a_.Distance(b_);
    double drugiBok = b_.Distance(c_);
    double trzeciBok = c_.Distance(d_);
    double czwartyBok = d_.Distance(a_);
    return  pierwszyBok + drugiBok + trzeciBok + czwartyBok;
}
double Square::Area() {
    double a = a_.Distance(b_);
    return a * a;
}
}
