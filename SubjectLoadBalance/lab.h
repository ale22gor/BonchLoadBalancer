#include "lesson.h"
class AdministrativeUnit;

#include "SubjectLoadBalance_global.h"
#include <list>

#ifndef LAB_H
#define LAB_H


class SUBJECTLOADBALANCE_EXPORT Lab:public Lesson
{
public:
    Lab(std::list<AdministrativeUnit>& ,int, int = -1);

    Lab(std::list<AdministrativeUnit>&& ,int&&, int = -1);


    void test();



};

#endif // LAB_H
