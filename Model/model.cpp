#include "model.h"
#include<QDebug>
#include <algorithm>
Model::Model(QObject *parent) : QObject{parent}

{
    try {
        m_coursesNames = new CoursesNamesModel{m_repository.getCoursesNames(),this};
        m_professorsNames = new ProffesorsNamesModel{m_repository.getProffessorsNames(),this};
        m_admUnitModel = new AdmUnitsModel{m_repository.getAdmUnits(),this};
        m_courseLessonsAMount.resize(m_coursesNames->m_coursesNames.size());
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

void Model::addProf(QString profName)
{
    Professor tmpProf(100,200,profName);
    try {
        for(auto& courseLessonsAmount:m_courseLessonsAMount){
            if(courseLessonsAmount.m_labAmount == 0 &&
                    courseLessonsAmount.m_lectureAmount == 0 &&
                    courseLessonsAmount.m_seminarAmount == 0)
                continue;
            Course tmpCourse = m_repository.getCourseByID(courseLessonsAmount.m_id);
            tmpProf.addSubCourse(&tmpCourse,courseLessonsAmount.m_labAmount,courseLessonsAmount.m_lectureAmount,courseLessonsAmount.m_seminarAmount);
            tmpProf.test();
            m_repository.UpdateLessonsStatus(tmpCourse);
        }

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

void Model::setCourseLessonsAmount(int currentIndex,int id, int labHour, int lectureHour, int seminarHour)
{
    qDebug() << labHour<<lectureHour<<seminarHour<<id<<currentIndex;

    m_courseLessonsAMount[currentIndex] = CourseLessonsAmount{labHour,lectureHour,seminarHour,id};
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

int Model::getCoursecCount()
{
    return m_coursesNames->rowCount();
}

int Model::getProffSCount()
{
    return m_professorsNames->rowCount();

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
