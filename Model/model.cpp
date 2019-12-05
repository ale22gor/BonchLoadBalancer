#include "model.h"

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

void Model::getProf(int id)
{
   m_professorDetail->setProf(m_repository.getProfessorByID(id));
}
