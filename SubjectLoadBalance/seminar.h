#include "lesson.h"
class AdministrativeUnit;

#include "SubjectLoadBalance_global.h"
#include <list>

#ifndef SEMINAR_H
#define SEMINAR_H


class SUBJECTLOADBALANCE_EXPORT Seminar:public Lesson
{

public:
    Seminar(std::list<AdministrativeUnit>& ,int, int = -1);
    Seminar(std::list<AdministrativeUnit>&& ,int&&, int = -1);

    void test();

};

#endif // SEMINAR_H
