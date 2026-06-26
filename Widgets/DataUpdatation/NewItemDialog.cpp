#include "NewItemDialog.h"
#include "ui_NewItemDialog.h"
#include <Constants.h>
#include <Items.h>
#include <QFileDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDialogButtonBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

NewItemDialog::NewItemDialog(QWidget* parent)
  : QDialog(parent)
  , ui(new Ui::NewItemDialog)
  , m_SaveButton(new QPushButton)
  , m_CancelButton(new QPushButton)
  , m_ItemTypeIndex(0)
  , m_IssueCount(1)
  , m_ItemDataFile(Purchase::ITEM_DATA_FILE_PATH)
{
    ui->setupUi(this);
    setWindowTitle(tr("Add New Item"));
    initNewItemDialog();
    initItemTypes();
    initFileDialog();
    initLineEdits();
    initDataFile();
}

NewItemDialog::~NewItemDialog()
{
    delete ui;
    m_ItemDataFile.close();
}

void NewItemDialog::OnIconSelected()
{
    QString iconPath = QFileDialog::getOpenFileName(this, tr("Choose icon for new item"), ".", tr("Images (*.png, *.jpg, *.ico)"));
    qDebug() << "path " << iconPath;
}

void NewItemDialog::OnSaveClicked()
{
    if(isValidInfo())
    {
        if(!m_ItemDataFile.isOpen())
        {
            if(!m_ItemDataFile.open(QIODeviceBase::Append))
            {
                ui->StatusPlainTextEdit->setPlainText(qPrintable(m_ItemDataFile.errorString()));
                ResetDialog();
                return;
            }
        }
        QDataStream out(&m_ItemDataFile);
        out.setVersion(QDataStream::Qt_4_1);
        Item item(ui->NewItemTypeComboBox->currentText(), m_NewItemName, "", m_NewItemPrice);
        out << item.itemType << item.itemName << item.iconPath << item.itemPrice;
        ui->StatusPlainTextEdit->setPlainText(tr("Entry added Successfully..."));
        ResetDialog();
    }
}

void NewItemDialog::OnCancelClicked()
{
    m_ItemDataFile.close();
    emit reject();
}

void NewItemDialog::OnItemNameLineEditValueChanged(const QString & itemName)
{
    m_NewItemName = itemName;
    if(itemName.isEmpty())
    {
        m_SaveButton->setDisabled(true);
        // ui->StatusPlainTextEdit->setPlainText(tr(QString("%1 Enter Item Name Type\n").arg(m_IssueCount).toStdString().c_str()));
        // m_IssueCount++;
    }
    else
    {
        m_SaveButton->setDisabled(false);
    }
    // else {

    // }
}

void NewItemDialog::OnItemPriceLineEditValueChanged(const QString & itemPrice)
{
    m_NewItemPrice = itemPrice.toUInt();
    if(itemPrice.isEmpty())
    {
        m_SaveButton->setDisabled(true);
        // ui->StatusPlainTextEdit->setPlainText(tr(QString("%1 Enter Item Name Type\n").arg(m_IssueCount).toStdString().c_str()));
        // m_IssueCount++;
    }
    else
    {
        m_SaveButton->setDisabled(false);
    }
}

void NewItemDialog::initNewItemDialog()
{
    QDialogButtonBox* dialogButtonBox = new QDialogButtonBox(Qt::Horizontal);
    m_SaveButton->setText(tr("Save"));
    m_CancelButton->setText(tr("Cancel"));
    connect(m_SaveButton, &QPushButton::clicked, this, &NewItemDialog::OnSaveClicked);
    connect(m_CancelButton, &QPushButton::clicked, this, &NewItemDialog::OnCancelClicked);
    m_SaveButton->setDisabled(true);
    dialogButtonBox->addButton(m_SaveButton, QDialogButtonBox::ActionRole);
    dialogButtonBox->addButton(m_CancelButton, QDialogButtonBox::RejectRole);

    QHBoxLayout* footerHLayout = new QHBoxLayout(this);
    footerHLayout->addWidget(m_SaveButton);
    footerHLayout->addWidget(m_CancelButton);
    ui->NewItemDialogHLayout->addLayout(footerHLayout);
}

void NewItemDialog::initItemTypes()
{
    m_ItemTypes << "NA" << "Coffee" << "Snacks" << "Desserts";
    QStandardItemModel* model = new QStandardItemModel(this);
    for(int itemIndex = 0; itemIndex < m_ItemTypes.size(); itemIndex++)
    {
        model->setItem(itemIndex, new QStandardItem(m_ItemTypes[itemIndex]));
    }
    ui->NewItemTypeComboBox->setModel(model);
}

void NewItemDialog::initFileDialog()
{
    connect(ui->ChooseIconButton, &QPushButton::clicked, this, &NewItemDialog::OnIconSelected);
}

void NewItemDialog::initLineEdits()
{
    QRegularExpression itemNameRegularExpression("^[A-Za-z ]+$");
    QRegularExpressionValidator* itemNameValidator = new QRegularExpressionValidator(itemNameRegularExpression, this);
    ui->NewItemNameLineEdit->setValidator(itemNameValidator);
    connect(ui->NewItemNameLineEdit, &QLineEdit::textChanged, this, &NewItemDialog::OnItemNameLineEditValueChanged);

    QRegularExpression itemPriceRegularExpression("^\\d+(?:,\\d+)*$");
    QRegularExpressionValidator* itemPriceValidator = new QRegularExpressionValidator(itemPriceRegularExpression, this);
    ui->NewItemPriceLabelLineEdit->setValidator(itemPriceValidator);
    connect(ui->NewItemPriceLabelLineEdit, &QLineEdit::textChanged, this, &NewItemDialog::OnItemPriceLineEditValueChanged);
}

void NewItemDialog::initDataFile()
{
    if(!m_ItemDataFile.exists())
    {
        if(m_ItemDataFile.open(QIODeviceBase::WriteOnly))
        {
            QDataStream out(&m_ItemDataFile);
            out.setVersion(QDataStream::Qt_4_1);
            out << Purchase::NEW_ITEM_MAGIC_NUMBER;
            m_ItemDataFile.close();
        }
    }
}

bool NewItemDialog::isValidInfo()
{
    bool isValid = false;
    int count = 1;
    int itemTypeIndex = ui->NewItemTypeComboBox->currentIndex();
    isValid = itemTypeIndex != 0 && !m_NewItemName.isEmpty() && m_NewItemPrice != 0;
    if(itemTypeIndex == 0)
    {
        ui->StatusPlainTextEdit->setPlainText(tr(QString("%1 Select Valid Item Type\n").arg(count).toStdString().c_str()));
        count++;
    }
    if(m_NewItemName.isEmpty())
    {
        ui->StatusPlainTextEdit->setPlainText(tr(QString("%1 Enter Item Name\n").arg(count).toStdString().c_str()));
        count++;
    }
    if(m_NewItemPrice == 0)
    {
        ui->StatusPlainTextEdit->setPlainText(tr(QString("%1 Enter Item Price\n").arg(count).toStdString().c_str()));
        count++;
    }
    return isValid;
}

void NewItemDialog::ResetDialog()
{
    ui->NewItemTypeComboBox->setCurrentIndex(0);
    ui->NewItemNameLineEdit->clear();
    ui->NewItemPriceLabelLineEdit->clear();
    ui->NewItemIcon->clear();
    ui->StatusPlainTextEdit->setPlainText(tr("Entry Added Successfully..."));
}
