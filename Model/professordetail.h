#ifndef PROFESSORDETAIL_H
#define PROFESSORDETAIL_H


#include <QAbstractListModel>
#include <memory>

#include "professor.h"

#include "Model_global.h"


class MODEL_EXPORT ProfessorDetail:public QAbstractListModel
{

    std::unique_ptr<Professor> m_prof;
    enum CourseNameRole {
        NameRole = Qt::UserRole + 1,
        Lab,
        Lecture,
        Seminar
    };

public:
    ProfessorDetail(QObject *parent = nullptr);
    void setProf(Professor);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
};

#endif // PROFESSORDETAIL_H
