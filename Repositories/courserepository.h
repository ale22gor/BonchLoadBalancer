#ifndef COURSEREPOSITORY_H
#define COURSEREPOSITORY_H

#include"repositories.h"
#include"course.h"

class REPOSITORIES_EXPORT CourseRepository: public Repositories<Course>
{
public:
    CourseRepository();

    void add(Course entity) override;
    void remove(T entity) = 0;
    void update(T entity) = 0;

    void getByID(int id) = 0;
};

#endif // COURSEREPOSITORY_H
