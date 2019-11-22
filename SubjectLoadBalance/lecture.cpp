#include "lecture.h"

Lecture::Lecture(std::list<AdministrativeUnit>& administrativeUnit,int housrs):
                 Lesson(administrativeUnit, housrs)
{

}

void Lecture::test()
{
    qDebug() << "lecture:"<<getHours();

}
