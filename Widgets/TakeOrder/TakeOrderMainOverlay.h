#ifndef TAKEORDERMAINOVERLAY_H
#define TAKEORDERMAINOVERLAY_H

#include "../Overlay/NavigationOverlay.h"

class TakeOrderMainOverlay : public NavigationOverlay
{
    Q_OBJECT
public:
    TakeOrderMainOverlay();
private:
    void initTakeOrderMainOverlay();
};

#endif // TAKEORDERMAINOVERLAY_H
