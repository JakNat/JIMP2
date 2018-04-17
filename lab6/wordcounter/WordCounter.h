//
// Created by bobo on 12.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <map>
#include <istream>
#include <vector>

using namespace std;

namespace datastructures {

    class Word{
    public:
        Word(string word);
        string word_;
        bool operator==(const Word &word) const;
        bool operator<(const Word &word) const;
        bool operator>(const Word &word) const;
        bool operator<=(const Word &word) const;
        bool operator>=(const Word &word) const;

    private:

    };

    class Counts{
    public:
        Counts(int a);
        int size_;

        bool operator==(const Counts &c) const ;
        bool operator==( int &x) const ;
        Counts operator++();
    private:

    };
    class WordCounter {
    public:
        WordCounter();
        WordCounter(initializer_list<Word> base_list);
        static void FromInputStream(std::istream &input);
        void print_base();
   //     Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list);
        int DistinctWords();
        int TotalWords();
        set<Word> Words();
        Counts operator[](const string word);


    private:
        vector<pair<Word,Counts>> base_;
    };
    bool operator==(const int left_int, const datastructures::Counts right_counts);


}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
