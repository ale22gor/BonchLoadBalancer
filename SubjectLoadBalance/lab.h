#include "lesson.h"

#include "SubjectLoadBalance_global.h"

#ifndef LAB_H
#define LAB_H


class SUBJECTLOADBALANCE_EXPORT Lab:public Lesson
{
public:
    Lab(AdministrativeUnit* ,int);
    void test();
};

#endif // LAB_H
