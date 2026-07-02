#include "mymodel.h"


MyModel::MyModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int MyModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return modelData.size();
}

int MyModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return 3;
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();
    if(orientation==Qt::Horizontal)
    {
        switch(section)
        {
        case 0: return QVariant(tr("Адрес"));
        case 1: return QVariant(tr("Имя"));
        case 2: return QVariant(tr("Tel"));
        default: return QVariant();
        }
    }
    else
        return QVariant(tr("%1").arg(section+1));
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();
    switch(index.column())
    {
    case 0: return modelData[index.row()].addr;
    case 1: return modelData[index.row()].name;
    case 2: return modelData[index.row()].tel1;
    default: return QVariant();
    }
}

void MyModel::SortAdres() {
    std::sort(modelData.begin(), modelData.end(), WithAddres::CompareAddr);
}
void MyModel::SortNames()
{
    std::sort(modelData.begin(), modelData.end(), WithAddres::CompareName);
}
