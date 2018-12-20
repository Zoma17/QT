#include "buttonsconfiguration.h"
#include <QDebug>


/*
    Out of date ,needs to be modified

    PROCEDURE TO ADD A BUTTON TO THE CHANGING BUTTONS:
    1-ADD A RESPRESENTATIVE BUTTON AND SLOT FOR IT HERE
    2-CONNECT THE BUTTON CLICKING AND THE SLOT
    3-IN THE SLOT , SET A SUITABLE MESSAGE THAT CONTAINS YOUR DESIRED JS BUTTON
    4-REMEMBER THE MESSAGE

    THEN IN GUI CLASS:
    5-CREATE A QSTRING IN IT
    6-GOTO CHANGE_IN_GUI FUNCNTION , WITHIN IT , ADD A CONDITION IF BUTTON==YOUR RECENTLY CREATED STRING IN STEP 5 , IF IT HAPPENS
        WHAT YOU HAPPEN SHALL BE PERFORMED
    7-GOTO CHANGE_BUTTONS_CONFIGURATION FUNCTION AND ADD YOUR CONDITION , IF CHECK== YOUR MESSAGE FROM STEPS 3&4 , THEN YOUR STEP 5
        QSTRING SHALL BECOME newConfig[newConfig.length()-1];

    8-DONE



*/



buttonsConfiguration::buttonsConfiguration()
{


    confWidget=new QWidget();
    confWidget->setGeometry(200,200,800,600);
    confWidget->setStyleSheet("background-color: orange ;");
    confWidget->setWindowTitle("Joystick Buttons Configuration");
    confWidget->setAttribute(Qt::WA_TransparentForMouseEvents);
    gridLay=new QGridLayout();
    confWidget->setLayout(gridLay);
    createButtons();
    deployButtons();
    initialDisplay();
    handleClicking();
//    spacer=new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Expanding);

}

void buttonsConfiguration::createButtons()
{



    jsButtons=new joystickButton * [functionBttns];
    adminButtons=new joystickButton * [adminBttns];
    selectionButtons=new QRadioButton * [joyBttns];

    for (int i=0;i<adminBttns;i++){
        adminButtons[i]=new joystickButton();
    }
    for (int i=0;i<functionBttns;i++){
        jsButtons[i]=new joystickButton();
    }
    for (int i=0;i<joyBttns;i++){
        selectionButtons[i]=new QRadioButton();
        selectionButtons[i]->setStyleSheet("color: black ;font-size: 20px; background-color: orange ; font:arial,helvetica;");
        selectionButtons[i]->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        selectionButtons[i]->setText("Button "+QString::number(i));
    }

    jsButtons[0]->setInfo("Buttons Settings","0");
    jsButtons[1]->setInfo("Change Camera","1");
    jsButtons[2]->setInfo("Restart Timer","2");
    jsButtons[3]->setInfo("Play/Pause Timer","3");
    adminButtons[1]->setInfo("Cancel","");
    adminButtons[0]->setInfo("Save","");

    textLabel=new QLabel("Camera Switch:         2\nTimer Play-Pause       1\nConfiguration Window  0\nRestart Timer           3");

}

void buttonsConfiguration::deployButtons()
{
    textLabel->setStyleSheet("QLabel{color: black ;  font-size: 20px; background-color: orange ; font:arial,helvetica; }");

    gridLay->addWidget(textLabel,0,2,1,4);
    textLabel->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    gridLay->setVerticalSpacing(50);
    gridLay->setMargin(50);


    for (int i=0;i<functionBttns;i++){
        gridLay->addWidget(jsButtons[i], 3+floor(i/4)  ,2*i-8*floor(i/4),1,2);
    }
    for (int i=0;i<joyBttns;i++){
        gridLay->addWidget(selectionButtons[i],4+floor(i/4)  ,2*i-8*floor(i/4),1,2);
    }
    for (int i=0;i<adminBttns;i++){
        gridLay->addWidget(adminButtons[i],8,6+i,1,1);
    }


}

void buttonsConfiguration::initialDisplay()
{
    for (int i=0;i<adminBttns;i++){
        adminButtons[i]->hide();
    }
    for (int i=0;i<functionBttns;i++){
        jsButtons[i]->show();
    }
    for (int i=0;i<joyBttns;i++){
        selectionButtons[i]->hide();
    }

//    confWidget->show();

}

void buttonsConfiguration::handleClicking()
{
    for (int i=0;i<adminBttns;i++){
        connect(adminButtons[i],SIGNAL(clicked()),adminButtons[i],SLOT(buttonClicked()));
        connect(adminButtons[i],SIGNAL(thisClicked(joystickButton*)),this,SLOT(adminButtonClicked(joystickButton *)));
    }

    for (int i=0;i<functionBttns;i++){
        connect(jsButtons[i],SIGNAL(clicked()),jsButtons[i],SLOT(buttonClicked()));
        connect(jsButtons[i],SIGNAL(thisClicked(joystickButton*)),this,SLOT(handleClicking(joystickButton *)));
    }

}

QString buttonsConfiguration::getButtonName(int index)
{
    return jsButtons[index]->getName();
}



void buttonsConfiguration::show_hide()
{
    confWidget->isHidden() ? confWidget->show() : confWidget->hide();
}

void buttonsConfiguration::handleClicking(joystickButton * clickedButton)
{
    for (int i=0;i<adminBttns;i++){
        adminButtons[i]->show();
    }
    for (int i=0;i<functionBttns;i++){
        jsButtons[i]->hide();
    }
    for (int i=0;i<joyBttns;i++){
        selectionButtons[i]->show();
    }
    clickedButton->show();
    buttonAndRole=clickedButton->getName()+"=";
}


void buttonsConfiguration::adminButtonClicked(joystickButton * clickedButton)
{
    if (clickedButton==adminButtons[0]){
        for (int i=0;i<joyBttns;i++){
            if(selectionButtons[i]->isChecked()){
                buttonAndRole+=QString::number(i);
                emit newSettings(buttonAndRole);
                break;
            }
        }
    }

    buttonAndRole="";
    initialDisplay();
}

void buttonsConfiguration::getCurrentButtons(QString currentConf)
{
    textLabel->setText(currentConf);
}
