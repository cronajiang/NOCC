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


//    SerialCom SERIAL;
//    BORLSW SWITCH;
    BORLFianium AOTF;
//    BORLPOWDETECT powerDet;
    power_recorder *pwRecorder = new power_recorder();



//    /* set laser and AOTF */
//    AOTF.BORLFianiumChannel(0);
//    AOTF.BORLFianiumFunctn(1);//EXECUTION

//    AOTF.BORLFianiumWavelength(650); // 0
//    AOTF.BORLFianiumPower(33.33);  // 0
//    AOTF.BORLFianiumCntrl();


    //SERIAL.SerialFindDebug();  // RUN THIS FIRST BEFORE SETCOMPORT




    /* obtain power before switch */
//     powerDet.ObtainPOW();

//   /* create a folder */
    QString projectName = "beforeSW";
    pwRecorder->create_folder(projectName+"_test2");
//  // qDebug()<<QDir::currentPath();


    /* set SWITCH */
    //Quint8 numChannel = 12*3;
    QByteArray swChannelOrder;
//    for(int ii = 0; ii<12; ii++)
//    swChannelOrder[ii] =ii+1;
//    for(int ii = 0; ii<12; ii++)
//    swChannelOrder[ii+12] =ii+1;
//    for(int ii = 0; ii<12; ii++)
//    swChannelOrder[ii+24] =ii+1;
    swChannelOrder[0] = 11;
    swChannelOrder[1] = 1;
    swChannelOrder[2] = 11;
    swChannelOrder[3] = 5;
    swChannelOrder[4] = 11;
    swChannelOrder[5] = 12;
    swChannelOrder[6] = 11;

//    {11 , 12,  11};
//    "",8, 11,  5, 11, 1,11];

//   /* set recording time */
    pwRecorder->get_swList(swChannelOrder);
   pwRecorder->set_timer_period(0.500*1000); //period for repetition [ms]
   pwRecorder->set_timer_duration(10*60*1000); // [ms]
//   SWITCH.SetChannel(11); // select channel
   pwRecorder->recording_start();


//        for (int i=1; i< 50; i++)
//        {  powerDet.ObtainPOW();
//           QThread::msleep(200);}  //debug for powerDet


//    Z.CurrentChannel();
//    Z.SwFirmware();
//    Z.SwType();
//  Z.SetChannel(12);
    return a.exec();
}
