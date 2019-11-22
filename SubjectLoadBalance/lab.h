#include "lesson.h"

#include "SubjectLoadBalance_global.h"
#include <memory>

#ifndef LAB_H
#define LAB_H


class SUBJECTLOADBALANCE_EXPORT Lab:public Lesson
{
public:
    Lab(std::list<AdministrativeUnit>& ,int);
    Lab(std::list<std::shared_ptr<AdministrativeUnit> > administrativeUnit, int hours);

    void test();



};

#endif // LAB_H
