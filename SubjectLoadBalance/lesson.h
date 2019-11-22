class AdministrativeUnit;

#include "SubjectLoadBalance_global.h"

#include <QtDebug>
#include <memory>
#include<list>

#ifndef LESSON_H
#define LESSON_H


class SUBJECTLOADBALANCE_EXPORT Lesson
{
    std::list<std::shared_ptr <AdministrativeUnit> > m_administrativeUnit;
    std::list<std::shared_ptr <AdministrativeUnit> > m_freeAdministrativeUnit;

    //select * from admunit where pk not in subcourse

    int m_hours;
public:
    Lesson(std::list<AdministrativeUnit>& ,int );
    Lesson(std::list<std::shared_ptr <AdministrativeUnit> > ,int );

    int getHours();
    void test();

    std::list<std::shared_ptr <AdministrativeUnit> > delegate(int amount);

    friend class Repositories;
};

#endif // LESSON_H
