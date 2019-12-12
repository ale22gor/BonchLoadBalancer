#ifndef MODEL_H
#define MODEL_H

#include<QString>
#include<list>

#include "coursesnamesmodel.h"
#include "proffesorsnamesmodel.h"
#include "professordetail.h"
#include "Model_global.h"
#include "repositories.h"
#include "admunitsmodel.h"

class MODEL_EXPORT Model: public QObject
{
    Q_OBJECT

       Repositories m_repository;

       CoursesNamesModel *m_coursesNames;
       ProffesorsNamesModel *m_professorsNames;
       ProfessorDetail *m_professorDetail;
       AdmUnitsModel *m_admUnitModel;

       std::list<int> m_selecttedUnitsId;

   public:
       explicit Model(QObject *parent = nullptr);
       CoursesNamesModel * getCoursesNamesModel();
       ProffesorsNamesModel * getProffesorsNamesModel();
       ProfessorDetail * getProffesorsDetailModel();
       AdmUnitsModel * getAdmUnitsModel();

    public slots:
       void getProf(int id);
       void addProf(QString, int, int, int, QString);
       void addCourse(QString, int, int, int);


};

#endif // MODEL_H
