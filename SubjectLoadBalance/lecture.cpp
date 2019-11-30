#include "lecture.h"
#include <QDebug>
#include "administrativeunit.h"


Lecture::Lecture(std::list<AdministrativeUnit>& administrativeUnit,int housrs,int id):
                 Lesson(administrativeUnit, housrs,id)
{

}

Lecture::Lecture(std::list<AdministrativeUnit>&& administrativeUnit, int&& housrs,int id):
    Lesson(administrativeUnit, housrs,id)

{

}

void Lecture::test()
{
    qDebug() << "lecture:";
    Lesson::test();
}
