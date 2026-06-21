#ifndef NAVIGATIONOVERLAY_H
#define NAVIGATIONOVERLAY_H

#include <QDialog>
#include "ui_NavigationOverlay.h"

namespace Ui {
class NavigationOverlay;
}

class NavigationOverlay : public QDialog
{
    Q_OBJECT

public:
    explicit NavigationOverlay(QWidget* parent = nullptr);
    ~NavigationOverlay();

protected:
    Ui::NavigationOverlay* ui;
};

#endif // NAVIGATIONOVERLAY_H
