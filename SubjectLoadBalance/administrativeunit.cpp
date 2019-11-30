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
    qDebug()<<"faculty:"<<m_faculty<<"amount OF people:"<<m_amountOfPeople<<"number:"<<m_number<<"free:"<<isFree();

}

int AdministrativeUnit::getId()
{
    return m_id;
}

bool AdministrativeUnit::isFree()
{
    return m_free;
}

void AdministrativeUnit::setFree(bool value)
{
    m_free = value;
}
