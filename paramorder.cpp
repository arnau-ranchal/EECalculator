#include "paramorder.h"

ParamOrder::ParamOrder(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant ParamOrder::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex ParamOrder::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex ParamOrder::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int ParamOrder::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int ParamOrder::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant ParamOrder::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
