#ifndef TAKEORDER_H
#define TAKEORDER_H

#include <QWidget>
#include <QStringList>

namespace Ui {
class TakeOrder;
}

class TakeOrder : public QWidget
{
    Q_OBJECT

public:
    explicit TakeOrder(QWidget* parent = nullptr);
    ~TakeOrder();

private:
    void initTabWidget();

    Ui::TakeOrder* ui;
    QStringList m_tabs;
};

#endif // TAKEORDER_H
