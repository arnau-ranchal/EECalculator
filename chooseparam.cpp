#include "chooseparam.h"

Chooseparam::Chooseparam(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant Chooseparam::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex Chooseparam::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex Chooseparam::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int Chooseparam::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int Chooseparam::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant Chooseparam::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
