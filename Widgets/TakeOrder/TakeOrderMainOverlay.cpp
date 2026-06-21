#include "TakeOrderMainOverlay.h"
#include "TakeOrder.h"
#include <QStackedWidget>

TakeOrderMainOverlay::TakeOrderMainOverlay()
{
    initTakeOrderMainOverlay();
}

void TakeOrderMainOverlay::initTakeOrderMainOverlay()
{
    ui->NavigationStackedWidget->insertWidget(0, new TakeOrder);
}
