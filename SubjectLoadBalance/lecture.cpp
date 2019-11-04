#include "lecture.h"

Lecture::Lecture(AdministrativeUnit* administrativeUnit,int housrs):
                 Lesson(administrativeUnit, housrs)
{

}

void Lecture::test()
{
    qDebug() << "lecture:"<<getHours();

}
