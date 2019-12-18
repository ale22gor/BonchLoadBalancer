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
#include "coursedetail.h"

#include"repositoryexception.h"


class MODEL_EXPORT Model: public QObject
{
    Q_OBJECT

       Repositories m_repository;

       CoursesNamesModel *m_coursesNames;
       ProffesorsNamesModel *m_professorsNames;
       ProfessorDetail *m_professorDetail;
       AdmUnitsModel *m_admUnitModel;
       CourseDetail *m_courseDetail;

       std::list<int> m_selecttedUnitsId;

   public:
       explicit Model(QObject *parent = nullptr);
       CoursesNamesModel * getCoursesNamesModel();
       ProffesorsNamesModel * getProffesorsNamesModel();
       ProfessorDetail * getProffesorsDetailModel();
       AdmUnitsModel * getAdmUnitsModel();
       CourseDetail *getCourseDetail();

    public slots:
       void getProf(int id);
       void getCourse(int id);

       void addProf(QString, int, int, int, QString);
       void addCourse(QString, int, int, int);
       void resetSelectedAdmUnits();

       int getFreeLessons();
};

#endif // MODEL_H
