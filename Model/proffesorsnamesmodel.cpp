#include "proffesorsnamesmodel.h"


ProffesorsNamesModel::ProffesorsNamesModel(std::vector<std::pair<int,QString> >  names, QObject *parent):
    QAbstractListModel{parent},
    m_professorNames{names}
{

}
/*
void ProffesorsNamesModel::add(QString name)
{
    beginResetModel();
    //m_professorNames.push_back(name);
    endResetModel();
}
*/
QVariant ProffesorsNamesModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= static_cast<int>(m_professorNames.size()))
        return QVariant();

    const std::pair<int,QString> &name = m_professorNames[static_cast<size_t>(index.row())];
    if (role == NameRole)
        return name.second;
    else if (role == IdRole)
        return name.first;
    else if (role == Qt::DisplayRole) {
        return name.second;
    }
    return QVariant();

}

int ProffesorsNamesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_professorNames.size());
}

QHash<int, QByteArray> ProffesorsNamesModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[IdRole] = "profId";
    return roles;
}
