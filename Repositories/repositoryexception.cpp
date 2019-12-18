#include "repositoryexception.h"


RepositoryException::RepositoryException(const char* msg,const char *table,const char *operation,std::string info) noexcept:
    std::runtime_error{msg},
    m_table{table},
    m_operation{operation},
    m_info{info}
{

}

const char *RepositoryException::getTable() const noexcept
{
    return m_table;
}

const char *RepositoryException::getOperation() const noexcept
{
    return m_operation;
}

std::string RepositoryException::getInfo() const noexcept
{
    return m_info;
}


