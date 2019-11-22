#include "lab.h"
#include "lecture.h"
#include "seminar.h"
#include "group.h"

#include <list>
#include <memory>
#include <QString>

#include "SubjectLoadBalance_global.h"

#ifndef COURSE_H
#define COURSE_H


class SUBJECTLOADBALANCE_EXPORT Course
{
    QString m_courseName;

    std::shared_ptr<Lab> m_lab;

    std::shared_ptr<Lecture> m_lecture;

    std::shared_ptr<Seminar> m_seminar;

public:
    Course(Lab, Lecture, Seminar );
    Course();

    QString getName();

    void test();

    friend class SubCourse;
    friend class Repositories;

};

#endif // COURSE_H
