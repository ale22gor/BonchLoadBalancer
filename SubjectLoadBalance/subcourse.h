class Course;

class Lab;
class Lecture;
class Seminar;

#include <list>

#include "SubjectLoadBalance_global.h"

#ifndef SUBCOURSE_H
#define SUBCOURSE_H


class SUBJECTLOADBALANCE_EXPORT SubCourse
{
    Course *m_course;
    std::list<Lab *> m_labs;
    std::list<Lecture *> m_lectures;
    std::list<Seminar *> m_seminars;
public:
    SubCourse(Course*,int ,int ,int);
    void test();

};

#endif // SUBCOURSE_H
