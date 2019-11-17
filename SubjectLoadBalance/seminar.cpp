#include "seminar.h"

Seminar::Seminar(std::shared_ptr <AdministrativeUnit> administrativeUnit,int housrs):
    Lesson(administrativeUnit, housrs)
{

}

void Seminar::test()
{
    qDebug() << "seminar:"<<getHours();

}
