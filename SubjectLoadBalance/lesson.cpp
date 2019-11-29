#include "lesson.h"
#include <QtDebug>
#include <algorithm>

Lesson::Lesson(std::list<AdministrativeUnit> administrativeUnit, int hours):
    m_administrativeUnit{administrativeUnit},
    m_hours{hours},
    m_amountOfFree{static_cast<int>(administrativeUnit.size())}
{
    //change order and move to :
    //m_freeAdministrativeUnit = m_administrativeUnit;
    //m_hours = hours;
}

Lesson::Lesson(std::list<AdministrativeUnit> &&administrativeUnit, int &&hours):
    m_administrativeUnit{administrativeUnit},
    m_hours{hours},
    m_amountOfFree{static_cast<int>(m_administrativeUnit.size())}

{

}

int Lesson::getHours()
{
    return m_hours;
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
    if(m_amountOfFree >= amount && amount > 0){
        m_amountOfFree -=amount;
        std::list<AdministrativeUnit> admUinitToDelegate;

        std::copy_if(m_administrativeUnit.begin(), m_administrativeUnit.end(), std::back_inserter(admUinitToDelegate),
                     [](AdministrativeUnit admUnit){return admUnit.isFree() ;});

        return admUinitToDelegate;
    }

}
