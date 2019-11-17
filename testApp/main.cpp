#include <QCoreApplication>
#include <list>

#include "course.h"
#include "lab.h"
#include "lecture.h"
#include "seminar.h"
#include "group.h"
#include "Constants.h"
#include "professor.h"

#include "repositories.h"

#include <memory>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::shared_ptr <Group> group {new Group{Faculty::ISIT,25,632}};
    group->test();

    std::shared_ptr<Lab> a1{new Lab{group,13}};
    //a1->test();
    std::list<std::shared_ptr<Lab> >labs;
    labs.push_back(a1);

    std::shared_ptr<Lecture> a2{new Lecture{group,13}};
    //a2->test();
    std::list<std::shared_ptr<Lecture> >lectures;
    lectures.push_back(a2);

    std::shared_ptr<Seminar> a3{new Seminar{group,13}};
    //a3->test();
    std::list<std::shared_ptr<Seminar> >seminars;
    seminars.push_back(a3);

    Course myCourse{labs,lectures,seminars};
    myCourse.test();

    Repositories<int> testR;


    //Professor prof{500,600};
    //prof.addSubCourse(&myCourse,1,1,1);
    //prof.test();


    return a.exec();
}
