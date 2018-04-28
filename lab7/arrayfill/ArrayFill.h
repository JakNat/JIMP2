//
// Created by bobo on 18.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
        virtual void UniformFill(int value = 0);
    };
    class FillArray : public ArrayFill{
    public:
        void Incremental(ArrayFill *p,int step = 1);


    };
}

#endif //JIMP_EXERCISES_ARRAYFILL_H
