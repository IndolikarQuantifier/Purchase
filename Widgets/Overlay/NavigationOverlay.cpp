#include "NavigationOverlay.h"

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
