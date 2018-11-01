#include "gui.h"

gui::gui(QWidget *parent)
{
     timerLabel=new QLabel();
     timerLabel->setGeometry(0,0,50,50);
     timerLabel->setStyleSheet("background-color: rgba(0,0,0,0%)");
     pressureSensorLabel=new QLabel();
     updater=new QTimer();
     updater->setInterval(1000);
     updater->start();
     timer=new CountDown();
     vSpacer=new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Expanding);
     verLay=new QVBoxLayout();
     parent->setLayout(verLay);
     parent->setStyleSheet("background-color: cyan");
     connect(updater,SIGNAL(timeout()),this,SLOT(updateTimer()));
     button=new QPushButton(parent);
     timer->setTimer(1,80);
     verLay->addWidget(timerLabel);
     verLay->addWidget(pressureSensorLabel);
     str=new gstream(parent,verLay);


}

void gui::updateTimer()
{
    button->setText(timer->getTimeRemaining());
    timerLabel->setText(timer->getTimeRemaining());
}
