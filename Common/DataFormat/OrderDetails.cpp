#include "OrderDetails.h"

OrderDetails::OrderDetails(QObject* parent)
  : QObject{ parent }
{

}

OrderDetails::OrderDetails(const QString &item, const unsigned int qty, const unsigned int cost, QObject *parent)
    : QObject{ parent }
    , m_Item(item)
    , m_Qty(qty)
    , m_Cost(cost)
{

}

const QString &OrderDetails::item()
{
    return m_Item;
}

const unsigned int OrderDetails::qty()
{
    return m_Qty;
}

const unsigned int OrderDetails::cost()
{
    return m_Cost;
}


