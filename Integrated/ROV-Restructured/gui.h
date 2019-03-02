#ifndef GUI_H
#define GUI_H
#include <QObject>
#include <QPushButton>
#include "countdown.h"
#include <QTimer>
#include <QDebug>
#include <QWidget>
#include <QFont>
#include <QGridLayout>
#include <QApplication>
#include <QString>
#include <string.h>
//#include "buttonsconfiguration.h"
//#include "gstream.h"
#include "gstreamer.h"
#include <QTimer>
#include "sensorlabel.h"
#include <QProcess>

class gui : public QObject
{
    Q_OBJECT
public:
    gui(QWidget * parent=0);
    ~gui();
//    QPushButton * getChangingButton();    //temporary to use the button instead of the joystick as i ddon't have the joystick now;
    QGridLayout * getLayout();
//    void getCam(gstream *Camera, uint8_t cameraNum);
    void setCam(gstreamer *Camera, uint8_t cameraNum);
    void positionItems(QGst::Ui::VideoWidget * parent);
public slots:
    void changeInGUI(QString button);
    void changeInButtonsConfiguration(QString newConfig);
    void prepButtonsConfig();
//    void changeCamerasSizes();
    void toggleCamera();
    void updateSensorLabel(QString depth);
signals:
    void pause_play();
    void restartTimer();
    void buttonsConfig(QString Configuration);
    void show_hideButConfig();
    void setFullScreen();
private:

    void startLengthMeasuring();
    void createWindows();
    void createButtons();
    void assignButtons();
    void handleSignals();
    void checkForButtonsSwitch(int buttonIndex,QString newNumber);
    bool switchButtons(QString * button1,QString * old_button1,QString * button2,QString * old_button2);

    sensorLabel * sensor_label;
    QString configuration;
    CountDown * timer;
    QGridLayout * gridLay;
    uint8_t windowSelector=0;
//    gstream ** camera;
    gstreamer ** cameraZ;
//    QWidget ** window;
    QVideoWidget ** videoWindow;
    QWidget * GUIwindow;
    QWidget * dummyWidget;
    QGridLayout * layTimer;
    QGst::Ui::VideoWidget ** videoDisplayer;
    QProcess * process;

    const int ZUpID=0,ZDownID=1,lightOnOffID=2,activateRID=3,restartTimerID=4,startLenMeasureID=5,buttonsSettingsID=6,changeCameraID=7,playPauseTimerID=8,fullScreenID=9;
    //    QString upZButton="0",activateR="1",lightOnOff="2",restartTimer="3",buttonsSettings="4",changeCamera="5",playPauseTimer="6";
    QString * buttons;
};

#endif // GUI_H
