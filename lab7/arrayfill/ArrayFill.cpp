//
// Created by bobo on 18.04.18.
//

#include <cstddef>
#include <vector>
#include "ArrayFill.h"
using std::vector;

namespace arrays {
    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }
}