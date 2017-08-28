#include <QCoreApplication>
#include <QtSerialPort/QtSerialPort>
#include "borlpowdetect.h"
#include "serialcom.h"
#include "borlsw.h"
#include "borlfianium.h"
#include <QThread>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    SerialCom SERIAL;
    BORLSW SWITCH;
    BORLPOWDETECT ARDUINO;
    BORLFianium AOTF;


    SERIAL.SerialFind();


    //SWITCH.SetCOMPort(SERIAL.SerialSet(1));
    ARDUINO.SetCOMPort(SERIAL.SerialSet(1));

    //SWITCH.SetChannel(2);

    AOTF.BORLFianiumChannel(0);
    AOTF.BORLFianiumFunctn(1);

    AOTF.BORLFianiumWavelength(650);
    AOTF.BORLFianiumPower(33.33);
    AOTF.BORLFianiumCntrl();



    for(int i=0;i<15;i++)
    {
    QThread::msleep(5000);
    ARDUINO.ObtainPOW();
    }

//    Z.CurrentChannel();
//    Z.SwFirmware();
//    Z.SwType();
//  Z.SetChannel(12);












    return a.exec();
}
