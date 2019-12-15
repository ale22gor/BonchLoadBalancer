#ifndef ADMUNITTOSELECT_H
#define ADMUNITTOSELECT_H

#include "administrativeunit.h"


struct admUnitToSelect{
    bool m_LabSelected;
    bool m_lectureSelected;
    bool m_seminarSelected;
    AdministrativeUnit  m_admUnits;

    admUnitToSelect(AdministrativeUnit admUnits):m_LabSelected{false},m_lectureSelected{false},m_seminarSelected{false},m_admUnits{admUnits}
    {}
    void resetSelected(){
        m_LabSelected = false;
        m_lectureSelected = false;
        m_seminarSelected = false;
    }
};

#endif // ADMUNITTOSELECT_H


