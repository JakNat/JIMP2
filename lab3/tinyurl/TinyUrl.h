//
// Created by tbk on 17.03.2018.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <vector>

using namespace std;

namespace tinyurl{
    typedef struct TinyUrlCodec{
        array <char,6> firstHash;
        vector<array <char,6>> Hashes ;
        vector <string> urls;

    }TinyUrlCodec;


    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
