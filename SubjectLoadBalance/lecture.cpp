#include "lecture.h"

Lecture::Lecture(std::shared_ptr <AdministrativeUnit> administrativeUnit,int housrs):
                 Lesson(administrativeUnit, housrs)
{

}

void Lecture::test()
{
    qDebug() << "lecture:"<<getHours();

}
