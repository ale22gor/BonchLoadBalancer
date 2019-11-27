class Course;
#include <list>

#include "SubjectLoadBalance_global.h"

#ifndef PROFESSOR_H
#define PROFESSOR_H


class SUBJECTLOADBALANCE_EXPORT Professor
{
    std::list <Course>m_subCourses;
    int m_averageHours;
    int m_maxHours;
public:
    Professor(int , int );
    void addSubCourse(Course*,int ,int ,int);
    void test();
};

#endif // PROFESSOR_H
