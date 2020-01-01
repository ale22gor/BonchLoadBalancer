#define BOOST_TEST_MODULE logick
#include <boost/test/included/unit_test.hpp>

#include<list>

#include "course.h"
#include "lab.h"
#include "lecture.h"
#include "seminar.h"
#include "administrativeunit.h"
#include "Constants.h"
#include "professor.h"

#include "repositories.h"

BOOST_AUTO_TEST_SUITE (logick)
BOOST_AUTO_TEST_CASE( coursePartial )
{
    AdministrativeUnit group {Faculty::ISIT,25,632,1};

    std::list<AdministrativeUnit> testList{group};

    Lab testLab{testList,14};
    Lecture testLecture{testList,14};
    Seminar testSeminar{testList,14};

    Course testCourse{testLab,testLecture,testSeminar};


    BOOST_REQUIRE(testLab == *testCourse.getLab());

    BOOST_REQUIRE(testLecture == *testCourse.getLecture());

    BOOST_REQUIRE(testSeminar == *testCourse.getSeminar());


    Course testSubCourse1{&testCourse,1,0,1};

    BOOST_REQUIRE(*testCourse.getLab() == *testSubCourse1.getLab());

    BOOST_REQUIRE(*testCourse.getSeminar() == *testSubCourse1.getSeminar());

    Course testSubCourse2{&testCourse,0,1,0};

    BOOST_REQUIRE(*testCourse.getLecture() == *testSubCourse2.getLecture());


}

BOOST_AUTO_TEST_CASE( courseFull )
{
    AdministrativeUnit group {Faculty::ISIT,25,632,1};

    std::list<AdministrativeUnit> testList{group};

    Lab testLab{testList,14};
    Lecture testLecture{testList,14};
    Seminar testSeminar{testList,14};

    Course testCourse{testLab,testLecture,testSeminar};

    Course testSubCourse{&testCourse,1,1,1};

    BOOST_REQUIRE(testCourse == testSubCourse);


}

BOOST_AUTO_TEST_CASE( proffesor )
{
    AdministrativeUnit group {Faculty::ISIT,25,632,1};

    std::list<AdministrativeUnit> testList{group};

    Lab testLab{testList,14};
    Lecture testLecture{testList,14};
    Seminar testSeminar{testList,14};

    Course testCourse{testLab,testLecture,testSeminar};

    Professor testProf{100,200,"antipin"};

    testProf.addSubCourse(&testCourse,1,1,1);

    BOOST_REQUIRE(testProf == testCourse);
}

BOOST_AUTO_TEST_SUITE_END( )

BOOST_AUTO_TEST_SUITE (database)

BOOST_AUTO_TEST_CASE( saveLoadCourse )
{
    AdministrativeUnit group {Faculty::ISIT,25,632,1};

    std::list<AdministrativeUnit> testList{group};

    Lab testLab{testList,14};
    Lecture testLecture{testList,14};
    Seminar testSeminar{testList,14};

    Course testCourse{testLab,testLecture,testSeminar};

    Repositories testR{"testDb.db"};
    //testR.add(testCourse);

    Course testCourse1{testR.getCourseByID(1)};

    BOOST_REQUIRE(testCourse == testCourse1);

}

BOOST_AUTO_TEST_CASE( saveProff )
{
    AdministrativeUnit group {Faculty::ISIT,25,632,1};

    std::list<AdministrativeUnit> testList{group};

    Lab testLab{testList,14};
    Lecture testLecture{testList,14};
    Seminar testSeminar{testList,14};

    Course testCourse{testLab,testLecture,testSeminar};

    Repositories testR{"testDb.db"};
    //testR.add(testCourse);

    Course testCourse1{testR.getCourseByID(1)};

    Professor testProf{100,200,"antipin"};//{testR.getProfessorByID(1)};
    //error if 0 below
    testProf.addSubCourse(&testCourse1,1,1,1);

    //testR.add(testProf);

    Professor testProf1{testR.getProfessorByID(1)};//{testR.getProfessorByID(1)};
    testProf.test();
    testProf1.test();

    BOOST_REQUIRE(testProf == testProf1);

}

BOOST_AUTO_TEST_SUITE_END( )

