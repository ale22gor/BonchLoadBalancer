#ifndef ADMUNITSMODEL_H
#define ADMUNITSMODEL_H

#include "administrativeunit.h"
#include <vector>
#include <QObject>
#include <QAbstractListModel>

class AdmUnitsModel:public QAbstractListModel
{
    Q_OBJECT

    std::vector<AdministrativeUnit> m_admUnits;

    enum CourseNameRole {
        Faculty = Qt::UserRole + 1,
        Group,
        Amount
    };
public:
    AdmUnitsModel(std::vector<AdministrativeUnit>,QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
};

#endif // ADMUNITSMODEL_H
