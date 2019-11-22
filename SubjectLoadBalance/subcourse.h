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
    std::shared_ptr<Course> m_course;
    std::shared_ptr<Lab> m_lab;
    std::shared_ptr<Lecture> m_lecture;
    std::shared_ptr<Seminar> m_seminar;

public:
    SubCourse(std::shared_ptr<Course>,int ,int ,int);
    void test();

};

#endif // SUBCOURSE_H
