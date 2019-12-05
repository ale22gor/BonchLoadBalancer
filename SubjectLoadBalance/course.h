
#include <list>
#include <memory>
#include <QString>

#include "SubjectLoadBalance_global.h"

class Lab;
class Lecture;
class Seminar;
#ifndef COURSE_H
#define COURSE_H


class SUBJECTLOADBALANCE_EXPORT Course
{
    QString m_courseName;

    std::shared_ptr<Lab> m_lab;

    std::shared_ptr<Lecture> m_lecture;

    std::shared_ptr<Seminar> m_seminar;

    const int m_id;
public:
    Course(Lab, Lecture, Seminar, QString, int =-1);
    Course(Course* , int ,int , int  , int = -1);
    Course();

    QString getName() const;
    int getID();

    std::shared_ptr<Lab> getLab() const;
    std::shared_ptr<Lecture> getLecture() const;
    std::shared_ptr<Seminar> getSeminar() const;

    void test() const;

    friend class Repositories;

};

#endif // COURSE_H
