//
// Created by bobo on 06.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

using namespace std;

#include <complex>
#include <vector>

namespace algebra {
    class Matrix {
    private:
        int height_;
        int width__;
        std::complex<double> nr_;

        std::complex<double> **matrix_;

    public:
        Matrix();
        ~Matrix();
        Matrix(const Matrix &Matrix);
        //2. konstruktor przenoszący
   //     Matrix(Matrix &&Matrix);
        //3. operator przypisania kopiujący
     //   Matrix &operator=(const Matrix &Matrix);
        //4. operator przypisania przenoszący
       // Matrix &operator=(Matrix &&Matrix);;
        Matrix(int height, int weight);
        void usun();

        Matrix(std::string paramets);

        Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list);
        Matrix Add(const Matrix &matrix) const;
       // Matrix Add(Matrix matrix);
        Matrix Sub(const Matrix &matrix);
        Matrix Mul(const Matrix &matrix);
        Matrix Mul(std::complex<double> value);

        Matrix Div(const Matrix &matrix);
        Matrix Div(std::complex<double> value);
        std::pair<size_t, size_t> Size();

        Matrix Pow(int value);

        std::complex<double>  GetValue(int height, int weight);
        void SetValue(int height, int weight, std::complex<double> value);



        std::string Print() const ;

    };
}

#endif //JIMP_EXERCISES_MATRIX_H
