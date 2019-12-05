#ifndef PROFFESORSNAMESMODEL_H
#define PROFFESORSNAMESMODEL_H

#include <QObject>
#include <QString>
#include <vector>
#include <QAbstractListModel>


#include "Model_global.h"

class MODEL_EXPORT ProffesorsNamesModel:public QAbstractListModel
{    Q_OBJECT

     std::vector<QString> m_professorNames;
     enum NameRole {
         NameRole = Qt::UserRole + 1,
     };
 public slots:
     void add(QString);

 public:
     ProffesorsNamesModel(std::vector<QString>, QObject *parent = nullptr);
     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
     int rowCount(const QModelIndex & parent = QModelIndex()) const;
     QHash<int, QByteArray> roleNames() const;
};

#endif // PROFFESORSNAMESMODEL_H
