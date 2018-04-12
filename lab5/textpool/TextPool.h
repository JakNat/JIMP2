//
// Created by bobo on 07.04.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
#include <list>
using namespace std;
namespace pool {
    class TextPool {
    public:
        TextPool();
        ~TextPool();
        TextPool(TextPool &&textPool);
        TextPool(const std::initializer_list<std::string> &words);
        TextPool &operator=(TextPool &&textPool);
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
    private:
        std::set<std::string> list_;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
