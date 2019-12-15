#include "repositories.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>


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
    if(entity.m_lab == nullptr && entity.m_seminar == nullptr && entity.m_lecture == nullptr
            && entity.getName() == "")
        //throw exeption notify user
        return;

    int labFK{-1};
    QString labId;
    QString labId2;
    int lectureFK{-1};
    QString lectureId;
    QString lectureId2;
    int seminarFK{-1};
    QString seminarId;
    QString seminarId2;


    if(entity.m_lab != nullptr){
        labFK = add(*(entity.m_lab));
        if(entity.m_seminar == nullptr && entity.m_lecture == nullptr)
            labId = "lab_id";
        else
            labId = "lab_id, ";
        labId2 = ":"+labId;
    }
    if(entity.m_seminar != nullptr){
        seminarFK = add(*(entity.m_seminar));
        if(entity.m_lecture == nullptr)
            seminarId = "seminar_id";
        else
            seminarId = "seminar_id, ";
        seminarId2 = ":"+seminarId;
    }
    if(entity.m_lecture != nullptr){
        lectureFK = add(*(entity.m_lecture));
        lectureId = "lecture_id ";
        lectureId2 = ":"+lectureId;
        qDebug()<<lectureId2;
    }


    QSqlQuery query(Database);
    query.prepare("INSERT INTO course (course_name, " + labId + seminarId + lectureId + ")VALUES (:course_name," + labId2 + seminarId2 + lectureId2 + ")");
    query.bindValue(":course_name", entity.getName().toStdString().c_str());
    QString loh{"INSERT INTO course (course_name, " + labId + seminarId + lectureId + ")VALUES (:course_name," + labId2 + seminarId2 + lectureId2 + ")"};
    qDebug() << loh;
    if(entity.m_lab != nullptr)
        query.bindValue(":lab_id", labFK);
    if(entity.m_seminar != nullptr)
        query.bindValue(":seminar_id", seminarFK);
    if(entity.m_lecture != nullptr)
        query.bindValue(":lecture_id", lectureFK);


    if( !query.exec() )
        qDebug() << query.lastError() <<" course";
    else
        qDebug() << "inserted  course!";


}

void Repositories::add(Course &entity, int profPk)
{
    qDebug()<<entity.getName();

    int labFK{-1};
    QString labId;
    QString labId2;
    int lectureFK{-1};
    QString lectureId;
    QString lectureId2;
    int seminarFK{-1};
    QString seminarId;
    QString seminarId2;

    QString profId;
    QString profId2;

    if(entity.m_lab != nullptr || entity.m_seminar != nullptr || entity.m_lecture != nullptr)
        profId = "proffesor_id,";
    else
        profId = "proffesor_id";

    profId2 =":"+profId;

    if(entity.m_lab != nullptr){
        labFK = add(*(entity.m_lab));
        if(entity.m_seminar == nullptr && entity.m_lecture == nullptr)
            labId = "lab_id";
        else
            labId = "lab_id, ";
        labId2 = ":"+labId;
    }
    if(entity.m_seminar != nullptr){
        seminarFK = add(*(entity.m_seminar));
        if(entity.m_lecture == nullptr)
            seminarId = "seminar_id";
        else
            seminarId = "seminar_id, ";
        seminarId2 = ":"+seminarId;
    }
    if(entity.m_lecture != nullptr){
        lectureFK = add(*(entity.m_lecture));
        lectureId = "lecture_id ";
        lectureId2 = ":"+lectureId;
    }

    QSqlQuery query(Database);
    query.prepare("INSERT INTO course (course_name, proffesor_id, " + labId + seminarId + lectureId + ")"
                  "VALUES (:course_name, :proffesor_id, " + labId2 + seminarId2 + lectureId2 + ")");
    query.bindValue(":course_name", entity.getName().toStdString().c_str());
    if(entity.m_lab != nullptr)
        query.bindValue(":lab_id", labFK);
    if(entity.m_seminar != nullptr)
        query.bindValue(":seminar_id", seminarFK);
    if(entity.m_lecture != nullptr)
        query.bindValue(":lecture_id", lectureFK);
    query.bindValue(":proffesor_id", profPk);

    if( !query.exec() )
        qDebug() << query.lastError() <<" course";
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
        qDebug() << query.lastError() <<" lab";
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
        qDebug() << query.lastError() << " lesson";
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

void Repositories::UpdateLessonsStatus(Course &course)
{
    QString lessonIdInterval;
    lessonIdInterval += QString::number(course.m_lab->getID());
    lessonIdInterval += ',';
    lessonIdInterval += QString::number(course.m_lecture->getID());
    lessonIdInterval += ',';
    lessonIdInterval += QString::number(course.m_seminar->getID());

    QString admUnitIdInterval;

    for(auto &id:course.m_lab->m_idToUpdate){
        admUnitIdInterval += QString::number(id);
        admUnitIdInterval += ',';
    }
    for(auto &id:course.m_lecture->m_idToUpdate){
        admUnitIdInterval += QString::number(id);
        admUnitIdInterval += ',';
    }
    for(auto &id:course.m_seminar->m_idToUpdate){
        admUnitIdInterval += QString::number(id);
    }
    qDebug()<<lessonIdInterval<<admUnitIdInterval<<"!!!!!!!!!!!!!!!!!!!!!";
    QSqlQuery query(Database);
    query.prepare("UPDATE lessonToAdmUnit "
                  "SET free=0 "
                  "WHERE lesson_id IN ("+lessonIdInterval+") AND admUnit_id IN("+admUnitIdInterval+") ");
    //query.bindValue(":free", lesson.);


    if( !query.exec() )
        qDebug() << query.lastError();
    else
        qDebug() << "updated something!";
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
        int id {query.value(0).toInt()};
        QString courseName {query.value(1).toString()};
        int labId {query.value(2).toInt()};
        int seminarId {query.value(3).toInt()};
        int lectureId  {query.value(4).toInt()};
        qDebug() << labId;
        qDebug() << lectureId;
        qDebug() << seminarId;

        if(labId == 0 && lectureId == 0 && seminarId == 0){
            exit(1);//throw exeption
        }

        if(labId == 0){
            if(lectureId == 0)
                return Course{getSeminarByID(seminarId),courseName,id};

            else if(seminarId == 0)
                return Course{getLectureByID(lectureId),courseName,id};

            else
                return Course{getLectureByID(lectureId),getSeminarByID(seminarId),courseName,id};
        }
        else if(lectureId == 0){

            if(seminarId == 0)
                return Course{getLabByID(labId),courseName,id};

            else
                return Course{getLabByID(labId),getSeminarByID(seminarId),courseName,id};
        }
        else if(seminarId == 0){
            return Course{getLabByID(labId),getLectureByID(lectureId),courseName,id};

        }
        else
            return Course{getLabByID(labId),getLectureByID(lectureId),getSeminarByID(seminarId),courseName,id};

    }
    qDebug() << "course not selected";

}

Professor Repositories::getProfessorByID(int proffesorId)
{
    QSqlQuery query(Database);

    query.prepare("SELECT * FROM proffesor WHERE proffesor_id=:proffesor_id");
    query.bindValue(":proffesor_id", proffesorId);
    if(!query.exec()){
        qDebug() << query.lastError();
    }
    else
        qDebug() << "proffesor selected";
    if (query.next()) {
        int proffesorID = query.value(0).toInt();
        QString profName = query.value(1).toString();
        //int maxHour = query.value(2).toInt();
        //int averageHour = query.value(3).toInt();

        return Professor{getProffesorCourseList(proffesorID),100,200,profName,proffesorID};
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
        //int id = query.value(0).toInt();
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
                        lessonQuery.value(1).toInt(),lessonQuery.value(0).toInt()};
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
        //int id {query.value(0).toInt()};
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
                        lessonQuery.value(1).toInt(),lessonQuery.value(0).toInt()};
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
        //int id {query.value(0).toInt()};
        int lessonId {query.value(1).toInt()};

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
                        lessonQuery.value(1).toInt(),lessonQuery.value(0).toInt()};
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
        int id {query.value(0).toInt()};
        int amountOfPeople {query.value(1).toInt()};

        int number {query.value(2).toInt()};
        QString strFaculty {query.value(3).toString()};
        bool free {query.value(4).toBool()};
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

std::vector<AdministrativeUnit> Repositories::getAdmUnits()
{
    QSqlQuery query(Database);

    query.prepare(R"#(SELECT *
                  FROM admUnit)#");
    if(!query.exec()){
        qDebug() << query.lastError();
        //return invalid value or exception
    }else
        qDebug() << "admunit selected";

    std::vector<AdministrativeUnit> tmpList;

    while (query.next()) {
        int id {query.value(0).toInt()};
        int amountOfPeople {query.value(1).toInt()};
        int number {query.value(2).toInt()};
        QString strFaculty {query.value(3).toString()};

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

        tmpList.push_back(AdministrativeUnit{faculty,amountOfPeople,number,id});
    }
    return tmpList;
}

std::vector<Course> Repositories::getProffesorCourseList(int proffesorID)
{
    QSqlQuery query(Database);

    query.prepare("SELECT * FROM course WHERE proffesor_id=:proffesor_id");
    query.bindValue(":proffesor_id", proffesorID);
    if(!query.exec()){
        qDebug() << query.lastError();
    }
    else
        qDebug() << "Professor courses selected";

    std::vector<Course> courseList;
    while (query.next()) {
        int id {query.value(0).toInt()};
        QString courseName{query.value(1).toString()};
        int labId {query.value(2).toInt()};
        int seminarId {query.value(3).toInt()};
        int lectureId  {query.value(4).toInt()};

        //N+1 PROBLEM OPTIMIZATION NEEDED

        if(labId == 0 && lectureId == 0 && seminarId == 0){
            //throw exeption
        }

        if(labId == 0){
            if(lectureId == 0)
                courseList.push_back( Course{getSeminarByID(seminarId),courseName,id});

            else if(seminarId == 0)
                courseList.push_back( Course{getLectureByID(lectureId),courseName,id});

            else
                courseList.push_back( Course{getLectureByID(lectureId),getSeminarByID(seminarId),courseName,id});
        }
        else if(lectureId == 0){

            if(seminarId == 0)
                courseList.push_back( Course{getLabByID(labId),courseName,id});

            else
                courseList.push_back( Course{getLabByID(labId),getSeminarByID(seminarId),courseName,id});
        }
        else if(seminarId == 0){
            courseList.push_back( Course{getLabByID(labId),getLectureByID(lectureId),courseName,id});

        }
        else
            courseList.push_back( Course{getLabByID(labId),getLectureByID(lectureId),getSeminarByID(seminarId),courseName,id});

    }


    return courseList;


}

std::vector<std::pair<int,QString> >  Repositories::getProffessorsNames()
{
    QSqlQuery query(Database);

    query.prepare("SELECT proffesor_id, proffesor_name FROM proffesor");
    if(!query.exec()){
        qDebug() << query.lastError();
    }
    else
        qDebug() << "Professors names selected";

    std::vector<std::pair<int,QString> >  professorsNames;
    //resize vector
    while (query.next()) {
        professorsNames.push_back(std::make_pair(query.value(0).toInt(),QString{query.value(1).toString()}));
    }
    return professorsNames;

}

std::vector<std::pair<int,QString> > Repositories::getCoursesNames()
{
    QSqlQuery query(Database);

    query.prepare("SELECT course_id, course_name FROM course");
    if(!query.exec()){
        qDebug() << query.lastError();
    }
    else
        qDebug() << "Courses names selected";

    std::vector<std::pair<int,QString> > coursesNames;
    while (query.next()) {
        coursesNames.push_back(std::make_pair(query.value(0).toInt(),QString{query.value(1).toString()}));
    }
    return coursesNames;
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


