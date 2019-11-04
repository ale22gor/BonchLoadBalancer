#include "lesson.h"

#include "SubjectLoadBalance_global.h"

#ifndef SEMINAR_H
#define SEMINAR_H


class SUBJECTLOADBALANCE_EXPORT Seminar:public Lesson
{
public:
    Seminar(AdministrativeUnit* ,int);
    void test();

};

#endif // SEMINAR_H
