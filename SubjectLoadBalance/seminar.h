#include "lesson.h"

#include "SubjectLoadBalance_global.h"
#include <memory>


#ifndef SEMINAR_H
#define SEMINAR_H


class SUBJECTLOADBALANCE_EXPORT Seminar:public Lesson
{

public:
    Seminar(std::list<AdministrativeUnit>& ,int);
    void test();

};

#endif // SEMINAR_H
