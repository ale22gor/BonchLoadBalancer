#include <QCoreApplication>
#include <list>

#include "course.h"
#include "lab.h"
#include "lecture.h"
#include "seminar.h"
#include "administrativeunit.h"
#include "Constants.h"
#include "professor.h"

#include "repositories.h"

#include <memory>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AdministrativeUnit group {Faculty::ISIT,25,632,1};
    group.test();
    std::list<AdministrativeUnit> testList{group};


    Repositories testR;

    Lab testL{testList,14};
    Lecture testLess{testList,14};
    Seminar  testLec{testList,14};


    Course tmpCourse1{testL,testLess,testLec,"mycourseS"};
    qDebug() << "course to save";
    tmpCourse1.test();
    qDebug() << "course to save";

    testR.add(tmpCourse1);

      /*
    Course tmpCourse{testR.getCourseByID(1)};//{testL,testLess,testLec};

    qDebug() << "course to load";
    tmpCourse.test();
    qDebug() << "course to load";


    Professor testProf{100,200,"antipin"};//{testR.getProfessorByID(1)};
    //error if 0 below
    testProf.addSubCourse(&tmpCourse,1,1,1);

    qDebug() << "proff to save";
    testProf.test();
    qDebug() << "proff to save";
    testR.UpdateLessonsStatus(tmpCourse);
    testR.add(testProf);

    Professor testProf1{testR.getProfessorByID(1)};//{testR.getProfessorByID(1)};
    qDebug() << "proff to load";
    testProf1.test();
    qDebug() << "proff to load";

    */

    //std::vector<QString> m_coursesNames{testR.getCoursesNames()};

    //for(auto &proffesorName:m_coursesNames){
    //    qDebug()<<proffesorName;
    //}

    return a.exec();
}
