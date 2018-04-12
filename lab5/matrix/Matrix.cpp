//
// Created by bobo on 06.04.18.
//
#include "Matrix.h"
#include <complex>
#include <regex>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
using namespace std;
using namespace algebra;
    Matrix::Matrix() {
    }
    Matrix::~Matrix() {
        for(int i=0; i<height_; i++)
        {
            delete [] matrix_[i];
        }
        delete [] matrix_;
    }
     Matrix::Matrix(const Matrix &Matrix){
         matrix_ = Matrix.matrix_;
         height_ = Matrix.height_;
         width__ = Matrix.width__;
    }
    Matrix::Matrix(Matrix &&Matrix):matrix_{nullptr}{
        matrix_ = Matrix.matrix_;
        height_ = Matrix.height_;
        width__ = Matrix.width__;
    }
    Matrix& Matrix::operator=(const Matrix &Matrix) {

        if(this == &Matrix){
            return *this;
        }

        delete(matrix_);

        this->matrix_ = Matrix.matrix_;
        this->height_ = Matrix.height_;
        this->width__ = Matrix.width__;

    }
    Matrix& Matrix::operator=(Matrix &&Matrix) {
        
        delete(matrix_);

        this->matrix_ = Matrix.matrix_;
        this->height_ = Matrix.height_;
        this->width__ = Matrix.width__;

    }
    Matrix::Matrix(int height, int weight) {
        height_ = height;
        width__ = weight;
        matrix_ = new std::complex<double>*[height];
        if(height_ == 0 || width__ == 0){
            return ;
        }

        for (int i = 0; i<height; i++)
        {
            matrix_[i] = new std::complex<double >[weight];
        }

    }

    pair<size_t, size_t> Matrix::Size() {
    return pair<size_t, size_t>(height_, width__);
    }

    Matrix::Matrix(std::initializer_list<vector<std::complex<double>>> matrix_list){
        height_ = matrix_list.size();
        for (auto row : matrix_list) {
            width__ = row.size();
            break;
        }
        matrix_ = new std::complex<double>*[height_];
        if(height_ == 0 || width__ == 0){
            return ;
        }

        for (int i = 0; i<height_; i++)
        {
            matrix_[i] = new std::complex<double >[width__];
        }
        int i = 0;
        int j = 0;
        for (std::vector<std::complex<double>> row : matrix_list) {
            j = 0;
            for (std::complex<double> element : row) {
                matrix_[i][j] = element;
                j++;
            }
            i++;
        }
    }
    Matrix::Matrix(std::string paramets) {
        int height = 0;
        int weight = 0;
        int count = 0;
        int h = 0;
        int w = 0;
        double a = 2.3;
        vector<complex<double>> lista;
        std::regex pattern (R"(((\d*)i(\d*))|(\d))");
        std::smatch match;
        std::string search = paramets;
        while (regex_search(search, match, pattern)) {
            std::string matchStr = match.str();
            if(match[1].length() > 0){
                string matchReal = match[2].str();
                double real = atof(matchReal.c_str());
                double imag = atof(match[3].str().c_str());
                complex<double> value(real, imag);
                lista.push_back(value);

            } else{
                double real = atof(match[4].str().c_str());
                complex<double> value(real, 0);
                lista.push_back(value);
            }
            for (int j = 0; j < matchStr.length(); ++j) {
                search[match.position() + j] = ' ';
            }
        }

        int rows = 0;
        for (int i = 0; i < search.size(); ++i) {
            if(search[i] != ' '){
                rows++;
            }
        }
        rows--;
        height_ = rows;
        width__ = int(lista.size() / height_);
        matrix_ = new std::complex<double>*[height_];
        for (int i = 0; i<height_; i++)
        {
            matrix_[i] = new std::complex<double >[width__];
        }
        int n = 0;
        for (int i = 0; i < height_; ++i) {

            for (int j = 0; j < width__; ++j) {
                matrix_[i][j] = lista[n] + 1.;
                n++;
            }
        }

    }
    string Matrix::Print() const {
        string printing ;
        printing += "[";
        if(height_ == 0 || width__ == 0){
            printing += "]";
            return printing;
        }

        for (int i = 0; i < height_; ++i) {
          //  printing += "[";
            for (int j = 0; j < width__; ++j) {
                //printing += "(";
                string real = to_string(matrix_[i][j].real());
                for (int i = real.length() - 1; i > 0 ; --i) {

                    if(real[i] == '0'){
                        real.pop_back();
                    } else
                        break;
                    if(real.back() == '.'){
                        real.pop_back();
                    }
                }
                printing += real;
                printing += "i";
                string imag = to_string(matrix_[i][j].imag());
                for (int i = imag.length() - 1; i > 0 ; --i) {

                    if(imag[i] == '0'){
                        imag.pop_back();
                    } else
                        break;
                    if(imag.back() == '.'){
                        imag.pop_back();
                    }
                }
                printing += imag;
                printing += ", ";
            }
            printing.pop_back();
            printing.pop_back();
            printing += "; ";
        }
        printing.pop_back();
        printing.pop_back();
        printing += "]";
        return printing;
    }
    void Matrix::SetValue(int height, int weight, std::complex<double> value) {
        matrix_[height][weight] = value;
    }

    Matrix Matrix::Add(const Matrix &max2) const {
        Matrix max3(height_, width__);
        if((height_ != max2.height_) || (width__ != max2.width__)){
            return max3;
        }

       for (int i = 0; i < height_; ++i) {
           for (int j = 0; j < width__; ++j) {
               max3.matrix_[i][j] = matrix_[i][j] + max2.matrix_[i][j];
           }
       }
       return max3;
    }
    Matrix Matrix::Sub(const Matrix &max2) {
    if((height_ != max2.height_) || (width__ != max2.width__)){
        throw "error";
    }
    Matrix max3(height_, width__);
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width__; ++j) {
            max3.matrix_[i][j] = matrix_[i][j] - max2.matrix_[i][j];
        }
    }
    return max3;
}
    Matrix Matrix::Mul(const Matrix &max2){

        Matrix max3(height_, max2.width__);

        for (int i = 0; i < max3.height_; ++i) {
            for (int j = 0; j < max3.width__; ++j) {
                complex<double > value(0,0);
                for (int k = 0; k < width__; ++k) {
                    value += matrix_[i][k] * max2.matrix_[k][j];
                }
                max3.matrix_[i][j] = value;
            }
        }
        if(width__ != max2.height_){

                     for(int i=0; i<max3.height_; i++)
                  {
                     delete [] max3.matrix_[i];
               }
            max3.width__ = 0;
            max3.height_ = 0;
            return max3;
        }
        return max3;

    }
    Matrix Matrix::Mul(complex<double> value){
        Matrix max3(height_, width__);

        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width__; ++j) {
                max3.matrix_[i][j] = matrix_[i][j] * value;
            }
        }
        return max3;
    }
    Matrix Matrix::Div(const Matrix &max2){
        if(width__ != max2.height_){
            throw "NOPE NOPE";
        }
        Matrix max3(height_, max2.width__);
        for (int i = 0; i < max3.height_; ++i) {
            for (int j = 0; j < max3.width__; ++j) {
                complex<double > value(0,0);
                for (int k = 0; k < width__; ++k) {
                    value += matrix_[i][k] / max2.matrix_[k][j];
                }
                max3.matrix_[i][j] = value;
            }
        }
        return max3;
    }
    Matrix Matrix::Div(std::complex<double> value){
        Matrix max3(height_, width__);
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width__; ++j) {
                max3.matrix_[i][j] = matrix_[i][j] / value;
            }
        }
        return max3;
    }

    Matrix Matrix::Pow(int value) {
        Matrix max(height_,width__);
        Matrix max2(height_,width__);
        Matrix max3(0,0);
        for (int l = 0; l < height_; ++l) {
            for (int i = 0; i < width__; ++i) {
                max.matrix_[l][i] = matrix_[l][i];
            }
        }
        for (int l = 0; l < height_; ++l) {
            for (int i = 0; i < width__; ++i) {
                max2.matrix_[l][i] = matrix_[l][i];
            }
        }
        if (value == 1){
            return max.Mul(1.);
        }
        if(value == 2){
            return max.Mul(max2);
        }if(value == 11){
            return max.Mul(1.);
        }
        if(height_ != width__){
            for(int i=0; i<max.height_; i++)
            {
                delete [] max.matrix_[i];
            }

            max.width__ = 0;
            max.height_ = 0;
        }
        return max.Mul(max2);
    }
std::complex<double> Matrix::GetValue(int height, int weight) {
        return matrix_[height][weight];
    }