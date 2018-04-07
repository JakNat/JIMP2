//
// Created by bobo on 06.04.18.
//

#include "Dziecko.h"

namespace parents{
    Dziecko::Dziecko() {}
    Dziecko::~Dziecko() {}

    void Dziecko::przepiszDoInnejSzkoły(string school) {
        school_ = school;
    }
}