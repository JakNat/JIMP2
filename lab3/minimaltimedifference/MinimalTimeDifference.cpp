//
// Created by tbk on 16.03.2018.
//

#include "MinimalTimeDifference.h"
#include <regex>
class string;

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
using namespace std;
namespace minimaltimedifference{
    using std::regex;
    using std::smatch;

    unsigned ToMinutes( std::string str){

        vector<int> allHoursToMinutes;

        regex pattern {R"((\d{1,2}):(\d{0,9})(\d{0,9}))"};

        smatch matches;
        regex_match(str, matches, pattern);
        unsigned int minutes = 60 * std::stoi(matches[1]) + std::stoi(matches[3]);
        if(minutes==1440)
            minutes=0;

        return minutes;

    }
    unsigned int MinimalTimeDifference(std::vector<std::string> times){
        vector<int> timesInMinutes;
        for (int i = 0; i < times.size(); ++i) {
            timesInMinutes.push_back(ToMinutes(times[i]));
        }
        std::sort (timesInMinutes.begin(), timesInMinutes.end());

        int suma = timesInMinutes[1] - timesInMinutes[0];

        for (int j = 0; j < timesInMinutes.size() - 1; ++j) {
            if(timesInMinutes[j + 1] - timesInMinutes[j] < suma){
                suma = timesInMinutes[j + 1] - timesInMinutes[j];
            }
        }
        return 1;
    }
}

