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

void Professor::addSubCourse(Course *course,int labAmount,int lecturesamount,int seminarAmount)
{
    m_subCourses.push_back(Course{course, labAmount, lecturesamount, seminarAmount});
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

bool operator==(const Professor &p1, const Professor &p2)
{
    if(p1.m_name != p2.m_name ||
            p1.m_maxHours != p2.m_maxHours ||
            p1.m_averageHours != p2.m_averageHours)
        return false;

    if(p1.m_subCourses.size() != p2.m_subCourses.size())
        return false;

    for(int i{0};i<p1.m_subCourses.size();++i){
        if(!(p1.m_subCourses[i] == p2.m_subCourses[i]))
            return false;
    }

    return true;
}

bool operator==(const Professor &p, const Course &c)
{
    if(p.m_subCourses.size() > 0)
        return (p.m_subCourses[0] == c);
    return false;
}
