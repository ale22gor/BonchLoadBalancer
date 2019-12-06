#ifndef COURSESNAMESMODEL_H
#define COURSESNAMESMODEL_H

#include <QObject>
#include <QString>
#include <vector>
#include <QAbstractListModel>

#include "Model_global.h"


class MODEL_EXPORT CoursesNamesModel:public QAbstractListModel
{
    Q_OBJECT

    std::vector<std::pair<int,QString> > m_coursesNames;
    enum CourseNameRole {
        NameRole = Qt::UserRole + 1,
        Id
    };
public slots:
    void add(QString);

public:
    CoursesNamesModel(std::vector<std::pair<int,QString> >, QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;

    friend class Model;
};

#endif // COURSESNAMESMODEL_H
