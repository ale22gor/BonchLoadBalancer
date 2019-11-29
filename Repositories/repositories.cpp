#include "repositories.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


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
                   "admUnit_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,"
                   "amountOfPeople INTEGER,"
                   "number INTEGER,"
                   "faculty VARCHAR(30))" );
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Administrative Unit created!";



    // Creating table Lesson
    query.prepare( "CREATE TABLE IF NOT EXISTS lesson ("
                   "lesson_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                   "hours INTEGER)");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Lesson created!";

    //  table lessonid (admUInit + lesson ID) to subcourse
    //Creating table LessonToAdmUnit
    query.prepare("CREATE TABLE IF NOT EXISTS lessonToAdmUnit("
                  "lesson_id INTEGER,"
                  "admUnit_id INTEGER,"
                  "free BOOLEAN,"
                  "FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id) ON DELETE CASCADE,"
                  "FOREIGN KEY(admUnit_id) REFERENCES admUnit(admUnit_id) ON DELETE CASCADE)");

    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 LessonToAdmUnit created!";

    // Creating table Lab
    query.prepare( "CREATE TABLE IF NOT EXISTS lab ("
                   "lab_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,"
                   "lesson_id INTEGER,"
                   "FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE)");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Lab created!";

    // Creating table Seminar
    query.prepare( "CREATE TABLE IF NOT EXISTS seminar ("
                   "seminar_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                   "lesson_id INTEGER,"
                   "FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE)");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Seminar created!";

    // Creating table Lecture
    query.prepare( "CREATE TABLE IF NOT EXISTS lecture ("
                   "lecture_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                   "lesson_id INTEGER,"
                   "FOREIGN KEY(lesson_id) REFERENCES lesson(lesson_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE)");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Lecture created!";

    // Creating table Proffessor
    query.prepare( "CREATE TABLE IF NOT EXISTS proffesor ("
                   "proffesor_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                   "proffesor_name VARCHAR(30))");
    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "Table1 Proffesor created!";

    // Creating table Course
    query.prepare( "CREATE TABLE IF NOT EXISTS course ("
                   "course_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                   "course_name VARCHAR(30),"
                   "lab_id INTEGER,"
                   "seminar_id INTEGER,"
                   "lecture_id INTEGER,"
                   "proffesor_id INTEGER DEFAULT NULL, FOREIGN KEY(proffesor_id) REFERENCES proffesor(proffesor_id)"
                   "ON DELETE CASCADE ON UPDATE CASCADE,"
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

void Repositories::add(Professor &entity)
{
    qDebug()<<entity.getName();

    QSqlQuery query(Database);
    query.prepare("INSERT INTO proffesor (proffesor_name) "
                  "VALUES (:proffesor_name)");
    query.bindValue(":proffesor_name", entity.getName().toStdString().c_str());

    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  prof!";

    int lastIndex = query.lastInsertId().toInt();
    for(auto &course:entity.m_subCourses)
        add(course,lastIndex);


}

void Repositories::add(Course &entity )
{
    qDebug()<<entity.getName();

    int labFK{-1};
    int lectureFK{-1};
    int seminarFK{-1};

    if(entity.m_lab != nullptr)
        labFK = add(*(entity.m_lab));
    if(entity.m_lecture != nullptr)
        lectureFK = add(*(entity.m_lecture));
    if(entity.m_seminar != nullptr)
        seminarFK = add(*(entity.m_seminar));

    QSqlQuery query(Database);
    query.prepare("INSERT INTO course (course_name, lab_id, seminar_id, lecture_id) "
                  "VALUES (:course_name, :lab_id, :seminar_id, :lecture_id)");
    query.bindValue(":course_name", entity.getName().toStdString().c_str());
    query.bindValue(":lab_id", labFK);
    query.bindValue(":seminar_id", seminarFK);
    query.bindValue(":lecture_id", lectureFK);

    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  course!";




}

void Repositories::add(Course &entity, int profPk)
{
    qDebug()<<entity.getName();

    int labFK = add(*(entity.m_lab));
    int lectureFK = add(*(entity.m_lecture));
    int seminarFK = add(*(entity.m_seminar));

    QSqlQuery query(Database);
    query.prepare("INSERT INTO course (course_name, lab_id, seminar_id, lecture_id, proffesor_id) "
                  "VALUES (:course_name, :lab_id, :seminar_id, :lecture_id, :proffesor_id)");
    query.bindValue(":course_name", entity.getName().toStdString().c_str());
    query.bindValue(":lab_id", labFK);
    query.bindValue(":seminar_id", seminarFK);
    query.bindValue(":lecture_id", lectureFK);
    query.bindValue(":proffesor_id", profPk);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  course!";
}

int Repositories::add(Lab &entity)
{
    QSqlQuery query(Database);

    Lesson tmp = entity;
    int lessonFk = add(tmp);


    query.prepare("INSERT INTO lab (lesson_id) "
                  "VALUES (:lesson_id)");
    query.bindValue(":lesson_id", lessonFk);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  lab!";

    int lastIndex = query.lastInsertId().toInt();

    return lastIndex;

}

int Repositories::add(Lesson &entity)
{
    QSqlQuery query(Database);
    //int admUnitPk = entity.m_administrativeUnit;

    query.prepare("INSERT INTO lesson (hours) "
                  "VALUES (:hours)");
    query.bindValue(":hours", entity.getHours());


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  lesson!";
    int lastIndex = query.lastInsertId().toInt();

    for(auto &admUnit:entity.m_administrativeUnit){
        //refactoring maybe (nultiple prepare statemnet
        query.prepare("INSERT INTO lessonToAdmUnit (lesson_id, admUnit_id, free) "
                      "VALUES (:lesson_id, :admUnit_id, :free)");
        query.bindValue(":lesson_id", lastIndex);
        query.bindValue(":admUnit_id", admUnit.getId());
        query.bindValue(":free", admUnit.isFree());

        if( !query.exec() )
            qDebug() << query.lastError();
        else
            qDebug() << "inserted  admToLesson!";

    }

    return lastIndex;

}

std::list<Course> Repositories::getCourse()
{

}

Course Repositories::getCourseByID(int courseID)
{
    QSqlQuery query(Database);

    query.prepare("SELECT * FROM course WHERE course_id=:course_id");
    query.bindValue(":course_id", courseID);
    if(!query.exec()){
        qDebug() << query.lastError();
    }
    else
        qDebug() << "course selected";
    if (query.next()) {
        int labId = query.value(2).toInt();
        int lectureId = query.value(3).toInt();
        int seminarId = query.value(4).toInt();

        return Course{getLabByID(labId),getLectureByID(lectureId),getSeminarByID(seminarId)};
    }
}

Lab Repositories::getLabByID(int labPk)
{

    QSqlQuery query(Database);

    query.prepare("SELECT * FROM lab WHERE lab_id=:lab_id");
    query.bindValue(":lab_id", labPk);
    if(!query.exec()){
        qDebug() << query.lastError();
        //return invalid value or exception
    }
    else
        qDebug() << "lab selected";

    if (query.next()) {
        int lessonId = query.value(1).toInt();

        QSqlQuery lessonQuery(Database);
        lessonQuery.prepare("SELECT * FROM lesson WHERE lesson_id=:lesson_id");
        lessonQuery.bindValue(":lesson_id", lessonId);

        if(!lessonQuery.exec()){
            qDebug() << lessonQuery.lastError();
            //return invalid value or exception
        }else
            qDebug() << "lesson selected";

        if (lessonQuery.next()){
            return  Lab{getAdmUnitsByID(lessonId),
                        lessonQuery.value(1).toInt()};
        }
    }

}

Lecture Repositories::getLectureByID(int lecturePk)
{
    QSqlQuery query(Database);

    query.prepare("SELECT * FROM lecture WHERE lecture_id=:lecture_id");
    query.bindValue(":lecture_id", lecturePk);
    if(!query.exec()){
        qDebug() << query.lastError();
        //return invalid value or exception
    }else
        qDebug() << "lecture selected";

    if (query.next()) {
        int lessonId = query.value(1).toInt();

        QSqlQuery lessonQuery(Database);
        lessonQuery.prepare("SELECT * FROM lesson WHERE lesson_id=:lesson_id");
        lessonQuery.bindValue(":lesson_id", lessonId);

        if(!lessonQuery.exec()){
            qDebug() << lessonQuery.lastError();
            //return invalid value or exception
        }else
            qDebug() << "lesson selected";

        if (lessonQuery.next()){
            return  Lecture{getAdmUnitsByID(lessonId),
                        lessonQuery.value(1).toInt()};
        }
    }

}

Seminar Repositories::getSeminarByID(int seminarPK)
{
    QSqlQuery query(Database);

    query.prepare("SELECT * FROM seminar WHERE seminar_id=:seminar_id");
    query.bindValue(":seminar_id", seminarPK);
    if(!query.exec()){
        qDebug() << query.lastError();
        //return invalid value or exception
    }else
        qDebug() << "seminar selected";

    if (query.next()) {
        int lessonId = query.value(1).toInt();

        QSqlQuery lessonQuery(Database);
        lessonQuery.prepare("SELECT * FROM lesson WHERE lesson_id=:lesson_id");
        lessonQuery.bindValue(":lesson_id", lessonId);

        if(!lessonQuery.exec()){
            qDebug() << lessonQuery.lastError();
            //return invalid value or exception
        }else
            qDebug() << "lesson selected";

        if (lessonQuery.next()){
            return Seminar{getAdmUnitsByID(lessonId),
                        lessonQuery.value(1).toInt()};
        }
    }

}



std::list<AdministrativeUnit> Repositories::getAdmUnitsByID(int lessonPK)
{
    QSqlQuery query(Database);

    query.prepare(R"#(SELECT a.admUnit_id, a.amountOfPeople, a.number, a.faculty, al.free
                    FROM admUnit as a
                    INNER JOIN lessonToAdmUnit as al
                         ON a.admUnit_id = al.admUnit_id
                  INNER JOIN  lesson as l
                         ON l.lesson_id = al.lesson_id
                  WHERE l.lesson_id=:lesson_id)#");
    query.bindValue(":lesson_id", lessonPK);
    if(!query.exec()){
        qDebug() << query.lastError();
        //return invalid value or exception
    }else
        qDebug() << "admunit selected";

    std::list<AdministrativeUnit> tmpList;

    while (query.next()) {
        int id = query.value(0).toInt();
        int amountOfPeople = query.value(1).toInt();

        int number = query.value(2).toInt();
        QString strFaculty = query.value(3).toString();
        bool free = query.value(4).toBool();
        Faculty faculty;
        if(strFaculty.compare("ISIT"))
            faculty = Faculty::ISIT;
        else if(strFaculty.compare("RTS"))
            faculty = Faculty::RTS;
        else if(strFaculty.compare("IKSS"))
            faculty = Faculty::IKSS;
        else
            //default value
            faculty = Faculty::ISIT;

        tmpList.push_back(AdministrativeUnit{faculty,amountOfPeople,number,id,free});
    }
    return tmpList;

}

int Repositories::add(Lecture &entity)
{
    QSqlQuery query(Database);

    Lesson tmp = entity;
    int lessonFk = add(tmp);


    query.prepare("INSERT INTO lecture (lesson_id) "
                  "VALUES (:lesson_id)");
    query.bindValue(":lesson_id", lessonFk);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  lecture!";
    int lastIndex = query.lastInsertId().toInt();

    return lastIndex;

}

int Repositories::add(Seminar &entity)
{
    QSqlQuery query(Database);

    Lesson tmp = entity;
    int lessonFk = add(tmp);


    query.prepare("INSERT INTO seminar (lesson_id) "
                  "VALUES (:lesson_id)");
    query.bindValue(":lesson_id", lessonFk);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "inserted  seminar!";

    int lastIndex = query.lastInsertId().toInt();

    return lastIndex;

}


