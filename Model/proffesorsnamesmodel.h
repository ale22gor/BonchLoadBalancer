#ifndef PROFFESORSNAMESMODEL_H
#define PROFFESORSNAMESMODEL_H

#include <QObject>
#include <QString>
#include <vector>

#include <QAbstractListModel>


#include "Model_global.h"

class MODEL_EXPORT ProffesorsNamesModel:public QAbstractListModel
{    Q_OBJECT


     std::vector<std::pair<int,QString> > m_professorNames;
     enum NameRole {
         NameRole = Qt::UserRole + 1,
         IdRole
     };
 public slots:
     //void add(QString) = delete;

 public:
     ProffesorsNamesModel(std::vector<std::pair<int,QString> > , QObject *parent = nullptr);
     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
     int rowCount(const QModelIndex & parent = QModelIndex()) const override;
     QHash<int, QByteArray> roleNames() const override;
};

#endif // PROFFESORSNAMESMODEL_H
