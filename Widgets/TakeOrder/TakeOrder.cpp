#include "TakeOrder.h"
#include "ui_TakeOrder.h"
#include <Constants.h>
#include <Items.h>

#include <QFile>
#include <QDataStream>

TakeOrder::TakeOrder(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::TakeOrder)
  , m_ItemLists(this)
{
    ui->setupUi(this);
    initOrderTableWidget();
    initTabWidget();
}

TakeOrder::~TakeOrder()
{
    delete ui;
}

void TakeOrder::initTabWidget()
{
    m_tabs << "Coffee" ;//<< "Snacks" << "Desserts";
    for(int tabIndex = 0; tabIndex < m_tabs.size(); tabIndex++)
    {
        ui->TakeOrderTabWidget->insertTab(tabIndex, &m_ItemLists, m_tabs[tabIndex]);
    }
}

void TakeOrder::initOrderTableWidget()
{
    // m_OrderTableWidget.setColumnCount(2);
    QFile file(Purchase::ITEM_DATA_FILE_PATH);

    if(!file.open(QIODeviceBase::ReadOnly))
    {
        return;
    }
    QDataStream in(&file);
    unsigned int magic;
    in >> magic;
    Item item("", "", "", 0);
    int row = 0;
    while(!in.atEnd())
    {
        in >> item.itemType >> item.itemName >> item.iconPath >> item.itemPrice;
        // model->setData(QModelIndex(row, 0, QModelIndex()), )
     //   m_OrderTableWidget.insertRow(row);
      //  QTableWidgetItem* item00 = new QTableWidgetItem(item.itemName);
      //  m_OrderTableWidget.setItem(row, 0, item00);

       // QTableWidgetItem* item01 = new QTableWidgetItem(QString::number(item.itemPrice));
       // m_OrderTableWidget.setItem(row, 1, item01);
       // row++;
    }
}
