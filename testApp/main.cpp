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
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Group group {Faculty::ISIT,25,632};
    group.test();

    /*

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
    */
    /*
    std::list<AdministrativeUnit> units{group};
    Lab lab{units,15};
    Lecture lecture{units,15};
    Seminar seminar{units,15};



    Course myCourse{lab,lecture,seminar};
    myCourse.test();
    */


    Repositories testR;
    Professor testProf{100,200};
    testR.add(testProf);
    qDebug()<<"name:"<<testProf.getName();
    //testR.add(myCourse);

    //SubCourse mySubCourse(std::make_shared<Course>(myCourse),1,1,1);
    //mySubCourse.test();
    //Professor prof{500,600};
    //prof.addSubCourse(&myCourse,1,1,1);
    //prof.test();


    return a.exec();
}
