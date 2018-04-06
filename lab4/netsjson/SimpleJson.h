//
// Created by bobo on 05.04.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H


#include <experimental/optional>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using std::string;
using std::map;
using std::vector;
using std::experimental::optional;
using ::std::literals::operator""s;
namespace nets {
    class JsonValue {
    public:
        ~JsonValue();
        JsonValue(int value);
        JsonValue(double value);
        JsonValue(bool value);
        JsonValue(std::string value);

        JsonValue(std::vector<JsonValue> values);
        JsonValue(std::map<std::string,JsonValue> values);
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        map<string, JsonValue> m_;
        optional<double> d_;
        optional<int> i_;
        optional<bool> b_;
        optional<string> s_;
        optional<vector<JsonValue>> v_;

    };

}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
