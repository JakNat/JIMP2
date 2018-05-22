//
// Created by bobo on 19.05.18.
//

#include <iostream>
#include "Scheduler.h"


using namespace academia;
int main (){
    Schedule schedule;
    schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
    schedule.InsertScheduleItem(SchedulingItem {5, 6, 7, 8, 9});
    SchedulingItem x{0, 1, 2, 3, 4};

    Schedule firstTeacherSchedule = schedule.OfTeacher(1);
   // std::cout<< firstTeacherSchedule.Size();
           std::cout<<schedule[1].CourseId();
    //std::cout<<x.CourseId();
  //  std::cout<<firstTeacherSchedule[0].TeacherId();
  //  std::cout<<firstTeacherSchedule[0].RoomId();
   // std::cout<<firstTeacherSchedule[0].TimeSlot();
}