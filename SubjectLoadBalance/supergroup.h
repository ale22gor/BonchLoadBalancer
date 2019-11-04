#include "administrativeunit.h"


#include "SubjectLoadBalance_global.h"

#ifndef SUPERGROUP_H
#define SUPERGROUP_H


class SUBJECTLOADBALANCE_EXPORT SuperGroup: public AdministrativeUnit
{
public:
    SuperGroup(Faculty ,int ,int);
};

#endif // SUPERGROUP_H
