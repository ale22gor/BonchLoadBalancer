#include "lab.h"
#include "lecture.h"
#include "seminar.h"
#include "group.h"

#include <list>
#include <memory>
#include <string>

#include "SubjectLoadBalance_global.h"

#ifndef COURSE_H
#define COURSE_H


class SUBJECTLOADBALANCE_EXPORT Course
{
    std::string m_courseName;

    std::list<std::shared_ptr<Lab> >m_labs;
    std::list<std::shared_ptr<Lab> > m_freeLabs;

    std::list<std::shared_ptr<Lecture> > m_lectures;
    std::list<std::shared_ptr<Lecture> > m_freeLectures;

    std::list<std::shared_ptr<Seminar> > m_seminars;
    std::list<std::shared_ptr<Seminar> > m_freeSeminars;

public:
    Course(std::list<std::shared_ptr<Lab> >, std::list<std::shared_ptr<Lecture> >,std::list<std::shared_ptr<Seminar> >);
    Course();

    bool checkLabs(int);
    bool checkLectures(int);
    bool checkSeminars(int);

    void addLabs(std::shared_ptr<Group>, int);
    void addLecture(std::shared_ptr<Group>, int);
    void addSeminar(std::shared_ptr<Group>, int);

    std::list<std::shared_ptr<Lab> > delegateLabs(int);
    std::list<std::shared_ptr<Lecture> > delegateLectures(int);
    std::list<std::shared_ptr<Seminar> > delegateSeminars(int);

    void test();

};

#endif // COURSE_H
