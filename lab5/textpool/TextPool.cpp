//
// Created by bobo on 07.04.18.
//

#include "TextPool.h"
namespace pool{

    TextPool & TextPool::operator=(TextPool &&textPool) {
        if (this == &textPool) {
            return textPool;
        }
        list_.clear();
        swap(list_, textPool.list_);
        return *this;
    }


    std::experimental::string_view TextPool::Intern(const std::string &str){
        bool flag = true;
        for (auto &n : list_) {
            if (n == str){
                flag = false;
                return n;
            }
        }
        if (flag){
           // list_.emplace(str);
            return Intern(str);
        }
    }

    size_t TextPool::StoredStringCount() const{
        size_t size = 0;
        for (auto &n : list_) {
            size+=1;
        }
        return size;
    }

}