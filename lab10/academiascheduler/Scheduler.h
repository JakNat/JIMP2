//
// Created by bobo on 19.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <set>

using std::map;
using std::set;
using std::vector;


namespace academia{
    class SchedulingItem{
    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    public:
        SchedulingItem(int course_id_, int teacher_id_, int room_id_, int time_slot_, int year_);

        virtual ~SchedulingItem();

        int CourseId() const;

        int TeacherId() const;

        int RoomId() const;

        int TimeSlot() const;

        int Year() const;
    };
    class Schedule{
    private:
        std::vector<SchedulingItem> schedulingItemList_;
        std::vector<int> notAvableTimeSlots;
    public:
        Schedule();

        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        std::size_t Size() const;
        SchedulingItem operator[](int x)const ;
    };
    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(
                const vector<int> &rooms,
                const map<int, vector<int>> &teacher_courses_assignment,
                const map<int, set<int>> &courses_of_year,
                int n_time_slots
        )=0;
    };

    class NoViableSolutionFound {};

    class GreedyScheduler : public Scheduler {
    public:
        Schedule PrepareNewSchedule(
                const vector<int> &rooms,
                const map<int, vector<int>> &teacher_courses_assignment,
                const map<int, set<int>> &courses_of_year,
                int n_time_slots
        );
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
