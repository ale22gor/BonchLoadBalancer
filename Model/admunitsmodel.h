#ifndef ADMUNITSMODEL_H
#define ADMUNITSMODEL_H

#include "admUnitToSelect.h"
#include <vector>
#include <QObject>
#include <QAbstractListModel>


class AdmUnitsModel:public QAbstractListModel
{
    Q_OBJECT

    std::vector<admUnitToSelect> m_admUnitsToSelect;

    enum CourseNameRole {
        Faculty = Qt::UserRole + 1,
        Group,
        Amount,
        LabCheckStatus,
        LectureCheckStatus,
        SeminarCheckStatus,
    };
public:
    AdmUnitsModel(std::vector<AdministrativeUnit>,QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    void resetData();

    friend class Model;
};

#endif // ADMUNITSMODEL_H
