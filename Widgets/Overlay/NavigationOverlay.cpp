#include "NavigationOverlay.h"
#include "ui_NavigationOverlay.h"

NavigationOverlay::NavigationOverlay(QWidget* parent)
  : QDialog(parent)
  , ui(new Ui::NavigationOverlay)
{
    ui->setupUi(this);
}

NavigationOverlay::~NavigationOverlay()
{
    delete ui;
}

QStackedWidget *NavigationOverlay::GetnavigationArea() const
{
    return ui->NavigationStackedWidget;
}
