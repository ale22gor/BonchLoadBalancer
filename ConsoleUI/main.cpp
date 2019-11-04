#include <QCoreApplication>
#include <list>

#include "course.h"
#include "lab.h"
#include "lecture.h"
#include "seminar.h"
#include "group.h"
#include "Constants.h"
#include "professor.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Group group{Faculty::ISIT,25,632};
    group.test();

    std::list<Lab> labs{{&group,13}};
    std::list<Lecture> lectures{{&group,13}};
    std::list<Seminar> seminars{{&group,13}};

    Course myCourse{labs,lectures,seminars};
    myCourse.test();

    Professor prof{500,600};
    prof.addSubCourse(&myCourse,1,1,1);
    prof.test();


    return a.exec();
}
