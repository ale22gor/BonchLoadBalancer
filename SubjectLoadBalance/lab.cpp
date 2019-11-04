#include "lab.h"

Lab::Lab(AdministrativeUnit* administrativeUnit,int housrs):
    Lesson(administrativeUnit, housrs)
{

}

void Lab::test()
{
    qDebug() << "lab :"<<getHours();
}
