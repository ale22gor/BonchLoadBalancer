#include "repositories.h"
#include <QSqlQuery>
#include <QSqlError>



template<class T>
void Repositories<T>::add(T entity)
{

}

template<>
void Repositories<Course>::add(Course entity)
{

}
