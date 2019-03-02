#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QObject>
#include <QDebug>
#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <QTimer>
#include <string.h>
#include <QString>
using namespace std;


class Joystick:public QObject
{
    Q_OBJECT
public:
    Joystick();
    ~Joystick();
    void JoyStickInitialization();

    int get_x();
    int get_y();
    int get_z();
    int get_r();
    int getMapped_z();
    int get_hat();
    void activate();
    void remove();
    bool checkIfGuiButton(int button);
    void buttonDown(int button);
    void buttonUp(int button);
    void changeInButtonsConfiguration(QString newConfig);
    int getNumOfPiButtons();
    int getButtonNumber(int buttonIndex);

public slots:
    void action();
signals:
    void sendMsg(QString);
    void newButtons();

private:
    QTimer *timer;
    SDL_Event  event;
    int prev_x,prev_y,prev_z,prev_r,upZ=0,light=0,axisChangeFlag=0,activateR=0;
    int x,y,z,r;
//    int upZButton=0,activateRButton=1,lightButton=6;
    int * buttons;
    QString msg;
    void change_prev();
    void move();
    int mapZ();
    int map(int x);
    void buttonDownMessage();
    void buttonUpMessage();
    SDL_Joystick *js;

};


#endif // JOYSTICK_H
