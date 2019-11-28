#include "administrativeunit.h"
#include <QDebug>



AdministrativeUnit::AdministrativeUnit(Faculty faculty, int amountOfPeople, int number, int id, bool free):
    m_faculty{faculty},
    m_amountOfPeople{amountOfPeople},
    m_number{number},
    m_id{id},
    m_free{free}
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
