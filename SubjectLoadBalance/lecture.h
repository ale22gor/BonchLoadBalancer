#include "lesson.h"

#include "SubjectLoadBalance_global.h"


#ifndef LECTURE_H
#define LECTURE_H


class SUBJECTLOADBALANCE_EXPORT Lecture:public Lesson
{
public:
    Lecture(std::list<AdministrativeUnit>& ,int);
    void test();
};

#endif // LECTURE_H
