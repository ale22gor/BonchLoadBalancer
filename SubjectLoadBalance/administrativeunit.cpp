#include "administrativeunit.h"
#include <QDebug>



AdministrativeUnit::AdministrativeUnit(Faculty faculty, int amountOfPeople, int number):
    m_faculty{faculty},
    m_amountOfPeople{amountOfPeople},
    m_number{number},
    m_free{true}
{

}

void AdministrativeUnit::test()
{
    qDebug()<<m_faculty<<m_amountOfPeople<<m_number;

}

int AdministrativeUnit::getId()
{
    return m_id;
}

bool AdministrativeUnit::isFree()
{
    return m_free;
}
