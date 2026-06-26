#include "QuantityWidget.h"
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "ui_QuantityWidget.h"

QuantityWidget::QuantityWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::QuantityWidget)
  , m_Quantity(0)
{
    ui->setupUi(this);
    initQuantityButtons();
    initQuantityLineEdit();
}

QuantityWidget::~QuantityWidget()
{
    delete ui;
}

unsigned int QuantityWidget::quantityCount()
{
    return m_Quantity;
}

void QuantityWidget::setQty(unsigned int qty)
{
    ui->QuantityLineEdit->setText(QString::number(qty));
}

void QuantityWidget::initQuantityButtons()
{
    ui->RemoveButton->setDisabled(true);
    connect(ui->RemoveButton, &QPushButton::clicked, this, &QuantityWidget::OnRemoveButtonClicked);
    connect(ui->AddButton, &QPushButton::clicked, this, &QuantityWidget::OnAddButtonClicked);
}

void QuantityWidget::initQuantityLineEdit()
{
    QRegularExpression regularExpression("^(?:[0-9]|[1-9][0-9]{1,2})$");
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(regularExpression, this);
    ui->QuantityLineEdit->setValidator(validator);
    ui->QuantityLineEdit->setText("0");
    connect(ui->QuantityLineEdit, &QLineEdit::textChanged, this, &QuantityWidget::OnQuantityLineEditTextChanged);
}

void QuantityWidget::OnRemoveButtonClicked()
{
    m_Quantity--;
    ui->QuantityLineEdit->setText(QString::number(m_Quantity));
    if(m_Quantity == 0) {
        ui->RemoveButton->setDisabled(true);
    }
}

void QuantityWidget::OnAddButtonClicked()
{
    if(m_Quantity == 0) {
        ui->RemoveButton->setDisabled(false);
    }
    m_Quantity++;
    ui->QuantityLineEdit->setText(QString::number(m_Quantity));
}

void QuantityWidget::OnQuantityLineEditTextChanged(const QString &quantity)
{
    m_Quantity = quantity.toUInt();
    if(m_Quantity == 0) {
        ui->RemoveButton->setDisabled(true);
    }
    else {
        ui->RemoveButton->setDisabled(false);
    }
}
