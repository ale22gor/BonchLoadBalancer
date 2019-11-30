#include "seminar.h"
#include <QDebug>
#include "administrativeunit.h"


Seminar::Seminar(std::list<AdministrativeUnit>& administrativeUnit,int housrs,int id):
    Lesson(administrativeUnit, housrs,id)
{

}

Seminar::Seminar(std::list<AdministrativeUnit> && administrativeUnit, int && housrs,int id):
    Lesson(administrativeUnit, housrs,id)

{

}

void Seminar::test()
{
    qDebug() << "seminar:";
    Lesson::test();

}
