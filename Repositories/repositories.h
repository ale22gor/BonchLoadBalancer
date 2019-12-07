#ifndef REPOSITORIES_H
#define REPOSITORIES_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <list>
#include <vector>
#include <utility>

#include "Repositories_global.h"


#include "course.h"
#include "lab.h"
#include "lecture.h"
#include "seminar.h"
#include "lesson.h"
#include "administrativeunit.h"
#include "professor.h"

class REPOSITORIES_EXPORT Repositories
{
    QSqlDatabase Database;

    //admUnit buffer search first
    //
    
public:

    Repositories();

    void add(Professor &);
    void add(Course &);
    void add(Course &, int);

    int add(Lecture&);
    int add(Seminar&);
    int add(Lab&);

    int add(Lesson&);
    int add(AdministrativeUnit&);

    void Update(Professor &);

    void Update(Course &);
    void UpdateLessonsStatus(Course &);


    int Update(Lecture&);
    int Update(Seminar&);
    int Update(Lab&);

    int Update(Lesson&);


    std::list<Course> getCourse();
    Course getCourseByID(int );
    Professor getProfessorByID(int );


    Lab getLabByID(int );
    Lecture getLectureByID(int );
    Seminar getSeminarByID(int );

    //Lesson getLessonByID(int );
    std::list<AdministrativeUnit> getAdmUnitsByID(int );
    std::vector<AdministrativeUnit> getAdmUnits();

    std::vector<Course> getProffesorCourseList(int );

    std::vector<std::pair<int,QString> > getProffessorsNames();
    std::vector<std::pair<int,QString> > getCoursesNames();





};


#endif // REPOSITORIES_H
