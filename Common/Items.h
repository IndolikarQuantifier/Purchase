#ifndef ITEMS_H
#define ITEMS_H
#include <QString>

struct Item
{
    explicit Item(const QString& _itemType, const QString& _itemName, const QString& _iconPath, const unsigned int _itemPrice)
      : itemType(_itemType)
      , itemName(_itemName)
      , iconPath(_iconPath)
      , itemPrice(_itemPrice) {}
    QString itemType;
    QString itemName;
    QString iconPath;
    unsigned int itemPrice;
};
#endif // ITEMS_H
