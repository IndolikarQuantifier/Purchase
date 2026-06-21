#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <QObject>

class OrderDetails : public QObject
{
    Q_OBJECT
public:
    explicit OrderDetails(QObject* parent = nullptr);
    explicit OrderDetails(const QString& item, const unsigned int qty, const unsigned int cost, QObject* parent = nullptr);
    const QString& item();
    const unsigned int qty();
    const unsigned int cost();

private:
    QString m_Item;
    unsigned int m_Qty;
    unsigned int m_Cost;
};

#endif // ORDERDETAILS_H
