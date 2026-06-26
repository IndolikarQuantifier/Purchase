#include "TakeOrderMainOverlay.h"
#include "TakeOrder.h"
#include <QStackedWidget>

TakeOrderMainOverlay::TakeOrderMainOverlay(QWidget* parent) : NavigationOverlay(parent)
{
    initTakeOrderMainOverlay();
}

void TakeOrderMainOverlay::initTakeOrderMainOverlay()
{
    GetnavigationArea()->insertWidget(0, new TakeOrder);
}
