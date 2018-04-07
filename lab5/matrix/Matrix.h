//
// Created by bobo on 06.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H


#include <complex>
namespace algebra {
    class Matrix {
    private:
        int height_;
        int weight_;
        std::complex<double> nr_;

        std::complex<double> **matrix_;

    public:
        Matrix();

        ~Matrix();

        Matrix(int height, int weight);

        Matrix(const Matrix &matrix);

        Matrix(std::string paramets);

        double getValue(int height, int weight);

        void setValue(int height, int weight, std::complex<double > value);

        Matrix add(const Matrix &matrix);

        Matrix sub(const Matrix &matrix);
        void print();

    };
}

#endif //JIMP_EXERCISES_MATRIX_H
