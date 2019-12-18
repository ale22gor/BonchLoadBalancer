#include "model.h"
#include<QDebug>
#include <algorithm>
Model::Model(QObject *parent) : QObject{parent}

{
    try {
        m_coursesNames = new CoursesNamesModel{m_repository.getCoursesNames(),this};
        m_professorsNames = new ProffesorsNamesModel{m_repository.getProffessorsNames(),this};
        m_admUnitModel = new AdmUnitsModel{m_repository.getAdmUnits(),this};
    }catch (RepositoryException& myException) {
        qDebug() << myException.getTable();
        qDebug() << myException.getOperation();
        qDebug() << QString::fromStdString(myException.getInfo());
    }
    m_professorDetail = new ProfessorDetail{this};
    m_courseDetail = new CourseDetail{this};


}
CoursesNamesModel * Model::getCoursesNamesModel(){return m_coursesNames;}

ProffesorsNamesModel *Model::getProffesorsNamesModel(){return m_professorsNames;}

ProfessorDetail *Model::getProffesorsDetailModel()
{
    return  m_professorDetail;
}
CourseDetail *Model::getCourseDetail()
{
    return  m_courseDetail;
}

AdmUnitsModel *Model::getAdmUnitsModel()
{
    return  m_admUnitModel;
}

void Model::addProf(QString profName, int labAmount, int lectureAmount, int seminarAmount, QString courseName)
{
    qDebug()<<labAmount<<lectureAmount<<seminarAmount;
    //find way to return int -> remove friend from model classes names + remove find if
    auto it = std::find_if(m_coursesNames->m_coursesNames.begin(),m_coursesNames->m_coursesNames.end(),
                           [courseName](std::pair<int,QString> tmpPair){
            return tmpPair.second == courseName;
}
            );

    Professor tmpProf(100,200,profName);
    try {
        qDebug() <<"1";
        Course tmpCourse = m_repository.getCourseByID(it->first);
        qDebug() <<"2";

        tmpProf.addSubCourse(&tmpCourse,labAmount,lectureAmount,seminarAmount);
        qDebug() <<"3";
        //tmpCourse.test();
        m_repository.UpdateLessonsStatus(tmpCourse);
        qDebug() <<"4";

        m_repository.add(tmpProf);
    }catch (RepositoryException& myException) {
        qDebug() << myException.getTable();
        qDebug() << myException.getOperation();
        qDebug() << QString::fromStdString(myException.getInfo());
    }
}

void Model::addCourse(QString name, int labHour, int lectureHour, int seminarHour)
{
    std::list<AdministrativeUnit> labAdmUnits;
    std::list<AdministrativeUnit> lectureAmount;
    std::list<AdministrativeUnit> seminarAmount;

    for(auto admUnitsSelected:m_admUnitModel->m_admUnitsToSelect){
        if(admUnitsSelected.m_LabSelected)
            labAdmUnits.push_back(admUnitsSelected.m_admUnits);
        if(admUnitsSelected.m_lectureSelected)
            lectureAmount.push_back(admUnitsSelected.m_admUnits);
        if(admUnitsSelected.m_seminarSelected)
            seminarAmount.push_back(admUnitsSelected.m_admUnits);
    }

    Lab lab{labAdmUnits,labHour};
    Lecture lecture{lectureAmount,lectureHour};
    Seminar  seminar{seminarAmount,seminarHour};



    Course tmpCourse1{lab,lecture,seminar,name};
    try {
        m_repository.add(tmpCourse1);
    } catch (RepositoryException& myException) {
        qDebug() << myException.getTable();
        qDebug() << myException.getOperation();
        qDebug() << QString::fromStdString(myException.getInfo());
    }

}

void Model::resetSelectedAdmUnits()
{
    m_admUnitModel->resetData();
}

int Model::getFreeLessons()
{
    try {
        return m_repository.getFreeLessons();
    } catch (RepositoryException& myException) {
        qDebug() << myException.getTable();
        qDebug() << myException.getOperation();
        qDebug() << QString::fromStdString(myException.getInfo());
        return 0;
    }
}

void Model::getProf(int id)
{
    try {
        m_professorDetail->setProf(m_repository.getProfessorByID(id));

    } catch (RepositoryException& myException) {
        qDebug() << myException.getTable();
        qDebug() << myException.getOperation();
        qDebug() << QString::fromStdString(myException.getInfo());
    }
}

void Model::getCourse(int id)
{
    try {
        m_courseDetail->setCourse(m_repository.getCourseByID(id));

    } catch (RepositoryException& myException) {
        qDebug() << myException.getTable();
        qDebug() << myException.getOperation();
        qDebug() << QString::fromStdString(myException.getInfo());
    }
}
