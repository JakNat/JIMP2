//
// Created by bobo on 21.04.18.
//

#include <vector>
#include <ios>
#include <iostream>
#include "Iterable.h"
using namespace std;

namespace utility{


////////////////////////ZipperIterator//////////////////
ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right,
                               std::vector<int>::const_iterator left_end,
                               std::vector<std::string>::const_iterator right_end) {
         left_ = left;
         right_ = right;
         left_end_ = --left_end;
         right_end_ = --right_end;
}
 std::pair<int , std::string> ZipperIterator::Dereference() const {
     int i = *left_;
     string s = *right_;
     return std::pair<int, std::string> (i,s);
}



    IterableIterator& ZipperIterator::Next() {

    if(left_ != left_end_ ){
        ++left_ ;
    }
    if(right_ != right_end_){
        ++right_;
    }
        return *this;
}

bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
    if( *left_ == other->Dereference().first && *right_ == other->Dereference().second){
        return false;
    }

    return true;
}
///////////////////IterableIteratorWrapper///////////////////////////////////////
IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    iterator_ = move(iterator);
}



IterableIteratorWrapper& IterableIteratorWrapper::operator++() {
    iterator_.get()->Next();
    return *this;
}
bool IterableIteratorWrapper::operator!=(const utility::IterableIteratorWrapper &other) const {
    return iterator_.get()->NotEquals(other.iterator_);
}

std::pair<int, std::string> IterableIteratorWrapper::operator*() const{
    pair<int, std::string> p (0,"");
    return iterator_.get()->Dereference();
}

}



