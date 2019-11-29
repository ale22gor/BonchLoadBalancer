#include "Constants.h"
#include "SubjectLoadBalance_global.h"

#ifndef ADMINISTRATIVEUNIT_H
#define ADMINISTRATIVEUNIT_H



class SUBJECTLOADBALANCE_EXPORT AdministrativeUnit
{
    Faculty m_faculty;
    int m_amountOfPeople;
    int m_number;
    int m_id;

    bool m_free;
public:

    AdministrativeUnit(Faculty ,int ,int, int, bool = true);
    void test();

    friend class Repositories;
    int getId();
    bool isFree();
};

#endif // ADMINISTRATIVEUNIT_H
