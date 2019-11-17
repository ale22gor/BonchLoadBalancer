#include "lesson.h"

#include "SubjectLoadBalance_global.h"
#include <memory>

#ifndef SEMINAR_H
#define SEMINAR_H


class SUBJECTLOADBALANCE_EXPORT Seminar:public Lesson
{
public:
    Seminar(std::shared_ptr <AdministrativeUnit> ,int);
    void test();

};

#endif // SEMINAR_H
