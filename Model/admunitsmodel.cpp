#include "admunitsmodel.h"


AdmUnitsModel::AdmUnitsModel(std::vector<AdministrativeUnit> admUnits, QObject *parent):
    QAbstractListModel{parent}
{
    //check for optimization
    for(auto& admUnit:admUnits)
        m_admUnitsToSelect.push_back(admUnit);
}

QVariant AdmUnitsModel::data(const QModelIndex &index, int role) const
{

    //qDebug() << m_coursesNames[static_cast<size_t>(index.row())];
    if (index.row() < 0 || index.row() >= static_cast<int>(m_admUnitsToSelect.size()))
        return QVariant();

    const admUnitToSelect& admunit{m_admUnitsToSelect[static_cast<size_t>(index.row())]};

    if(role == Faculty)
    {
        return admunit.m_admUnits.getFaculty();
    }
    else if(role == Amount)
    {
        return admunit.m_admUnits.getamountOfPeople();
    }
    else if(role == Group)
    {
        return admunit.m_admUnits.getNumber();
    }
    else if(role == LabCheckStatus)
    {
        return admunit.m_LabSelected;
    }
    else if(role == LectureCheckStatus)
    {
        return admunit.m_lectureSelected;
    }
    else if(role == SeminarCheckStatus)
    {
        return admunit.m_seminarSelected;
    }

    else
        return QVariant();

}

int AdmUnitsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_admUnitsToSelect.size());
}

QHash<int, QByteArray> AdmUnitsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Faculty] = "faculty";
    roles[Group] = "group";
    roles[Amount] = "amount";
    roles[LabCheckStatus] = "labCheckStatus";
    roles[LectureCheckStatus] = "lectureCheckStatus";
    roles[SeminarCheckStatus] = "seminarCheckStatus";

    return roles;
}

bool AdmUnitsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() >= static_cast<int>(m_admUnitsToSelect.size()))
        return false;

    admUnitToSelect& admunit{m_admUnitsToSelect[static_cast<size_t>(index.row())]};
    if (role == LabCheckStatus) admunit.m_LabSelected = value.toBool();
    else if (role == LectureCheckStatus) admunit.m_lectureSelected = value.toBool();
    else if (role == SeminarCheckStatus) admunit.m_seminarSelected = value.toBool();
    else return false;

    emit dataChanged(index, index, { role } );

    return true ;
}
