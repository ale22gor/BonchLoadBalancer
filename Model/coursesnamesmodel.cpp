#include "coursesnamesmodel.h"

#include<QtDebug>

CoursesNamesModel::CoursesNamesModel(std::vector<std::pair<int,QString> > names, QObject *parent):
    QAbstractListModel{parent},
    m_coursesNames{names}
{
}

void CoursesNamesModel::add(QString name)
{
    //beginInsertRows(QModelIndex(), rowCount(), rowCount());
    //m_coursesNames.push_back(name);
    //endInsertRows();
}

QVariant CoursesNamesModel::data(const QModelIndex &index, int role) const
{
    //qDebug() << m_coursesNames[static_cast<size_t>(index.row())];
    if (index.row() < 0 || index.row() >= static_cast<int>(m_coursesNames.size()))
        return QVariant();

    const std::pair<int,QString> &name = m_coursesNames[static_cast<size_t>(index.row())];
    if (role == NameRole)
        return QVariant{name.second};
    else if(role == Id)
        return QVariant{name.first};
    else if (role == Qt::DisplayRole)
       return QVariant{name.second};
    else
        return QVariant();

}

int CoursesNamesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_coursesNames.size());
}

QHash<int, QByteArray> CoursesNamesModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[Id] = "courseId";
    return roles;
}
