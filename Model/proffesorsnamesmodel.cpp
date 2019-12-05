#include "proffesorsnamesmodel.h"


ProffesorsNamesModel::ProffesorsNamesModel(std::vector<QString> names, QObject *parent):
    QAbstractListModel{parent},
    m_professorNames{names}
{

}

void ProffesorsNamesModel::add(QString name)
{
    beginResetModel();
    m_professorNames.push_back(name);
    endResetModel();}

QVariant ProffesorsNamesModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= static_cast<int>(m_professorNames.size()))
        return QVariant();

    const QString &name = m_professorNames[static_cast<size_t>(index.row())];
    if (role == NameRole)
        return name;
    else if (role == Qt::DisplayRole) {
       return name;
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
    return roles;
}
