#ifndef TAKEORDERMAINOVERLAY_H
#define TAKEORDERMAINOVERLAY_H

#include <NavigationOverlay.h>

class TakeOrderMainOverlay : public NavigationOverlay
{
    Q_OBJECT
public:
    TakeOrderMainOverlay(QWidget* parent = nullptr);
private:
    void initTakeOrderMainOverlay();
};

#endif // TAKEORDERMAINOVERLAY_H
