class AdministrativeUnit;

#include "SubjectLoadBalance_global.h"

#include <QtDebug>


#ifndef LESSON_H
#define LESSON_H


class SUBJECTLOADBALANCE_EXPORT Lesson
{
    AdministrativeUnit* m_administrativeUnit;
    int m_hours;
public:
    Lesson(AdministrativeUnit* ,int );
    int getHours();
    void test();
};

#endif // LESSON_H
