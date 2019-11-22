#include "professor.h"
#include "course.h"
#include <QDebug>

Professor::Professor(int maxHours, int averageHours):
    m_averageHours{averageHours},
    m_maxHours{maxHours}
{}

void Professor::addSubCourse(Course *course,int seminarAmount,int labAmount,int lecturesamount)
{

    /*
    if(course->checkLabs(seminarAmount)&&
    course->checkLabs(labAmount)&&
    course->checkLabs(lecturesamount))
    {
        m_subCourses.push_back(SubCourse(course,seminarAmount,labAmount,lecturesamount));
    }
    */


}

void Professor::test()
{
    qDebug() << "average Hours"<<m_averageHours<<"max Hours"<<m_maxHours;
    for(auto subCourse:m_subCourses){
        subCourse.test();
    }


}
