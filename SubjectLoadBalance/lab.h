#include "lesson.h"

#include "SubjectLoadBalance_global.h"
#include <memory>

#ifndef LAB_H
#define LAB_H


class SUBJECTLOADBALANCE_EXPORT Lab:public Lesson
{
public:
    Lab(std::shared_ptr <AdministrativeUnit> ,int);
    void test();

};

#endif // LAB_H
