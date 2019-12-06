#include "model.h"
#include<QDebug>
#include <algorithm>
Model::Model(QObject *parent) : QObject{parent}

{
    m_coursesNames = new CoursesNamesModel{m_repository.getCoursesNames(),this};
    m_professorsNames = new ProffesorsNamesModel{m_repository.getProffessorsNames(),this};
    m_professorDetail = new ProfessorDetail{this};
}
CoursesNamesModel * Model::getCoursesNamesModel(){return m_coursesNames;}

ProffesorsNamesModel *Model::getProffesorsNamesModel(){return m_professorsNames;}

ProfessorDetail *Model::getProffesorsDetailModel()
{
    return  m_professorDetail;
}

void Model::addProf(QString profName, int labAmount, int lectureAmount, int seminarAmount, QString courseName)
{
    qDebug()<<profName;

    //find way to return int -> remove friend from model classes names + remove find if
    auto it = std::find_if(m_coursesNames->m_coursesNames.begin(),m_coursesNames->m_coursesNames.end(),
                 [courseName](std::pair<int,QString> tmpPair){
        return tmpPair.second == courseName;
    }
    );

    Professor tmpProf(100,200,profName);
    tmpProf.test();
    qDebug()<<it->first;

    Course tmpCourse = m_repository.getCourseByID(it->first);
    tmpProf.addSubCourse(&tmpCourse,labAmount,lectureAmount,seminarAmount);
    //m_repository.add(tmpProf);
}

void Model::getProf(int id)
{
    m_professorDetail->setProf(m_repository.getProfessorByID(id));
}
