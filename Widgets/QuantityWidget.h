#ifndef QUANTITYWIDGET_H
#define QUANTITYWIDGET_H

#include <QWidget>

namespace Ui {
class QuantityWidget;
}

class QuantityWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuantityWidget(QWidget* parent = nullptr);
    ~QuantityWidget();
    unsigned int quantityCount();
    void setQty(unsigned int qty);

private slots:
    void OnRemoveButtonClicked();
    void OnAddButtonClicked();
    void OnQuantityLineEditTextChanged(const QString& quantity);

private:
    void initQuantityButtons();
    void initQuantityLineEdit();

    Ui::QuantityWidget* ui;
    unsigned int m_Quantity;
};

#endif // QUANTITYWIDGET_H
