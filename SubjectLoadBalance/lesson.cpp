#include "lesson.h"
#include "administrativeunit.h"
#include <QtDebug>


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
    qDebug()  <<"lesson";
    for(auto &admUnit:m_administrativeUnit){
        admUnit.test();
    }

}

std::list<AdministrativeUnit> Lesson::delegate(int amount)
{
    if(m_amountOfFree >= amount){
        m_amountOfFree -=amount;
        //copy_if admUnit if free (m_administrativeUnit)
        //return copy_if result
        auto end =  std::next(m_administrativeUnit.begin(),amount);
        std::list<AdministrativeUnit> admUinitToDelegate{m_administrativeUnit.begin(),end};

        return admUinitToDelegate;
    }
    //return std::list<std::shared_ptr<AdministrativeUnit> >;

}
