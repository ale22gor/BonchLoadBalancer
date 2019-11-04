#include "lesson.h"



Lesson::Lesson(AdministrativeUnit *administrativeUnit, int hours):
    m_administrativeUnit{administrativeUnit},
    m_hours{hours}
{

}

int Lesson::getHours()
{
    return m_hours;
}

void Lesson::test()
{
    qDebug()  <<"lesson";
}
