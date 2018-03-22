//
// Created by tbk on 17.03.2018.
//

#include "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>

#include <iostream>
#include <array>
#include <vector>
class string;
using namespace std;
namespace tinyurl {



   unique_ptr<TinyUrlCodec> Init(){
       auto codex = make_unique<TinyUrlCodec>();
       codex.get()->firstHash = {'0','0','0','0','0','0'};
       return codex;
    }

    void NextHash(std::array<char, 6> *state){
        array<char,6> tablica = *state;
        for (int i = tablica.size() - 1; i >= 0; --i) {

            tablica[i]++;
            if( tablica[i] == 58){
                tablica[i] = 65;
            }
            else if( tablica[i] == 91){
                tablica[i] = 97;
            }
            else if( tablica[i] == 123){
                tablica[i] = 48;
            }
            if(!( tablica[i] == 48 )){
                break;
            }
        }
        *state = tablica;
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        NextHash(&(*codec)->firstHash);

        (*codec)->Hashes.push_back((*codec)->firstHash);

        (*codec)->urls.push_back(url);
        std::string hash;
        for (int i = 0; i < (*codec)->firstHash.size(); ++i) {

            hash += (*codec)->firstHash[i];
        }
        return hash;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        int index = 0;
        for (int i = 0; i < codec->Hashes.size(); ++i) {
            bool a = true;

            for (int j = 0; j < codec->Hashes[i].size(); ++j) {
                if(codec->Hashes[i][j] != hash[j]){
                    a = false;
                    break;
                }
            }
            if(a){
                index = i;
                break;
            }
        }

        return codec->urls[index];
    }
}