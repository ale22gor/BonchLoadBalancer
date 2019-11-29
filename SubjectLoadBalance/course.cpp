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

}
Course::Course(Course* course, int labAmount,int lecturesamount, int  seminarAmount)
{
    //check if course == this -> break
    std::list<AdministrativeUnit> admUnits{course->m_lab->delegate(labAmount)};
    if(admUnits.size()>0)
        m_lab = std::make_shared<Lab>(admUnits, course->m_lab->getHours());

    admUnits = course->m_lecture->delegate(lecturesamount);
    if(admUnits.size()>0)
            m_lecture =  std::make_shared<Lecture>(admUnits, course->m_lecture->getHours());

    admUnits = course->m_seminar->delegate(seminarAmount);
    if(admUnits.size()>0)
            m_seminar =  std::make_shared<Seminar>(admUnits, course->m_seminar->getHours());

}




void Course::test()
{
    if(m_lab != nullptr)
        m_lab->test();
    if(m_lecture != nullptr)
        m_lecture->test();
    if(m_seminar != nullptr)
        m_seminar->test();

}
