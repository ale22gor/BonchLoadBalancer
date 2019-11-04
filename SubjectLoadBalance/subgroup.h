#include "administrativeunit.h"


#include "SubjectLoadBalance_global.h"

#ifndef SUBGROUP_H
#define SUBGROUP_H


class SUBJECTLOADBALANCE_EXPORT SubGroup: public AdministrativeUnit
{
public:
    SubGroup(Faculty ,int ,int);
};

#endif // SUBGROUP_H
