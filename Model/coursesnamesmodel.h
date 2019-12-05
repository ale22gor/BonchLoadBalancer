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

    std::vector<QString> m_coursesNames;
    enum CourseNameRole {
        NameRole = Qt::UserRole + 1,
    };
public slots:
    void add(QString);

public:
    CoursesNamesModel(std::vector<QString>, QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
};

#endif // COURSESNAMESMODEL_H
