//
// Created by bobo on 07.04.18.
//

#include <experimental/string_view>
#include <iostream>
#include "TextPool.h"

using namespace std;
using namespace pool;
int main(){
    string oniin = "kjbb";
    std::experimental::string_view name = "imim";
    TextPool textPool{"mlkm", "lnkj", "njk" "knjkn"};
    for(auto s : textPool.list_){
        cout << s <<endl;

    }
}
