//
// Created by bobo on 01.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template<class T,class C>
class SequentialIdGenerator{
public:
    SequentialIdGenerator();
    SequentialIdGenerator(C value);
    T NextValue();

private:
    int counter_;

};
template<class T,class C>
SequentialIdGenerator<T,C>::SequentialIdGenerator(){
    counter_ = (int)C();

}

template<class T,class C>
SequentialIdGenerator<T,C>::SequentialIdGenerator(C value){
    counter_ = (int)value;

}


template<class T,class C>
T SequentialIdGenerator<T,C>::NextValue(){
    auto a = int(counter_);
    counter_++;
    return T(a);
}

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
