//
// Created by bobo on 13.04.18.
//

#include <iostream>
#include <vector>
#include "Student.h"

namespace st{
    StudyYear::StudyYear(int year) {
        year_ = year;
    }
    StudyYear StudyYear::operator++() {
        year_++;
        return *this;
    }
    StudyYear StudyYear::operator++(int a) {
        StudyYear copy = *this;

        year_++;
        return copy;
    }
    StudyYear StudyYear::operator--() {
        year_--;
    }
    StudyYear StudyYear::operator--(int b) {
        year_--;
    }
    std::ostream& operator<<(std::ostream &output, StudyYear studyYear){
        std::cout << studyYear.year_;
    }
    std::istream& operator>>(std::ostream &input, StudyYear &studyYear){

    }

    std::ostream& operator<<(std::ostream &output, Student student){
        std::vector<string> student_list{student.id,student.first_name,student.last_name, student.program};

        string s ="";
        output << "id" :
        return output << s;
    }
    std::istream& operator>>(std::ostream &input, Student &student){

    }
}