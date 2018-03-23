//
// Created by tbk on 16.03.2018.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
namespace minimaltimedifference{
    using ::std::string;
    using ::std::vector;
    unsigned int ToMinutes(const string time_HH_MM);
    unsigned int MinimalTimeDifference(vector<std::string> times);
}


#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
