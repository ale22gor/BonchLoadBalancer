#include "course.h"

#include "lab.h"
#include "lecture.h"
#include "seminar.h"

QString Course::getName() const
{
    return m_courseName;
}

Course::Course(Lab lab, Lecture lecture, Seminar seminar, QString name, int id)
    :m_courseName{name},
      m_id{id}
{
    if(lab.getAdmUnitsAmount() > 0 && lab.getHours() > 0)
        m_lab =  std::make_shared<Lab>(lab);
    if(lecture.getAdmUnitsAmount() > 0 && lecture.getHours() > 0)
        m_lecture =  std::make_shared<Lecture>(lecture);
    if(seminar.getAdmUnitsAmount() > 0 && seminar.getHours() > 0)
        m_seminar =  std::make_shared<Seminar>(seminar);

}

Course::Course(Lab lab, Lecture lecture, QString name, int id)
    :m_courseName{name},
      m_id{id}
{
    if(lab.getAdmUnitsAmount() > 0 && lab.getHours() > 0)
        m_lab =  std::make_shared<Lab>(lab);
    if(lecture.getAdmUnitsAmount() > 0 && lecture.getHours() > 0)
        m_lecture =  std::make_shared<Lecture>(lecture);

}

Course::Course(Lab lab, Seminar seminar, QString name, int id)
    :m_courseName{name},
      m_id{id}
{
    if(lab.getAdmUnitsAmount() > 0 && lab.getHours() > 0)
        m_lab =  std::make_shared<Lab>(lab);

    if(seminar.getAdmUnitsAmount() > 0 && seminar.getHours() > 0)
        m_seminar =  std::make_shared<Seminar>(seminar);

}

Course::Course(Lecture lecture, Seminar seminar, QString name, int id)
    :m_courseName{name},
      m_id{id}
{

    if(lecture.getAdmUnitsAmount() > 0 && lecture.getHours() > 0)
        m_lecture =  std::make_shared<Lecture>(lecture);
    if(seminar.getAdmUnitsAmount() > 0 && seminar.getHours() > 0)
        m_seminar =  std::make_shared<Seminar>(seminar);

}

Course::Course(Lab lab, QString name, int id)
    :m_courseName{name},
      m_id{id}
{
    if(lab.getAdmUnitsAmount() > 0 && lab.getHours() > 0)
        m_lab =  std::make_shared<Lab>(lab);


}

Course::Course(Lecture lecture, QString name, int id)
    :m_courseName{name},
      m_id{id}
{
    if(lecture.getAdmUnitsAmount() > 0 && lecture.getHours() > 0)
        m_lecture =  std::make_shared<Lecture>(lecture);

}

Course::Course(Seminar seminar, QString name, int id)
    :m_courseName{name},
      m_id{id}
{

    if(seminar.getAdmUnitsAmount() > 0 && seminar.getHours() > 0)
        m_seminar =  std::make_shared<Seminar>(seminar);

}
Course::Course(Course* course, int labAmount,int lecturesamount, int  seminarAmount, int id):
    m_id{id}
{

    //check if course == this -> break
    //if(this == course)
        //return;

    std::list<AdministrativeUnit> admUnits;
    //add move to
    if(labAmount > 0){
        admUnits = course->m_lab->delegate(labAmount);
        if(admUnits.size()>0)
            m_lab = std::make_shared<Lab>(admUnits, course->m_lab->getHours());
    }
    if(lecturesamount > 0){
        admUnits = course->m_lecture->delegate(lecturesamount);
        if(admUnits.size()>0)
            m_lecture =  std::make_shared<Lecture>(admUnits, course->m_lecture->getHours());
    }
    if(seminarAmount > 0){
        admUnits = course->m_seminar->delegate(seminarAmount);
        if(admUnits.size()>0)
            m_seminar =  std::make_shared<Seminar>(admUnits, course->m_seminar->getHours());
    }
    m_courseName = course->getName();


}

std::shared_ptr<Lab> Course::getLab() const
{
    return m_lab;
}

std::shared_ptr<Lecture> Course::getLecture() const
{
    return m_lecture;
}

std::shared_ptr<Seminar> Course::getSeminar() const
{
    return m_seminar;
}




void Course::test() const
{
    if(m_lab != nullptr)
        m_lab->test();
    if(m_lecture != nullptr)
        m_lecture->test();
    if(m_seminar != nullptr)
        m_seminar->test();

}
