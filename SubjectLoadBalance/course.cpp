#include "course.h"


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




void Course::test()
{
    m_lab->test();
    m_lecture->test();
    m_seminar->test();

}
