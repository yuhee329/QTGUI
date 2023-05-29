#include "ledkeywidget.h"
#include "ui_ledkeywidget.h"


LedkeyWidget::LedkeyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LedkeyWidget)
{
    ui->setupUi(this);

    pKeyled = new KeyLed(this);
    pQtimer = new QTimer(this);

    connect(pKeyled, SIGNAL(updateKeydataSig(int)),this,SLOT(slotKeyCheckBoxUpdate(int)));
    connect(pQtimer, SIGNAL(timeout()),this,SLOT(slotSetValueDial()));
    connect(ui->pPBtimerStart,SIGNAL(clicked(bool)),this,SLOT(slotTimerStart(bool)));
    connect(ui->pCBtimerValue,SIGNAL(currentIndexChanged(QString)),this,SLOT(slotTimerValueChange(QString)));
    connect(ui->pDialLed, SIGNAL(valueChanged(int)),pKeyled,SLOT(writeLedData(int)));
    connect(ui->pDialLed, SIGNAL(valueChanged(int)),ui->pProgressbarLed,SLOT(setValue(int)));
    connect(ui->pPBappQuit, SIGNAL(clicked()),qApp,SLOT(quit()));
}

void LedkeyWidget::slotTimerStart(bool check)
{
    if(check)
    {
        QString strValue = ui->pCBtimerValue->currentText();
        int timerValue = strValue.toInt();
        pQtimer->start(timerValue);
        ui->pPBtimerStart->setText("Timer Stop");
    }else{
        pQtimer->stop();
        ui->pPBtimerStart->setText("Timer Start");
    }
}

void LedkeyWidget::slotSetValueDial()
{
    int value = ui->pDialLed->value();
    if(value >= ui->pDialLed->maximum())
        value = 0;
    else
        value++;
    ui->pDialLed->setValue(value);
}

void LedkeyWidget::slotTimerValueChange(QString strValue)
{
    if(pQtimer->isActive())
    {
        pQtimer->stop();
        pQtimer->start(strValue.toInt());
    }
}

void LedkeyWidget::slotKeyCheckBoxUpdate(int key)
{
    static int lcdData = 0;
    lcdData ^= (0x01 << (key-1));
    ui->pLCDkeyNum->display(lcdData);
    if(key == 1){
        if(ui->pCBkey1->isChecked())
            ui->pCBkey1->setChecked(false);
        else
            ui->pCBkey1->setChecked(true);
    }else if(key == 2){
        if(ui->pCBkey2->isChecked())
            ui->pCBkey2->setChecked(false);
        else
            ui->pCBkey2->setChecked(true);
    }else if(key == 3){
        if(ui->pCBkey3->isChecked())
            ui->pCBkey3->setChecked(false);
        else
            ui->pCBkey3->setChecked(true);
    }else if(key == 4){
        if(ui->pCBkey4->isChecked())
            ui->pCBkey4->setChecked(false);
        else
            ui->pCBkey4->setChecked(true);
    }else if(key == 5){
        if(ui->pCBkey5->isChecked())
            ui->pCBkey5->setChecked(false);
        else
            ui->pCBkey5->setChecked(true);
    }else if(key == 6){
        if(ui->pCBkey6->isChecked())
            ui->pCBkey6->setChecked(false);
        else
            ui->pCBkey6->setChecked(true);
    }else if(key == 7){
        if(ui->pCBkey7->isChecked())
            ui->pCBkey7->setChecked(false);
        else
            ui->pCBkey7->setChecked(true);
    }else if(key == 8){
        if(ui->pCBkey8->isChecked())
            ui->pCBkey8->setChecked(false);
        else
            ui->pCBkey8->setChecked(true);
    }
}

LedkeyWidget::~LedkeyWidget()
{
    delete ui;
}

