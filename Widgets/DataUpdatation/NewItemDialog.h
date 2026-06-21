#ifndef NEWITEMDIALOG_H
#define NEWITEMDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QFile>

namespace Ui {
class NewItemDialog;
}

class QPushButton;

class NewItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewItemDialog(QWidget* parent = nullptr);
    ~NewItemDialog();

private slots:
    void OnIconSelected();
    void OnSaveClicked();
    void OnCancelClicked();
    void OnItemNameLineEditValueChanged(const QString&);
    void OnItemPriceLineEditValueChanged(const QString&);

private:
    void initNewItemDialog();
    void initItemTypes();
    void initFileDialog();
    void initLineEdits();
    bool isValidInfo();

    void ResetDialog();

    Ui::NewItemDialog* ui;
    QPushButton* m_SaveButton;
    QPushButton* m_CancelButton;
    QStringList m_ItemTypes;
    unsigned int m_NewItemPrice;
    int m_ItemTypeIndex;
    QString m_NewItemName;
    int m_IssueCount;
    QFile m_ItemDataFile;
};

#endif // NEWITEMDIALOG_H
