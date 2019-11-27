#ifndef REPOSITORIES_H
#define REPOSITORIES_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "Repositories_global.h"


#include "course.h"
#include "lab.h"
#include "lecture.h"
#include "seminar.h"
#include "lesson.h"
#include "administrativeunit.h"
#include "group.h"
#include "subgroup.h"
#include "supergroup.h"

class REPOSITORIES_EXPORT Repositories
{
    QSqlDatabase Database;

    //admUnit buffer search first
    //
    
public:

    Repositories();

    void add(Course &);
    void add(Course &, int);

    void add(Lecture&, int );
    void add(Seminar&, int );
    void add(Lab&, int);

    int add(Lesson&);
    int add(AdministrativeUnit&);

    void add(Group&, int);
    void add(SubGroup&, int);
    void add(SuperGroup&, int);

    std::list<Course> getCourse();
    Course getCourseByID(int );




};


#endif // REPOSITORIES_H
