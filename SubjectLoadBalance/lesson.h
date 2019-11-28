
#include "SubjectLoadBalance_global.h"

#include <memory>
#include <list>

class AdministrativeUnit;

#ifndef LESSON_H
#define LESSON_H


class SUBJECTLOADBALANCE_EXPORT Lesson
{
    std::list<AdministrativeUnit> m_administrativeUnit;

    //select * from admunit where pk not in subcourse

    int m_hours;
    int m_amountOfFree;

public:
    Lesson(std::list<AdministrativeUnit> ,int );
    Lesson(std::list<AdministrativeUnit> &&,int && );


    int getHours();
    void test();

    std::list<AdministrativeUnit> delegate(int amount);

    friend class Repositories;
};

#endif // LESSON_H
