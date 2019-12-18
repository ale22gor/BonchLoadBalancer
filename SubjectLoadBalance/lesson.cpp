#include "lesson.h"
#include <QtDebug>
#include <algorithm>

Lesson::Lesson(std::list<AdministrativeUnit> administrativeUnit, int hours, int id):
    m_administrativeUnit{administrativeUnit},
    m_hours{hours},
    m_id{id}
{
    m_amountOfFree = std::count_if(m_administrativeUnit.begin(), m_administrativeUnit.end(),[](AdministrativeUnit& admUnit)
    {
            return admUnit.isFree();
    });
    //change order and move to :
    //m_freeAdministrativeUnit = m_administrativeUnit;
    //m_hours = hours;
}

Lesson::Lesson(std::list<AdministrativeUnit> &&administrativeUnit, int &&hours, int id):
    m_administrativeUnit{administrativeUnit},
    m_hours{hours},
    m_id{id}
{
    m_amountOfFree = std::count_if(m_administrativeUnit.begin(), m_administrativeUnit.end(),[](AdministrativeUnit& admUnit)
    {
            return admUnit.isFree();
    });
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
    qDebug()<<"m_amountOfFree"<<m_amountOfFree;

}

std::list<AdministrativeUnit> Lesson::delegate(int amount)
{

    std::list<AdministrativeUnit> admUinitToDelegate;
    //qDebug()<<"m_amountOfFree"<<m_amountOfFree;
    qDebug()<<"amount"<<amount;

    if(m_amountOfFree >= amount && amount > 0){
        m_amountOfFree -=amount;

        //rewrite to stop check after n(custom copy_if_n kinda function)
        int amountOffound{0};

        std::copy_if(m_administrativeUnit.begin(), m_administrativeUnit.end(), std::back_inserter(admUinitToDelegate),
                     [this,&amount,amountOffound] (AdministrativeUnit& admUnit) mutable
        {
            if (amountOffound >= amount)
                return false;
            bool wasFree{false};
            if(admUnit.isFree()){
                amountOffound++;
                wasFree = true;
                admUnit.setFree(false);
                this->m_idToUpdate.push_back(admUnit.getId());
            }
            return wasFree;
        });
    }
    //qDebug()<<"m_amountOfFree"<<m_amountOfFree;

    return admUinitToDelegate;
}
