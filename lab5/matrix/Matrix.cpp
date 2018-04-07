//
// Created by bobo on 06.04.18.
//

#include "Matrix.h"
#include <complex>
#include <regex>
#include <iostream>

namespace algebra{

    Matrix::Matrix() {
    }
    Matrix::~Matrix() {
        for(int i=0; i<height_; i++)
        {
            delete [] matrix_[i];
        }
        delete [] matrix_;
    }
    Matrix::Matrix(int height, int weight) {
        height_ = height;
        weight_ = weight;
        matrix_ = new std::complex<double>*[height];


        for (int i = 0; i<height; i++)
        {
            matrix_[i] = new std::complex<double >[weight];
        }

    }
    Matrix::Matrix(std::string paramets) {
        int height = 0;
        int weight = 0;
        int h = 0;
        int w = 0;
        double a = 2.3;
        std::regex pattern (R"(((\d*)i(\d*)|(\d*)|([;])))");

        std::smatch match;
        std::string search = paramets;

        while (regex_search(search, match, pattern)) {
            std::cout << "match: " + match;
            std::cout << "\n";

        }
        height_ = height;
        weight_ = weight;
    }
    void Matrix::print() {
        for (int i = 0; i < height_; ++i) {
            std::cout << "| ";
            for (int j = 0; j < weight_; ++j) {
                std::cout << matrix_[i][j];
                std::cout << " ";
            }
            std::cout << "|\n";
        }
    }
    void Matrix::setValue(int height, int weight, std::complex<double> value) {
        matrix_[height][weight] = value;
    }
}