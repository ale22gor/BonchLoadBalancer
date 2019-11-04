#include "seminar.h"

Seminar::Seminar(AdministrativeUnit* administrativeUnit,int housrs):
    Lesson(administrativeUnit, housrs)
{

}

void Seminar::test()
{
    qDebug() << "seminar:"<<getHours();

}
