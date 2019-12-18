#ifndef REPOSITORYEXCEPTION_H
#define REPOSITORYEXCEPTION_H

#include <stdexcept>
#include <string>

class RepositoryException:public std::runtime_error
{
    const char *m_table;
    const char *m_operation;
    std::string m_info;


public:
    RepositoryException(const char* msg,const char* table,const char *operation,std::string info = "") noexcept;
    const char* getTable() const noexcept;
    const char* getOperation() const noexcept;
    std::string getInfo() const noexcept;
    //const char * what() const noexcept override ;
};

#endif // REPOSITORYEXCEPTION_H
