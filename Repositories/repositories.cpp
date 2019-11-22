#include "repositories.h"
#include <QSqlQuery>
#include <QSqlError>





Repositories::Repositories()
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
                   "admUnit_id INTEGER UNIQUE PRIMARY KEY ,"
                   "number INTEGER,"
                   "faculty VARCHAR(30))" );
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Administrative Unit created!";
{

    // Creating table Group
    query.prepare( "CREATE TABLE IF NOT EXISTS normalGroup ("
                   "normalGroup_id INTEGER UNIQUE PRIMARY KEY , "
                   "FOREIGN KEY(normalGroup_id) REFERENCES admUnit(admUnit_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE)" );
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Group created!";

    // Creating table SubGroup
    query.prepare( "CREATE TABLE IF NOT EXISTS subGroup ("
                   "subGroup_id INTEGER UNIQUE PRIMARY KEY , "
                   "FOREIGN KEY(subGroup_id) REFERENCES admUnit(admUnit_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE)" );
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 SubGroup created!";

    // Creating table SuperGroup
    query.prepare( "CREATE TABLE IF NOT EXISTS superGroup ("
                   "superGroup_id INTEGER UNIQUE PRIMARY KEY , "
                   "FOREIGN KEY(superGroup_id) REFERENCES admUnit(admUnit_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE)" );
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 SuperGroup created!";
}


    // Creating table Lesson
    query.prepare( "CREATE TABLE IF NOT EXISTS lesson ("
                   "lesson_id INTEGER UNIQUE PRIMARY KEY , "
                   "hours INTEGER)");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Lesson created!";

    //  table lessonid (admUInit + lesson ID) to subcourse
    //Creating table LessonToAdmUnit
    query.prepare("CREATE TABLE IF NOT EXISTS foobar("
                  "lesson_id INTEGER,"
                  "admUnit_id INTEGER,"
                  //"subcourse_id INTEGER" if not Null add to free
                  "FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id) ON DELETE CASCADE,"
                  "FOREIGN KEY(admUnit_id) REFERENCES admUnit(admUnit_id) ON DELETE CASCADE)");

    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 LessonToAdmUnit created!";

    // Creating table Lab
    query.prepare( "CREATE TABLE IF NOT EXISTS lab ("
                   "lab_id INTEGER UNIQUE PRIMARY KEY ,"
                   "free BOOLEAN DEFAULT(TRUE),"
                   "lesson_id INTEGER,"
                   "course_id INTEGER, FOREIGN KEY(course_id) REFERENCES course(course_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE,"
                   "FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE)");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Lab created!";

    // Creating table Seminar
    query.prepare( "CREATE TABLE IF NOT EXISTS seminar ("
                   "seminar_id INTEGER UNIQUE PRIMARY KEY , "
                   "free BOOLEAN DEFAULT(TRUE),"
                   "lesson_id INTEGER,"
                   "course_id INTEGER, FOREIGN KEY(course_id) REFERENCES course(course_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE,"
                   "FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE)");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Seminar created!";

    // Creating table Lecture
    query.prepare( "CREATE TABLE IF NOT EXISTS lecture ("
                   "lecture_id INTEGER UNIQUE PRIMARY KEY , "
                   "free BOOLEAN DEFAULT(TRUE),"
                   "lesson_id INTEGER,"
                   "course_id INTEGER, FOREIGN KEY(course_id) REFERENCES course(course_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE,"
                   "FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE)");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Lecture created!";

    // Creating table Course
    query.prepare( "CREATE TABLE IF NOT EXISTS course ("
                   "course_id INTEGER UNIQUE PRIMARY KEY , "
                   "course_name VARCHAR(30))");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Course created!";

}
/*
void Repositories::add(Course &entity )
{
    qDebug()<<entity.getName();

    QSqlQuery query(Database);
    query.prepare("INSERT INTO course (course_name) "
                  "VALUES (:course_name)");
    query.bindValue(":course_name", entity.getName().toStdString().c_str());

    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  course!";

    int lastIndex = query.lastInsertId().toInt();

    for(auto lecture: entity.m_lectures){
        add(*lecture,lastIndex);
    }
    for(auto lab: entity.m_labs){
        add(*lab,lastIndex);
    }
    for(auto seminar: entity.m_seminars){
        add(*seminar,lastIndex);
    }

}

void Repositories::add(Lab &entity, int fk)
{
    QSqlQuery query(Database);

    Lesson tmp = entity;
    int lessonFk = add(tmp);


    query.prepare("INSERT INTO lab (course_id, lesson_id) "
                  "VALUES (:course_id, :lesson_id)");
    query.bindValue(":course_id", fk);
    query.bindValue(":lesson_id", lessonFk);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  lab!";



}

int Repositories::add(Lesson &entity)
{
    QSqlQuery query(Database);

    int admUnitPk = add(*entity.m_administrativeUnit);

    query.prepare("INSERT INTO lesson (hours, admUnit_id) "
                  "VALUES (:hours, :admUnit_id)");
    query.bindValue(":hours", entity.getHours());
    query.bindValue(":admUnit_id", admUnitPk);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  lesson!";
    int lastIndex = query.lastInsertId().toInt();

    return lastIndex;

}

int Repositories::add(AdministrativeUnit &entity)
{
    QSqlQuery query(Database);

    //complete

    bool alreadyExist = false;

    query.prepare("SELECT * FROM admUnit WHERE faculty=:faculty AND number=:number");
    query.bindValue(":faculty", static_cast<int>(entity.m_faculty));
    query.bindValue(":number", entity.m_number);
    if(!query.exec()){
        qDebug() << query.lastError();
    }
    alreadyExist = query.next();

    if(alreadyExist){
        return query.value(0).toInt();
    }

    query.prepare("INSERT INTO admUnit (faculty,number) "
                  "VALUES (:faculty, :lesson_id)");
    query.bindValue(":faculty", static_cast<int>(entity.m_faculty));
    query.bindValue(":lesson_id", entity.m_number);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  admUnit!";

    int lastIndex = query.lastInsertId().toInt();

    return lastIndex;
}

std::list<Course> Repositories::getCourse()
{

}

void Repositories::add(Lecture &entity, int fk)
{
    QSqlQuery query(Database);

    Lesson tmp = entity;
    int lessonFk = add(tmp);


    query.prepare("INSERT INTO lecture (course_id, lesson_id) "
                  "VALUES (:course_id, :lesson_id)");
    query.bindValue(":course_id", fk);
    query.bindValue(":lesson_id", lessonFk);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  lecture!";

}

void Repositories::add(Seminar &entity, int fk)
{
    QSqlQuery query(Database);

    Lesson tmp = entity;
    int lessonFk = add(tmp);


    query.prepare("INSERT INTO seminar (course_id, lesson_id) "
                  "VALUES (:course_id, :lesson_id)");
    query.bindValue(":course_id", fk);
    query.bindValue(":lesson_id", lessonFk);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  seminar!";

}

*/
