#include "coursedetail.h"

#include "lab.h"
#include "seminar.h"
#include "lecture.h"

CourseDetail::CourseDetail(QObject *parent):
    QAbstractListModel{parent}
{

}

void CourseDetail::setCourse(Course course)
{
    if(m_course == nullptr)
        m_course = std::unique_ptr<Course>{new Course(course)};//cant call make unique !!!!!!WTF make_shared works
    else
        m_course.reset(new Course(course));

}

QVariant CourseDetail::data(const QModelIndex &index, int role) const
{
    if(m_course == nullptr)
        return QVariant();

    if(role == Lab)
    {
        if(m_course->getLab() != nullptr){
            QVariantList list;
            for(auto admUnit:m_course->getLab()->getAdmUnit()){
                //admUnit.test();
                list.append(QString{admUnit.getFaculty()}
                            +QString{" "}
                            +QString::number(admUnit.getNumber())
                            +QString{" "}
                            +QString::number(admUnit.getamountOfPeople()));
            }
            return list;
        }
        return   QVariantList();

    }

    if(role == Seminar)
    {
        if(m_course->getSeminar() != nullptr){
            QVariantList list;

            for(auto admUnit:m_course->getSeminar()->getAdmUnit()){
                list.append(QString{admUnit.getFaculty()}
                            +QString{" "}
                            +QString::number(admUnit.getNumber())
                            +QString{" "}
                            +QString::number(admUnit.getamountOfPeople()));
            }

            return list;
        }else
            return   QVariantList();

    }

    if(role == Lecture)
    {
        if(m_course->getLecture() != nullptr){

            QVariantList list;
            for(auto admUnit:m_course->getLecture()->getAdmUnit()){
                list.append(QString{admUnit.getFaculty()}
                            +QString{" "}
                            +QString::number(admUnit.getNumber())
                            +QString{" "}
                            +QString::number(admUnit.getamountOfPeople()));
            }
            return list;
        }
        return QVariant();

    }

    else if (role == NameRole)
        return QVariant{m_course->getName()};

    else
        return QVariant();

}

int CourseDetail::rowCount(const QModelIndex &parent) const
{
    return 1;
}
QHash<int, QByteArray> CourseDetail::roleNames() const
{

    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[Lab] = "Lab";
    roles[Lecture] = "Lecture";
    roles[Seminar] = "Seminar";

    return roles;
}
