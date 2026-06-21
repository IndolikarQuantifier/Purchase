#include "OrderSummary.h"
#include "OrderDetails.h"
OrderSummary::OrderSummary(QObject* parent)
  : QObject{ parent }
  , m_Orders()
{}

void OrderSummary::addOrder(const QString& item, unsigned int qty, unsigned int cost)
{
    OrderDetails* order = new OrderDetails(item, qty, cost);
    m_Orders.push_back(order);
}
