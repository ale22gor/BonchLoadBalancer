#include "seminar.h"

Seminar::Seminar(std::list<AdministrativeUnit>& administrativeUnit,int housrs):
    Lesson(administrativeUnit, housrs)
{

}

void Seminar::test()
{
    qDebug() << "seminar:"<<getHours();

}
