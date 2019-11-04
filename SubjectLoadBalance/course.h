#include "lab.h"
#include "lecture.h"
#include "seminar.h"

#include <list>

#include "SubjectLoadBalance_global.h"

#ifndef COURSE_H
#define COURSE_H


class SUBJECTLOADBALANCE_EXPORT Course
{
    std::list<Lab> m_labs;
    std::list<Lab *> m_freeLabs;

    std::list<Lecture> m_lectures;
    std::list<Lecture *> m_freeLectures;

    std::list<Seminar> m_seminars;
    std::list<Seminar *> m_freeSeminars;

public:
    Course(std::list<Lab>, std::list<Lecture>,std::list<Seminar>);
    bool checkLabs(int);
    bool checkLectures(int);
    bool checkSeminars(int);

    std::list<Lab *> delegateLabs(int);
    std::list<Lecture *> delegateLectures(int);
    std::list<Seminar *> delegateSeminars(int);

    void test();

};

#endif // COURSE_H
