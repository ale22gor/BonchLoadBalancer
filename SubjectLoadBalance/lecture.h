#include "lesson.h"
class AdministrativeUnit;

#include "SubjectLoadBalance_global.h"
#include <list>

#ifndef LECTURE_H
#define LECTURE_H


class SUBJECTLOADBALANCE_EXPORT Lecture:public Lesson
{
public:
    Lecture(std::list<AdministrativeUnit>& ,int, int = -1);
    Lecture(std::list<AdministrativeUnit>&& ,int&&, int = -1);

    void test();
};

#endif // LECTURE_H
