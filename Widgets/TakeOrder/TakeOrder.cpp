#include "TakeOrder.h"
#include "ui_TakeOrder.h"

TakeOrder::TakeOrder(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::TakeOrder)
{
    ui->setupUi(this);
    initTabWidget();
}

TakeOrder::~TakeOrder()
{
    delete ui;
}

void TakeOrder::initTabWidget()
{
    m_tabs << "Coffee" << "Snacks" << "Desserts";
    for(int tabIndex = 0; tabIndex < m_tabs.size(); tabIndex++)
    {
        ui->TakeOrderTabWidget->insertTab(tabIndex, new QWidget, m_tabs[tabIndex]);
    }
}
