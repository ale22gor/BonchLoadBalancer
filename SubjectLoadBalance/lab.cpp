#include "lab.h"

Lab::Lab(std::shared_ptr <AdministrativeUnit> administrativeUnit,int housrs):
    Lesson(administrativeUnit, housrs)
{

}

void Lab::test()
{
    qDebug() << "lab :"<<getHours();
}
