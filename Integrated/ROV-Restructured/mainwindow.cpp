#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

//    joyS=new Joystick_Handler();
//    server=new TCPServer("127.0.0.1",5000);
    ui->setupUi(this);
//    connect(joyS,SIGNAL(msgsent(string)),this,SLOT(sendToGUI(string)));
//    connect(joyS,SIGNAL(msgsent(string)),server,SLOT(sendmsg(string)));
//    connect(joyS,SIGNAL(msgsent(string)),server,SLOT(sendmsg(string)));
    centralWidget=new QWidget();
    centralWidget->setGeometry(0,0,1280,960);
    centralWidget->show();
    centralWidget->setWindowTitle("Stream");

//    centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    GUI=new gui(centralWidget);
}

MainWindow::MainWindow(QApplication * myApp) :
    ui(new Ui::MainWindow)
{

    joyS=new Joystick_Handler();
    server=new TCPServer("127.0.0.1",5000);
    ui->setupUi(this);
    connect(joyS,SIGNAL(sendToServer(QString)),server,SLOT(sendmsg(QString)));
    centralWidget=new QWidget();
    centralWidget->setGeometry(0,0,1280,960);
    centralWidget->show();
    centralWidget->setWindowTitle("Stream");
//    centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    GUI=new gui(centralWidget);
    connect(joyS,SIGNAL(sendToGUI(QString)),GUI,SLOT(changeInGUI(QString)));
    GUI->startListening(myApp);
}

MainWindow::~MainWindow()
{
    delete ui;
}



