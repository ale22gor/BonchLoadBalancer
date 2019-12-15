#include "professordetail.h"
#include<QtDebug>
#include "course.h"
#include "lab.h"
#include "seminar.h"
#include "lecture.h"



ProfessorDetail::ProfessorDetail( QObject *parent):
    QAbstractListModel{parent}
{

}

void ProfessorDetail::setProf(Professor proff)
{
    if(m_prof == nullptr)
        m_prof = std::unique_ptr<Professor>{new Professor(proff)};//cant call make unique !!!!!!WTF make_shared works
    else
        m_prof.reset(new Professor(proff));
}

QVariant ProfessorDetail::data(const QModelIndex &index, int role) const
{
    if(m_prof == nullptr)
        return QVariant();
    //qDebug() << m_coursesNames[static_cast<size_t>(index.row())];
    if (index.row() < 0 || index.row() >= static_cast<int>(m_prof->m_subCourses.size()))
        return QVariant();

    const Course subCourse{m_prof->m_subCourses[static_cast<size_t>(index.row())]};
    //subCourse.test();
    if(role == Lab)
    {
        if(subCourse.getLab() != nullptr){
            QVariantList list;
            for(auto admUnit:subCourse.getLab()->getAdmUnit()){
                admUnit.test();
                list.append(admUnit.getFaculty());
                list.append(admUnit.getNumber());
                list.append(admUnit.getamountOfPeople());
            }
            return list;
        }else
            return QVariant();
    }
    if(role == Seminar)
    {
        if(subCourse.getSeminar() != nullptr){

            QVariantList list;
            for(auto admUnit:subCourse.getSeminar()->getAdmUnit()){
                list.append(admUnit.getFaculty());
                list.append(admUnit.getNumber());
                list.append(admUnit.getamountOfPeople());
            }
            return list;
        }else
            return QVariant();
    }
    if(role == Lecture)
    {
        if(subCourse.getLecture() != nullptr){

            QVariantList list;
            for(auto admUnit:subCourse.getLecture()->getAdmUnit()){
                list.append(admUnit.getFaculty());
                list.append(admUnit.getNumber());
                list.append(admUnit.getamountOfPeople());
            }
            return list;
        }else
            return QVariant();

    }
    else if (role == NameRole)
        return QVariant{subCourse.getName()};
    else
        return QVariant();

}

int ProfessorDetail::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_prof->m_subCourses.size());
}

QHash<int, QByteArray> ProfessorDetail::roleNames() const
{

    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[Lab] = "Lab";
    roles[Lecture] = "Lecture";
    roles[Seminar] = "Seminar";

    return roles;
}
