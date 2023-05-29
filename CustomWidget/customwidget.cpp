#include "customwidget.h"
#include "ui_customwidget.h"

CustomWidget::CustomWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomWidget)
{
    ui->setupUi(this);
    ui->button->resize(300,100);
    ui->button->move(400,300);
    this->move(100,100);
    connect(ui->button,SIGNAL(clicked()),this,SLOT(processClick()));
}

void CustomWidget::processClick()
{
    QMessageBox::information(this,"Question","버튼이 눌렸어요!");
    emit widgetClicked();
//    qApp->quit();
}

CustomWidget::~CustomWidget()
{
    delete ui;
}

