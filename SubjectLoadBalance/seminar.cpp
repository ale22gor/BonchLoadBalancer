#include "seminar.h"
#include <QDebug>
#include "administrativeunit.h"


Seminar::Seminar(std::list<AdministrativeUnit>& administrativeUnit,int housrs):
    Lesson(administrativeUnit, housrs)
{

}

Seminar::Seminar(std::list<AdministrativeUnit> && administrativeUnit, int && housrs):
    Lesson(administrativeUnit, housrs)

{

}

void Seminar::test()
{
    qDebug() << "seminar:";
    Lesson::test();

}
