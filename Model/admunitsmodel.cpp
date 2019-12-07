#include "admunitsmodel.h"


AdmUnitsModel::AdmUnitsModel(std::vector<AdministrativeUnit> admUnits, QObject *parent):
    QAbstractListModel{parent},
    m_admUnits{admUnits}
{

}

QVariant AdmUnitsModel::data(const QModelIndex &index, int role) const
{

    //qDebug() << m_coursesNames[static_cast<size_t>(index.row())];
    if (index.row() < 0 || index.row() >= static_cast<int>(m_admUnits.size()))
        return QVariant();

    const AdministrativeUnit& admunit{m_admUnits[static_cast<size_t>(index.row())]};

    if(role == Faculty)
    {
        return admunit.getFaculty();
    }
    else if(role == Amount)
    {
        return admunit.getamountOfPeople();
    }
    else if(role == Group)
    {
        return admunit.getNumber();
    }

    else
        return QVariant();

}

int AdmUnitsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_admUnits.size());
}

QHash<int, QByteArray> AdmUnitsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Faculty] = "faculty";
    roles[Group] = "group";
    roles[Amount] = "amount";

    return roles;
}
