//
// Created by bobo on 12.04.18.
//

#include <iostream>
#include <set>
#include "WordCounter.h"

namespace datastructures {

    Counts::Counts(int a) {
        size_ = a;
    }

    bool Counts::operator==(const Counts &c) const {
        if (this->size_ == c.size_) {
            return true;
        } else {
            return false;
        }
    }
    bool Counts::operator==( int &x) const {
        if(this->size_ == x){
            return true;
        }
        return false;
    }
    Counts Counts::operator++() {
        size_++;
        return *this;
    }


//---------------------------------------------------//
    Word::Word(string word) {
        word_ = word;
    }

    bool Word::operator==(const Word &word) const{
        if (word_==word.word_){return true;}
        else{ return false;}
    }

    bool Word::operator<(const Word &word) const {
        return word_ < word.word_;
    }

    bool Word::operator>(const Word &word) const {
        return word < *this;
    }

    bool Word::operator<=(const Word &word) const {
        return !(word < *this);
    }

    bool Word::operator>=(const Word &word) const {
        return !(*this < word);
    }

//---------------------------------------------------//
    WordCounter::WordCounter() {
    }

    WordCounter::WordCounter(initializer_list<datastructures::Word> base_list) {
        for (auto word : base_list) {

            bool b = true;
            int x = 0;
            for (auto wordInBase : base_) {
                if (wordInBase.first.word_ == word.word_) {
                    b = false;
                    base_.at(x).second.size_++;
                    break;
                }
                x++;
            }
            if (b) {
                Counts c{1};
                pair<Word, Counts> p = {word, c};
                //base_.insert(p);
                base_.push_back(p);
            }
        }
        for (auto x : base_) {
            cout << x.first.word_ << endl;
        }

    }

    int WordCounter::DistinctWords() {
        int total = 0;
        for (auto x : base_) {
            total++;
        }
        return total;
    }

    int WordCounter::TotalWords() {
        int total = 0;
        for (auto x : base_) {
            total += x.second.size_;
        }
        return total;
    }

    Counts WordCounter::operator[](const string word) {
        for (auto x : base_) {
            if (x.first.word_ == word) {
                return x.second;
            }
        }
        return Counts{0};
    }

    set<Word> WordCounter::Words() {
        set<Word> list;
        for(auto x : base_){
            list.emplace(x.first);
        }
        return list;
    }
//---------------------------
    bool operator==(const int left_int, const datastructures::Counts right_counts){
        if(left_int == right_counts.size_){
            return true;
        }
        return false;
    }
    /*bool operator==(const set<Word> left, const set<Word> right ){
        bool b = true;
        return b;
    }*/
}


