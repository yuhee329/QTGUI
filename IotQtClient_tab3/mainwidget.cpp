#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    pTab1DevControl = new Tab1DevControl(ui->pTab1);
    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);
    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    ui->pTab1->setLayout(pTab1DevControl->layout());
    ui->pTab2->setLayout(pTab2SocketClient->layout());
    ui->pTab3->setLayout(pTab3ControlPannel->layout());


//    connect(pTab2SocketClient,SIGNAL(sigLedWrite(int)),pTab1DevControl.getKeyLed(),SLOT(slotSetValueDial(value(int))));
    connect(pTab2SocketClient,SIGNAL(sigLedWrite(int)),pTab1DevControl,SLOT(slotDialSetValue(int)));
    connect(pTab3ControlPannel,SIGNAL(sigSocketSendData(QString)),pTab2SocketClient,SLOT(slotSocketSendData(QString)));
    connect(pTab2SocketClient,SIGNAL(sigTab3RecvData(QString)),pTab3ControlPannel,SLOT(slotTab3RecvData(QString)));
}

MainWidget::~MainWidget()
{
    delete ui;
}

