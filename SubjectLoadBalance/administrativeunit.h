#include "Constants.h"
#include "SubjectLoadBalance_global.h"

#ifndef ADMINISTRATIVEUNIT_H
#define ADMINISTRATIVEUNIT_H



class SUBJECTLOADBALANCE_EXPORT AdministrativeUnit
{
    Faculty m_faculty;
    int m_amountOfPeople;
    int m_number;
public:

    AdministrativeUnit(Faculty ,int ,int );
    void test();
};

#endif // ADMINISTRATIVEUNIT_H
