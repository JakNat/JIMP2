//
// Created by bobo on 06.04.18.
//

#ifndef JIMP_EXERCISES_RODZIC_H
#define JIMP_EXERCISES_RODZIC_H
#include "Dziecko.h"

using namespace std;
namespace parents {
    class Rodzic {
    private:
        string name_;
        string surname_;
        int age_;
        Dziecko kid_;

    public:
        Rodzic();

        Rodzic(string name, string surname, int age, Dziecko kid);

        ~Rodzic();
    };
}

#endif //JIMP_EXERCISES_RODZIC_H
