class Course;
#include <vector>
#include <QString>

#include "SubjectLoadBalance_global.h"

#ifndef PROFESSOR_H
#define PROFESSOR_H


class SUBJECTLOADBALANCE_EXPORT Professor
{
    std::vector <Course> m_subCourses;

    int m_averageHours;
    int m_maxHours;

    QString m_name;
    const int m_id;
public:
    Professor(int, int, QString, int = -1);
    Professor(std::vector <Course>, int , int, QString, int = -1);

    void addSubCourse(Course*,int ,int ,int);
    void test();

    QString getName();
    int getInt();

    friend bool operator== (const Professor &p, const Course &c);
    friend bool operator== (const Professor &p1, const Professor &p2);


    friend class Repositories;
    friend class ProfessorDetail;

};

#endif // PROFESSOR_H
