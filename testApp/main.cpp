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

    Course tmpCourse1{testL,testLess,testLec};

    testR.add(tmpCourse1);

    Course tmpCourse{testR.getCourseByID(1)};//{testL,testLess,testLec};
    tmpCourse.test();

    Professor testProf{100,200};
    testProf.addSubCourse(&tmpCourse,1,1,1);
    testProf.test();
    testR.add(testProf);



    return a.exec();
}
