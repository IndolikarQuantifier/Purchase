#include "MainWindow.h"
// #include "./Widgets/TakeOrder.h"
#include "Widgets/DataUpdatation/NewItemDialog.h"
#include "Widgets/TakeOrder/TakeOrderMainOverlay.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // setCentralWidget(new Order);
    connect(ui->NewItemButton, &QPushButton::clicked, this, &MainWindow::OnNewItemButtonClicked);
    connect(ui->TakeOrdersButton, &QPushButton::clicked, this, &MainWindow::OnTakeOrderButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnNewItemButtonClicked()
{
    NewItemDialog dialog;
    dialog.setModal(true);
    dialog.exec();
}

void MainWindow::OnTakeOrderButtonClicked()
{
    TakeOrderMainOverlay overlay;
    overlay.setModal(true);
    overlay.exec();
}
