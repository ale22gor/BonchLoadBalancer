class AdministrativeUnit;

#include "SubjectLoadBalance_global.h"

#include <QtDebug>
#include <memory>


#ifndef LESSON_H
#define LESSON_H


class SUBJECTLOADBALANCE_EXPORT Lesson
{
    std::shared_ptr <AdministrativeUnit> m_administrativeUnit;
    int m_hours;
public:
    Lesson(std::shared_ptr <AdministrativeUnit> ,int );
    int getHours();
    void test();
};

#endif // LESSON_H
