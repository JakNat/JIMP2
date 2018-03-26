//
// Created by natojaku on 23.03.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H


#include "Point.h"
#include "Point.cpp"
namespace geometry {
    class Square {
    public:
        Square(Point a, Point b, Point c, Point d);

        double Circumference();

        double Area();

    private:
        Point a_;
        Point b_;
        Point c_;
        Point d_;

    };


}
#endif //JIMP_EXERCISES_SQUARE_H
