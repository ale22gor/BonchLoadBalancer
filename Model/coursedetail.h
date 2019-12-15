#ifndef COURSEDETAIL_H
#define COURSEDETAIL_H

#include <QObject>
#include <QAbstractListModel>

#include "course.h"

#include "Model_global.h"


class MODEL_EXPORT CourseDetail:public QAbstractListModel
{

    Q_OBJECT

    std::unique_ptr<Course>  m_course;

    enum CourseNameRole {
        NameRole = Qt::UserRole + 1,
        Lab,
        Lecture,
        Seminar
    };
public:
    CourseDetail(QObject *parent = nullptr);
    void setCourse(Course);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;

};

#endif // COURSEDETAIL_H
