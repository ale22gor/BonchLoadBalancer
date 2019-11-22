#include "lesson.h"
#include "administrativeunit.h"


Lesson::Lesson(std::list<AdministrativeUnit>& administrativeUnit, int hours)
{
    for(auto& admUnit:administrativeUnit){
        m_administrativeUnit.push_back(std::make_shared<AdministrativeUnit>(admUnit));
    }
    //change order and move to :
    m_freeAdministrativeUnit = m_administrativeUnit;
    m_hours = hours;
}

Lesson::Lesson(std::list<std::shared_ptr<AdministrativeUnit> > administrativeUnit, int hours):
    m_administrativeUnit{administrativeUnit},
    m_hours{hours}
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
        admUnit->test();
    }

}

std::list<std::shared_ptr <AdministrativeUnit> > Lesson::delegate(int amount)
{
    if(static_cast<int>(m_freeAdministrativeUnit.size()) >= amount){
        auto end =  std::next(m_freeAdministrativeUnit.begin(),amount);
        std::list<std::shared_ptr<AdministrativeUnit> > admUinitToDelegate{m_freeAdministrativeUnit.begin(),end};

        m_freeAdministrativeUnit.erase(m_freeAdministrativeUnit.begin(),end);
        return admUinitToDelegate;
    }
    //return std::list<std::shared_ptr<AdministrativeUnit> >;

}
