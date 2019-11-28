#include "lab.h"
#include <QDebug>
#include "administrativeunit.h"

Lab::Lab(std::list<AdministrativeUnit>& administrativeUnit,int hours):
    Lesson(administrativeUnit, hours)
{

}

Lab::Lab(std::list<AdministrativeUnit> && administrativeUnit, int && hours):
    Lesson(administrativeUnit, hours)
{

}

void Lab::test()
{
    qDebug() << "lab :"<<getHours();
}
