#include "lab.h"
#include <QDebug>
#include "administrativeunit.h"

Lab::Lab(std::list<AdministrativeUnit>& administrativeUnit,int hours, int id):
    Lesson(administrativeUnit, hours,id)
{

}

Lab::Lab(std::list<AdministrativeUnit> && administrativeUnit, int && hours,int id):
    Lesson(administrativeUnit, hours,id)
{

}

void Lab::test()
{
    qDebug() << "lab :";
    Lesson::test();
}
