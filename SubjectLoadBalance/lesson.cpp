#include "lesson.h"
#include <QtDebug>
#include <algorithm>

Lesson::Lesson(std::list<AdministrativeUnit> administrativeUnit, int hours, int id):
    m_administrativeUnit{administrativeUnit},
    m_hours{hours},
    m_amountOfFree{static_cast<int>(administrativeUnit.size())},
    m_id{id}
{
    //change order and move to :
    //m_freeAdministrativeUnit = m_administrativeUnit;
    //m_hours = hours;
}

Lesson::Lesson(std::list<AdministrativeUnit> &&administrativeUnit, int &&hours, int id):
    m_administrativeUnit{administrativeUnit},
    m_hours{hours},
    m_amountOfFree{static_cast<int>(m_administrativeUnit.size())},
    m_id{id}
{

}

int Lesson::getHours()
{
    return m_hours;
}

int Lesson::getID()
{
    return m_id;
}

std::list<AdministrativeUnit> Lesson::getAdmUnit() const
{
    return m_administrativeUnit;
}

int Lesson::getAdmUnitsAmount() const
{
    return static_cast<int>(m_administrativeUnit.size());
}

void Lesson::test()
{
    qDebug()  <<"lesson" << getHours();
    for(auto &admUnit:m_administrativeUnit){
        admUnit.test();
    }

}

std::list<AdministrativeUnit> Lesson::delegate(int amount)
{

    std::list<AdministrativeUnit> admUinitToDelegate;
    if(m_amountOfFree >= amount && amount > 0){
        m_amountOfFree -=amount;
        std::copy_if(m_administrativeUnit.begin(), m_administrativeUnit.end(), std::back_inserter(admUinitToDelegate),
                     [this](AdministrativeUnit& admUnit)
        {
            bool wasFree{false};
            if(admUnit.isFree()){
                wasFree = true;
                admUnit.setFree(false);
                this->m_idToUpdate.push_back(admUnit.getId());
            }
            return wasFree;
        });

    }
    return admUinitToDelegate;
}
