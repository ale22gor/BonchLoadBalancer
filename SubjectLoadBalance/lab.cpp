#include "lab.h"

Lab::Lab(std::list<AdministrativeUnit>& administrativeUnit,int hours):
    Lesson(administrativeUnit, hours)
{

}

Lab::Lab(std::list<std::shared_ptr<AdministrativeUnit> > administrativeUnit, int hours):
    Lesson(administrativeUnit, hours)
{

}


void Lab::test()
{
    qDebug() << "lab :"<<getHours();
}
