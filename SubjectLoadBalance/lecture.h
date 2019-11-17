#include "lesson.h"

#include "SubjectLoadBalance_global.h"


#ifndef LECTURE_H
#define LECTURE_H


class SUBJECTLOADBALANCE_EXPORT Lecture:public Lesson
{
public:
    Lecture(std::shared_ptr <AdministrativeUnit> ,int);
    void test();
};

#endif // LECTURE_H
