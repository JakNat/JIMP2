//
// Created by bobo on 05.04.18.
//



#include <experimental/optional>
#include <string>
#include <map>
#include <vector>
#include <iostream>

#include "SimpleJson.h"
using namespace std;
namespace nets {

    JsonValue::~JsonValue() {
        m_.clear();

    }

    JsonValue::JsonValue(int value) {
        i_ = value;
    }

    JsonValue::JsonValue(double value) {
        d_ = value;
    }

    JsonValue::JsonValue(bool value) {
        b_ = value;
    }

    JsonValue::JsonValue(string value) {
        string cos = value;
        for (int i=0;i<cos.length();i++){
            if (cos[i]=='\"' || cos[i]=='\\'){
                cos.insert(i, 1,'\\');
                i++;
            }
        }
        s_=cos;
    }



    JsonValue::JsonValue(std::vector <JsonValue> values) {
        v_ = values;
    }

    JsonValue::JsonValue(map <string, JsonValue> values) {
        m_ = values;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        for (auto &n : this->m_) {
            if (n.first==name){
                return n.second;
            }
        }
    }

    std::string JsonValue::ToString() const {

        if(i_){
            return std::to_string(*i_);
        }

        else if(d_)
        {   string double_string = std::to_string(*d_);

            for (int i = double_string.length() - 1; i > 0 ; --i) {

                if(double_string[i] == '0'){
                    double_string.pop_back();
                } else
                    break;
            }

            return double_string;

        }
        else if(s_){
            string data;
            data += "\"" + *s_ + "\"";
            return data;
        } else if(b_){
            string data = std::to_string(*b_);
            if(data == "1"){
                return "true";
            } else return "false";
            return std::to_string(*b_);
        } else if(v_){
            string data = "[";
            for( auto &a : *v_){
                data += a.ToString() + ", ";

            }
            data.pop_back();
            data.pop_back();
            data += "]";
            return data;
        }
        else if(&m_ != nullptr){
            string data;
            data += "{";
            for (auto &n : this->m_) {
                string cos = n.first;
                for (int i=0;i<cos.length();i++){
                    if (cos[i]=='\"' || cos[i]=='\\'){
                        cos.insert(i, 1,'\\');
                        i++;
                    }
                }
                data += "\"" + cos + "\": ";
                data += n.second.ToString() ;
                data += ", ";
            }
            data.pop_back();
            data.pop_back();
            data += "}";
            return data;
        }

         else{
            return "";
        }
        }

}