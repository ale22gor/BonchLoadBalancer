#ifndef REPOSITORIES_H
#define REPOSITORIES_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "Repositories_global.h"
#include "course.h"

template <class T>
class REPOSITORIES_EXPORT Repositories
{
    QSqlDatabase Database;
    
public:

    Repositories()
    {
        Database = QSqlDatabase::addDatabase("QSQLITE");
        Database.setDatabaseName("/home/dmitry/WorkSpace/BonchLoadBalance/myDb.db");
        if (!Database.open())
        {
            qDebug() << Database.lastError().text();
        }else{
            QSqlQuery query(Database);
            query.exec("PRAGMA foreign_keys = ON;");
            qDebug() << "Database connected" ;
        }

        QSqlQuery query;


        // Creating table Administrative Unit
        query.prepare( "CREATE TABLE IF NOT EXISTS admUnit ("
                       "admUnit_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                       "course_name VARCHAR(30))" );
        if( !query.exec() )
            qDebug() << query.lastError();
        else
            qDebug() << "Table1 Administrative Unit created!";

        // Creating table Lesson
        query.prepare( "CREATE TABLE IF NOT EXISTS lesson ("
                       "lesson_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                       "hours INTEGER, "
                       "admUnit_id INTEGER, FOREIGN KEY(admUnit_id) REFERENCES admUnit(admUnit_id)"
                       "ON DELETE CASCADE ON UPDATE CASCADE)" );
        if( !query.exec() )
            qDebug() << query.lastError();
        else
            qDebug() << "Table1 Lesson created!";


        // Creating table Lab
        query.prepare( "CREATE TABLE IF NOT EXISTS lab ("
                       "lab_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                       "lesson_id INTEGER, FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id)"
                       "ON DELETE CASCADE ON UPDATE CASCADE)" );
        if( !query.exec() )
            qDebug() << query.lastError();
        else
            qDebug() << "Table1 Lab created!";

        // Creating table seminar
        query.prepare( "CREATE TABLE IF NOT EXISTS seminar ("
                       "seminar_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                       "lesson_id INTEGER, FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id)"
                       "ON DELETE CASCADE ON UPDATE CASCADE)" );
        if( !query.exec() )
            qDebug() << query.lastError();
        else
            qDebug() << "Table1 seminar created!";

        // Creating table Lecture
        query.prepare( "CREATE TABLE IF NOT EXISTS lecture ("
                       "lecture_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                       "lesson_id INTEGER, FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id)"
                       "ON DELETE CASCADE ON UPDATE CASCADE)" );
        if( !query.exec() )
            qDebug() << query.lastError();
        else
            qDebug() << "Table1 lecture created!";

        // Creating table Course
        query.prepare( "CREATE TABLE IF NOT EXISTS course ("
                       "course_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                       "course_name VARCHAR(30),"
                       "lab_id INTEGER,"
                       "seminar_id INTEGER,"
                       "lecture_id INTEGER,"
                       "FOREIGN KEY(lab_id) REFERENCES lab(lab_id)"
                       "ON DELETE CASCADE ON UPDATE CASCADE,"
                       "FOREIGN KEY(seminar_id) REFERENCES seminar(seminar_id)"
                       "ON DELETE CASCADE ON UPDATE CASCADE,"
                       "FOREIGN KEY(lecture_id) REFERENCES lecture(lecture_id)"
                       "ON DELETE CASCADE ON UPDATE CASCADE)");
        if( !query.exec() )
            qDebug() << query.lastError();
        else
            qDebug() << "Table1 Course created!";


    }
    void add(T entity);
    void remove(T entity);
    void update(T entity);

    void getByID(int id);
    //std::List< > query(specification) = 0;

};
/*
template<>
class REPOSITORIES_EXPORT Repositories<int>
{
    Repositories();
    void add(int entity);
    void remove(int entity);
    void update(int entity);

    //void getByID(int id);
    //std::List< > query(specification) = 0;
};
*/

#endif // REPOSITORIES_H
