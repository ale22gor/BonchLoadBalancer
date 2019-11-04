class Proffesor;
#include <list>


#include "SubjectLoadBalance_global.h"

#ifndef REALLOAD_H
#define REALLOAD_H


class SUBJECTLOADBALANCE_EXPORT RealLoad
{
    std::list <Proffesor*> m_proffesors;
public:
    RealLoad();
};

#endif // REALLOAD_H
