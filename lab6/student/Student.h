//
// Created by bobo on 13.04.18.
//

#ifndef POINT_STUDENT_H
#define POINT_STUDENT_H

#include <string>

using std::string;
namespace st {
    class Student {
    private:
        string id, first_name, last_name, program;
        int year;

    };

    class StudyYear {
    public:
        StudyYear(int year);

        StudyYear operator++();

        StudyYear operator--();

        StudyYear operator++(int a);

        StudyYear operator--(int b);



    private:
        int year_;
    };
    std::ostream& operator<<(std::ostream &output, StudyYear studyYear);
    std::istream& operator>>(std::istream &input, StudyYear &studyYear);

    std::ostream& operator<<(std::ostream &output, Student student);
    std::istream& operator>>(std::istream &input, Student &student);
}

#endif //POINT_STUDENT_H
