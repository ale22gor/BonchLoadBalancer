#include "subcourse.h"
#include "course.h"
#include "lab.h"
#include "lecture.h"
#include "seminar.h"



SubCourse::SubCourse(Course *course, int seminarAmount,int labAmount, int lecturesamount)
    :m_course{course}
{
    //m_labs = m_course->delegateLabs(labAmount);
    //m_lectures = m_course->delegateLectures(lecturesamount);
    //m_seminars = m_course->delegateSeminars(seminarAmount);
}

void SubCourse::test()
{
    for(auto lab:m_labs){
        lab->test();
    }

    for(auto lecture:m_lectures){
        lecture->test();
    }

    for(auto seminar:m_seminars){
        seminar->test();
    }
}
