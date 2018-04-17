//
// Created by bobo on 12.04.18.
//


#include <map>
#include <iostream>
#include <set>
#include "WordCounter.h"

//#include "WordCounter.h"
using namespace std;
using namespace datastructures;

void add_word(map<string,int> &base, string word){
    int  a = 1;
    for(auto w: base) {
        if (word == w.first) {
            base[w.first] ++;
            return;
        }

    }

    pair<string, int> new_pair = {word, a};

    base.insert(new_pair);

}

int main() {
    map<string,int> base_;



    add_word(base_, "adadd");
    for(auto a : base_){
        cout << a.first << " liczba- "<< a.second<<endl;
    }
    WordCounter w {Word("Ds"), Word("fsdfd"),Word("njnjn"),Word("Ds")};
 //   cout << w.TotalWords()<<endl;
   // cout << w.DistinctWords();
    Counts c(3);
    Word a("asd");
    Word b("asdd");
    Word e("ss");
    cout << w["Ds"].size_<<endl;
    set<int> ii {56,1, 3,4};
    set<int> ij {1, 56,4,3};
    if (ii == ij){
        cout << "lkkkkkkkkkkkk";
    }

    set<Word> x;
    x.insert(a);
    x.insert(b);
}

