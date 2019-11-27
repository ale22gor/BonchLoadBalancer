#include "lesson.h"
class AdministrativeUnit;

#include "SubjectLoadBalance_global.h"
#include <list>

#ifndef LECTURE_H
#define LECTURE_H


class SUBJECTLOADBALANCE_EXPORT Lecture:public Lesson
{
public:
    Lecture(std::list<AdministrativeUnit>& ,int);
    void test();
};

#endif // LECTURE_H
