#include "course.h"

#include "lab.h"
#include "lecture.h"
#include "seminar.h"

Course::Course(){

}

QString Course::getName()
{
    return m_courseName;
}

Course::Course(Lab lab, Lecture lecture, Seminar seminar)
{
    m_lab =  std::make_shared<Lab>(lab);
    m_lecture =  std::make_shared<Lecture>(lecture);
    m_seminar =  std::make_shared<Seminar>(seminar);

    /*
    for(auto &lab:m_labs){
        m_freeLabs.push_back(&lab);
    }

    for(auto &lecture:m_lectures){
        m_freeLectures.push_back(&lecture);
    }

    for(auto &seminar:m_seminars){
        m_freeSeminars.push_back(&seminar);
    }
    */
}
Course::Course(Course* course, int labAmount,int lecturesamount, int  seminarAmount)
{
    //check if course == this -> break
    std::list<AdministrativeUnit> admUnits{course->m_lab->delegate(labAmount)};
    m_lab = {std::make_shared<Lab>(admUnits, course->m_lab->getHours()) };
    //m_labs = m_course->delegateLabs(labAmount);
    //m_lectures = m_course->delegateLectures(lecturesamount);
    //m_seminars = m_course->delegateSeminars(seminarAmount);
}




void Course::test()
{
    m_lab->test();
    m_lecture->test();
    m_seminar->test();

}
