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
    BORLFianium AOTF;
    BORLPOWDETECT powerDet;
    power_recorder *pwRecorder = new power_recorder();

    /* set laser and AOTF */
    AOTF.BORLFianiumChannel(0);
    AOTF.BORLFianiumFunctn(1);//EXECUTION

    AOTF.BORLFianiumWavelength(650); // 0
    AOTF.BORLFianiumPower(33.33);  // 0
    AOTF.BORLFianiumCntrl();

//     SERIAL.SerialFindDebug();  // RUN THIS FIRST BEFORE SETCOMPORT


    /* set SWITCH */
    SWITCH.SetChannel(11);

    /* obtain power before switch */
     powerDet.ObtainPOW();

//   /* create a folder */
//    pwRecorder->create_folder("session_1");
//   // qDebug()<<QDir::currentPath();

//   /* set recording time */
//   pwRecorder->set_timer_period(1*1000); //period for repetition ms
//   pwRecorder->set_timer_duration(10*1000);
//   //SWITCH.SetChannel(12); // select channel
//   pwRecorder->recording_start();


    //    for (int i=1; i< 1000; i++)
    //    {  powerDet.ObtainPOW();
    //       QThread::msleep(200);}  //debug for powerDet


//    Z.CurrentChannel();
//    Z.SwFirmware();
//    Z.SwType();
//  Z.SetChannel(12);
    return a.exec();
}
