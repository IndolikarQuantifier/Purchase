#ifndef NAVIGATIONOVERLAY_H
#define NAVIGATIONOVERLAY_H

#include <QDialog>
#include <QStackedWidget>

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
    QStackedWidget* GetnavigationArea() const;
    Ui::NavigationOverlay* ui;

};

#endif // NAVIGATIONOVERLAY_H
