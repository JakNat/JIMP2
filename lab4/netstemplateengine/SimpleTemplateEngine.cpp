//
// Created by bobo on 01.04.18.
//

#include "SimpleTemplateEngine.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <regex>
#include <vector>
namespace nets{



    View::View(std::string text){
       text_ = text;
    }

    View::~View(){
    }

    std::string View::Render(const std::unordered_map <std::string, std::string> &model) const{
        std::regex pattern (R"(\{\{\w+\}\})");
        std::string line = text_;
        std::smatch match;
        std::string search = line;

        while (regex_search(search, match, pattern)) {
            int replaced = 0;
            std::string matchStr = match.str();
            int size = matchStr.length();
            for (auto &n : model) {
                if(("{{" +n.first+"}}") == matchStr) {
                    line.replace( match.position(), size, n.second);
                    search =line;
                    for (int k=0; k<(match.position()+n.second.length()) ;k++){
                        search[k]=' ';
                    }
                    replaced = 1;
                    break;
                }
            }
            if (replaced == 0){
                line.replace(match.position(), size, "");
                search =line;
            }

        }
        return line;
    }

}