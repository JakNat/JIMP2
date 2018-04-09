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
       // Counter(const std::initializer_list< A> &elements) : counter_{elements};

      //  TextPool(const std::initializer_list< std::experimental::string_view> &elements) : list_{elements}{}

        //1. konstruktor kopiujący
        TextPool(const TextPool &textPool);

        //2. konstruktor przenoszący
        TextPool(TextPool &&textPool);

        //3. operator przypisania kopiujący
        TextPool &operator=(const TextPool &textPool);

        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&textPool);

        //5. Destruktor
        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;
        std::vector<const std::experimental::string_view> list_;
      //std::set<const std::experimental::string_view> list_;

    private:
      //  std::set<const std::experimental::string_view> list_;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
