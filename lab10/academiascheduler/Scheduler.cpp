//
// Created by bobo on 19.05.18.
//

#include <vector>
#include "Scheduler.h"

namespace academia{
    ////////////ScheludingItem//////////////////////////////////////
    SchedulingItem::SchedulingItem(int course_id_, int teacher_id_, int room_id_, int time_slot_, int year_)
            : course_id_(course_id_), teacher_id_(teacher_id_), room_id_(room_id_), time_slot_(time_slot_),
              year_(year_) {}

    SchedulingItem::~SchedulingItem() {


    }

    int SchedulingItem::CourseId() const {
        return course_id_;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId() const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }

    //////////////Schedule////////////////////////////////////////
    Schedule::Schedule() {}
    SchedulingItem Schedule::operator[](int x) const {
        int a = 0;
        for(auto SI : schedulingItemList_){
            if(a == x){
                return SI;
            }a++;
        }
    }
    std::size_t Schedule::Size() const {
        return schedulingItemList_.size();
    }
    void Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
        schedulingItemList_.push_back(item);
    }
    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule newSchedule;
        for(auto x : schedulingItemList_){
            if (x.TeacherId() == teacher_id){
                newSchedule.InsertScheduleItem(x);
            }
        }
        return newSchedule;
    }
    Schedule Schedule::OfRoom(int room_id) const {
        Schedule newSchedule;
        for(auto x : schedulingItemList_){
            if (x.RoomId() == room_id){
                newSchedule.InsertScheduleItem(x);
            }
        }
        return newSchedule;
    }
    Schedule Schedule::OfYear(int year) const {
        Schedule newSchedule;
        for(auto x : schedulingItemList_){
            if (x.Year() == year){
                newSchedule.InsertScheduleItem(x);
            }
        }
        return newSchedule;
    }
    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> newVector;
        if(schedulingItemList_.size() == 0){
            for (int i = 1; i <= n_time_slots; ++i) {
                newVector.push_back(i);
            }
            return newVector;

        }
        for (int i = 1; i <= n_time_slots; ++i) {
            newVector.push_back(i);
            for (int j = 0; j <= n_time_slots; ++j) {
                if (schedulingItemList_[j].TimeSlot() == i) {
                    newVector.pop_back();
                    break;
                }
            }
        }

            return newVector;
    }

Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                             const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                             const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {
    Schedule schedule;

    int scheduling_items_s = 0;
    int lessonsAmount = 0;
    int yearsAmount = 0;
    map<int, int> lessonAmountPerYear;
    for (auto year : teacher_courses_assignment) {
        yearsAmount++;
        std::pair<int, int> p(yearsAmount, 0);
        //   lessonAmountPerYear.insert(YearsAmount,0);
        for (auto lesson : year.second) {
            lessonsAmount++;
            lessonAmountPerYear[yearsAmount]++;
        }
    }
    int x = 0;
    for (auto teacher : teacher_courses_assignment) {
        for (auto lesson : teacher.second) {
            for (auto year : courses_of_year) {
                for (auto lessonYear : year.second) {
                    if (lesson == lessonYear && year.first == 1) {
                        x++;
                    }
                }
            }
        }
    }
    if (x > n_time_slots) {
        throw NoViableSolutionFound();
    }
    if (lessonsAmount > n_time_slots * rooms.size()) {
        throw NoViableSolutionFound();
    }
    for (auto room : rooms) {
        for (int i = 0; i < n_time_slots; ++i) {
            for (auto teacher : teacher_courses_assignment) {
                int y = teacher.first;
                for (auto lesson : teacher.second) {
                    int l = lesson;
                    bool a = false;
                    for (auto year : courses_of_year) {
                        for (auto yearLesson : year.second) {
                            if (a) { break; }
                            if (yearLesson == lesson) {
                                schedule.InsertScheduleItem(SchedulingItem(lesson, teacher.first, room, i, year.first));

                                scheduling_items_s++;
                                lessonsAmount--;
                                yearLesson = 0;
                                if (lessonsAmount == 0) { return schedule; }
                                i++;
                                a = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        for (auto room : rooms) {

            for (int i = 0; i < n_time_slots; ++i) {
                for (auto year : courses_of_year) {
                    int y = year.first;
                    for (auto lesson : year.second) {
                        int l = lesson;
                        bool a = false;
                        for (auto teacher : teacher_courses_assignment) {
                            for (auto teacherLesson : teacher.second) {
                                if (a) { break; }
                                if (teacherLesson == lesson) {
                                    schedule.InsertScheduleItem(
                                            SchedulingItem(lesson, teacher.first, room, i, year.first));

                                    scheduling_items_s++;
                                    lessonsAmount--;
                                    teacherLesson = 0;
                                    if (lessonsAmount == 0) { return schedule; }
                                    i++;
                                    a = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
//    int x = lessonAmountPerYear[1];

        return schedule;
    }


}}