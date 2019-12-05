#include "professor.h"
#include "course.h"
#include <QDebug>

Professor::Professor(int maxHours, int averageHours, QString name, int id):
    m_averageHours{averageHours},
    m_maxHours{maxHours},
    m_name{name},
    m_id{id}
{}

Professor::Professor(std::vector<Course> subCourses, int maxHours, int averageHours, QString name, int id):
    m_subCourses{subCourses},
    m_averageHours{averageHours},
    m_maxHours{maxHours},
    m_name{name},
    m_id{id}
{

}

void Professor::addSubCourse(Course *course,int seminarAmount,int labAmount,int lecturesamount)
{
    m_subCourses.push_back(Course{course, seminarAmount, labAmount, lecturesamount});
}

void Professor::test()
{
    qDebug() << "average Hours"<<m_averageHours<<"max Hours"<<m_maxHours;
    for(auto& subCourse:m_subCourses){
        subCourse.test();
    }


}

QString Professor::getName()
{
    return  m_name;
}
