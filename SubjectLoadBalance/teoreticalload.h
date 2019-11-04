class Course;
#include <list>

#include "SubjectLoadBalance_global.h"

#ifndef TEORETICALLOAD_H
#define TEORETICALLOAD_H


class SUBJECTLOADBALANCE_EXPORT teoreticalLoad
{
    std::list <Course*> m_courses;
public:
    teoreticalLoad();
    void addCourse(Course*);
};

#endif // TEORETICALLOAD_H
