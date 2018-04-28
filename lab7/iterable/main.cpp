//
// Created by bobo on 21.04.18.
//
#include <vector>
#include <iostream>
#include "Iterable.h"

using namespace utility;
using namespace std;
int main(){
    vector<int> w_int {6,5,6,2,6};
    vector<string> w_string{"jokoko", "ala", "hugo", "jokoko"};

    std::vector<int>::const_iterator left_ = w_int.begin();
    std::vector<std::string>::const_iterator right_ = w_string.begin();
    std::vector<int>::const_iterator left_end_ = w_int.end();
    std::vector<std::string>::const_iterator right_end_ = w_string.end();

    ZipperIterator zipperIterator(w_int.begin(), right_, left_end_, right_end_);
    ZipperIterator zipperIterator2(left_end_, right_end_, left_end_, right_end_);
//    std::unique_ptr<IterableIterator> test_it = make_unique<IterableIterator>();
  //  IterableIteratorWrapper wrapper{move(test_it)};
   

    /* for (std::vector<int>::const_iterator it = left_; it != left_end_ ; it++) {
       // cout << *it <<endl;
    }*/
}