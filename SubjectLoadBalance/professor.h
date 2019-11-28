class Course;
#include <list>
#include <QString>

#include "SubjectLoadBalance_global.h"

#ifndef PROFESSOR_H
#define PROFESSOR_H


class SUBJECTLOADBALANCE_EXPORT Professor
{
    std::list <Course>m_subCourses;

    int m_averageHours;
    int m_maxHours;

    QString m_name;
public:
    Professor(int , int );
    void addSubCourse(Course*,int ,int ,int);
    void test();

    QString getName();

    friend class Repositories;
};

#endif // PROFESSOR_H
