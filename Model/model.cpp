#include "model.h"
#include<QDebug>
#include <algorithm>
Model::Model(QObject *parent) : QObject{parent}

{
    m_coursesNames = new CoursesNamesModel{m_repository.getCoursesNames(),this};
    m_professorsNames = new ProffesorsNamesModel{m_repository.getProffessorsNames(),this};
    m_professorDetail = new ProfessorDetail{this};
    m_admUnitModel = new AdmUnitsModel{m_repository.getAdmUnits(),this};
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
    qDebug()<<profName;

    //find way to return int -> remove friend from model classes names + remove find if
    auto it = std::find_if(m_coursesNames->m_coursesNames.begin(),m_coursesNames->m_coursesNames.end(),
                 [courseName](std::pair<int,QString> tmpPair){
        return tmpPair.second == courseName;
    }
    );

    Professor tmpProf(100,200,profName);
    tmpProf.test();

    Course tmpCourse = m_repository.getCourseByID(it->first);
    //tmpCourse.test();

    tmpProf.addSubCourse(&tmpCourse,labAmount,lectureAmount,seminarAmount);
    m_repository.UpdateLessonsStatus(tmpCourse);
    m_repository.add(tmpProf);
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

    m_repository.add(tmpCourse1);

}

void Model::resetSelectedAdmUnits()
{
    m_admUnitModel->resetData();
}

void Model::getProf(int id)
{
    m_professorDetail->setProf(m_repository.getProfessorByID(id));
}

void Model::getCourse(int id)
{
    m_courseDetail->setCourse(m_repository.getCourseByID(id));
}
