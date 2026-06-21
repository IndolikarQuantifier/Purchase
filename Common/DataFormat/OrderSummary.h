#ifndef ORDERSUMMARY_H
#define ORDERSUMMARY_H

#include <QObject>
#include <QVector>

class OrderDetails;

class OrderSummary : public QObject
{
    Q_OBJECT
public:
    explicit OrderSummary(QObject* parent = nullptr);
    void addOrder(const QString& item, unsigned int qty, unsigned int cost);

private:
    QVector<OrderDetails*> m_Orders;
};

#endif // ORDERSUMMARY_H
