class Course;

class Lab;
class Lecture;
class Seminar;

#include <list>
#include <memory>

#include "SubjectLoadBalance_global.h"

#ifndef SUBCOURSE_H
#define SUBCOURSE_H


class SUBJECTLOADBALANCE_EXPORT SubCourse
{
    Course *m_course;
    std::list<std::shared_ptr<Lab> > m_labs;
    std::list<std::shared_ptr<Lecture> > m_lectures;
    std::list<std::shared_ptr<Seminar> > m_seminars;
public:
    SubCourse(Course*,int ,int ,int);
    void test();

};

#endif // SUBCOURSE_H
