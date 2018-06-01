//
// Created by bobo on 01.06.18.
//

#include "TeacherHash.h"

namespace academia{
    TeacherId::TeacherId() {}

    TeacherId::TeacherId(int id) {
        _id = id;
    }
     TeacherId::operator int() const {
        return _id;
    }

    Teacher::Teacher(academia::TeacherId id, std::string name, std::string place) {
        teacherId_ = id;
        name_ = name;
        place_ = place;
    }
    int Teacher::Id() const{
        return  teacherId_;
    }
    std::string Teacher::Name() const {
        return name_;
    }
    std::string Teacher::Department() const{
        return place_;
    }
    bool Teacher::operator==(academia::Teacher t) const {
        if(teacherId_ == t.teacherId_ && name_ == t.name_ && place_ == t.place_){
            return true;
        }
        return false;
    }
    bool Teacher::operator!=(academia::Teacher t) const {
        if(teacherId_ == t.teacherId_ && name_ == t.name_ && place_ == t.place_){
            return false;
        }
        return true;
    }

    size_t TeacherHash::operator()(const academia::Teacher &teacher) const {
        size_t hashName = std::hash<std::string>{}(teacher.Name());
        size_t hashDepartment = std::hash<std::string>{}(teacher.Department());
        return  teacher.Id() * hashName + hashDepartment;
    }
}