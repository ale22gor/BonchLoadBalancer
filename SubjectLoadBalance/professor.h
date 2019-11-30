class Course;
#include <list>
#include <QString>

#include "SubjectLoadBalance_global.h"

#ifndef PROFESSOR_H
#define PROFESSOR_H


class SUBJECTLOADBALANCE_EXPORT Professor
{
    std::list <Course> m_subCourses;

    int m_averageHours;
    int m_maxHours;

    QString m_name;
    const int m_id;
public:
    Professor(int, int, QString, int = -1);
    Professor(std::list <Course>, int , int, QString, int = -1);

    void addSubCourse(Course*,int ,int ,int);
    void test();

    QString getName();
    int getInt();

    friend class Repositories;
};

#endif // PROFESSOR_H
