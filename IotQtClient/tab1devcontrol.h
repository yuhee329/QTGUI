#ifndef TAB1DEVCONTROL_H
#define TAB1DEVCONTROL_H

#include <QWidget>
#include <QTimer>
#include "keyled.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Tab1DevControl; }
QT_END_NAMESPACE

class Tab1DevControl : public QWidget
{
    Q_OBJECT

public:
    Tab1DevControl(QWidget *parent = nullptr);
    ~Tab1DevControl();

private:
    Ui::Tab1DevControl *ui;
    KeyLed *pKeyled;
    QTimer *pQtimer;

private slots:
    void slotKeyCheckBoxUpdate(int);
    void slotSetValueDial();
    void slotTimerStart(bool);
    void slotTimerValueChange(QString);
};
#endif // Tab1DevControl_H
