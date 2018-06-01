//
// Created by bobo on 01.06.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H
#include <string>
namespace academia{

    class TeacherId{
    public:
        TeacherId();
        TeacherId(int id);
        operator int() const;


    private:
        int _id;
    };

    class Teacher{
    public:
        Teacher(TeacherId,std::string,std::string);
        int Id() const ;
        std::string Name() const ;
        std::string Department() const ;
        bool operator==(Teacher t) const ;
        bool operator!=(Teacher t) const ;
    private:
        TeacherId teacherId_;
        std::string name_;
        std::string place_;

    };

    class TeacherHash{
    public:
        size_t operator ()(const Teacher &teacher) const;
    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
