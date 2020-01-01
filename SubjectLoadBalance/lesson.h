
#include "SubjectLoadBalance_global.h"

#include <memory>
#include <list>

#include "administrativeunit.h"

#ifndef LESSON_H
#define LESSON_H


class SUBJECTLOADBALANCE_EXPORT Lesson
{
    std::list<AdministrativeUnit> m_administrativeUnit;
    std::list<int> m_idToUpdate;

    //select * from admunit where pk not in subcourse

    int m_hours;
    int m_amountOfFree;

    const int m_id;

public:
    Lesson(std::list<AdministrativeUnit> ,int ,int);
    Lesson(std::list<AdministrativeUnit> &&,int && ,int);


    int getHours();
    int getID();
    std::list<AdministrativeUnit> getAdmUnit() const;
    int getAdmUnitsAmount() const;

    void test();

    std::list<AdministrativeUnit> delegate(int amount);

    friend bool operator== (const Lesson &l1, const Lesson &l2);
    friend class Repositories;
};

#endif // LESSON_H
