//
// Created by bobo on 07.04.18.
//

#include "TextPool.h"
using namespace std;
namespace pool {
    TextPool::TextPool() {
    }
    TextPool::~TextPool() {
        list_.clear();
    }
    TextPool::TextPool(TextPool &&textPool) {
        std::swap(list_, textPool.list_);
    }
    TextPool & TextPool::operator=(TextPool &&xxx){
        if (this == &xxx) {
            return xxx;
        }
        list_.clear();
        swap(list_,xxx.list_);
        return *this;
    }

    TextPool::TextPool(const std::initializer_list<std::string> &list) {
        for (const string &l : list) {
            Intern(l);
        }
    }
     experimental::string_view TextPool::Intern(const string &str) {
         for (auto &l : list_) {
             if (l == str){
                 return l;
             }
         }
             list_.emplace(str);
             return Intern(str);
    }

    size_t TextPool::StoredStringCount() const {
        return list_.size();
    }
}