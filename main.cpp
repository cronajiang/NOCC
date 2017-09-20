#include <QCoreApplication>
#include <QtSerialPort/QtSerialPort>
#include "LIBRARY/POWERDETECT/borlpowdetect.h"
#include "LIBRARY/SERIALCOM/serialcom.h"
#include "LIBRARY/SWITCH/borlsw.h"
#include "LIBRARY/AOTF/borlfianium.h"
#include <QThread>
#include "power_recorder.h"

#include <iostream> // debug
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    SerialCom SERIAL;
    BORLSW SWITCH;
    BORLPOWDETECT ARDUINO;
    BORLFianium AOTF;
    BORLPOWDETECT powerDet;


    SERIAL.SerialFind();  // RUN THIS FIRST BEFORE SETCOMPORT


//    SWITCH.SetCOMPort(SERIAL.SerialSet(1));// DEVICE ID
//    SWITCH.SetCOMPort();// DEVICE ID

    SWITCH.SetChannel(11);

    powerDet.SetCOMPort(SERIAL.SerialSet(2));

    powerDet.ObtainPOW();

     AOTF.BORLFianiumChannel(0);
     AOTF.BORLFianiumFunctn(1);//EXECUTION

     AOTF.BORLFianiumWavelength(650); // 0
     AOTF.BORLFianiumPower(33.33);  // 0
     AOTF.BORLFianiumCntrl();

//    ARDUINO.SetCOMPort(SERIAL.SerialSet(1));


//    for (int i=1; i< 1000; i++)
//    {  powerDet.ObtainPOW();
//       QThread::msleep(200);}
   // create a folder
   // qDebug()<<QDir::currentPath();
   // create a file
   // set recording time


//   power_recorder *pwRecorder = new power_recorder();
//   pwRecorder->set_timer_period(1*1000); //period for repetition ms
//   pwRecorder->set_timer_duration(10*1000);
//   //SWITCH.SetChannel(12); // select channel
//   pwRecorder->recording_start();


//    Z.CurrentChannel();
//    Z.SwFirmware();
//    Z.SwType();
//  Z.SetChannel(12);












    return a.exec();
}
