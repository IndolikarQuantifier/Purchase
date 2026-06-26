#ifndef MVC_H
#define MVC_H
#include <QObject>

namespace Purchase
{
    enum PurchaseRole_E
    {
        OrderItemTypeRole = Qt::UserRole + 1,
        OrderItemNameRole,
        OrderItemIconRole,
        OrderItemQtyRole,
        OrderItemPriceRole
    };
}

#endif // MVC_H
