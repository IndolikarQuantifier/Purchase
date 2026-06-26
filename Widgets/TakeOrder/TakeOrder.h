#ifndef TAKEORDER_H
#define TAKEORDER_H

#include <QWidget>
#include <QStringList>
#include <QListView>

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
    void initOrderTableWidget();

    Ui::TakeOrder* ui;
    QStringList m_tabs;
    QListView m_ItemLists;

};

#endif // TAKEORDER_H
