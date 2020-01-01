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

int AdministrativeUnit::getNumber() const
{
    return  m_number;
}

int AdministrativeUnit::getamountOfPeople() const
{
    return  m_amountOfPeople;
}

QString AdministrativeUnit::getFaculty() const
{
    switch (m_faculty) {
    case Faculty::RTS:
        return QString("RTS");
    case Faculty::ISIT:
        return QString("ISIT");
    case Faculty::IKSS:
        return QString("IKSS");
    default:
        return QString("ISIT");
    }
}

bool operator==(const AdministrativeUnit &a1, const AdministrativeUnit &a2)
{
    return (a1.m_id == a2.m_id &&
            a1.m_free == a2.m_free &&
            a1.m_number == a2.m_number &&
            a2.m_faculty == a2.m_faculty &&
            a2.m_amountOfPeople == a2.m_amountOfPeople);

}
