#ifndef PROFESSORDETAIL_H
#define PROFESSORDETAIL_H


#include <QAbstractListModel>

#include "professor.h"

#include "Model_global.h"


class MODEL_EXPORT ProfessorDetail:public QAbstractListModel
{
    Professor m_prof;
    enum CourseNameRole {
        NameRole = Qt::UserRole + 1,
        Lab,
        Lecture,
        Seminar
    };
public:
    ProfessorDetail(Professor, QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
};

#endif // PROFESSORDETAIL_H
