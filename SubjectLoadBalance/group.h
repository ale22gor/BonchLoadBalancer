#include "administrativeunit.h"

#include "SubjectLoadBalance_global.h"

#ifndef GROUP_H
#define GROUP_H


class SUBJECTLOADBALANCE_EXPORT Group: public AdministrativeUnit
{
public:
    Group(Faculty ,int ,int);
};

#endif // GROUP_H
