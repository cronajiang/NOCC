#include <QDebug>
#include <QtCore>
#include "power_recorder.h"
#include <QTime>
power_recorder::power_recorder()
{


}



void power_recorder::MySlot()
{
//    qDebug() << "Timer executed";
    if (time.elapsed() >= timer_duration)
    {
        timer->stop();
    }

    else
        write_to_file();
}

void power_recorder::MyTask()
{
//    qDebug() << "Timer executed";
    if (time.elapsed() >= timer_duration)
    {
        timer->stop();
        if(timer->isActive())
            qDebug() << "timer is still active";
        else
        {
            idxCurr ++;
            if (idxCurr<numOrder)
                 recording_start();
        }
    }

    else
        write_to_file();
}


void power_recorder::set_filename()
{
//    file_name = folderName+"/"+ QDate::currentDate().toString("'data_'yyyy_MM_dd_'") +
//            QTime::currentTime().toString("hhmmss")+".txt";
    file_name = folderName+"/data_"+ QString::number(idxCurr+1)+".txt";
   // qDebug()<<file_name;
}

void power_recorder::get_voltage_fromArduino()
{
    powerDet.ObtainPOW();
    voltage = powerDet.voltage;// debug

}



void power_recorder::write_to_file()
{


    QFile file(file_name);

      get_voltage_fromArduino();
    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {


        QTextStream stream(&file);
//        qint32 voltage;
//        voltage = 1;

        stream << QTime::currentTime().toString("hhmmsszzz");
        stream << '\t';
        stream << voltage;
        stream << "\r\n";
        stream.flush();
        file.close();
//        qDebug()     << "File Written";
    }

}
void power_recorder::read_from_file()
{

}


void power_recorder::set_timer_period(quint16 t)
{
    timer_period = t;
}

void power_recorder::set_timer_duration(quint64 t)
{
    timer_duration = t;
}

void power_recorder::recording_start()
{
    set_filename();


    SWITCH.SetChannel(swChannelOrder[idxCurr]); // select channel

    timer = new QTimer(this);
    //QTime time= QTime::currentTime();
    //startingTime = time.second();

    time.start();
//    connect(timer,SIGNAL(timeout()), this, SLOT(MySlot()));
     connect(timer,SIGNAL(timeout()), this, SLOT(MyTask()));
    //startingTime = QTime.currentTime();
 //   qDebug() << startingTime;

   timer->start(timer_period);

}

void power_recorder::create_folder(QString folder_name) // create a folder under current dir
{
    folderName = folder_name;
    if(!QDir(folder_name).exists())
//        qDebug() << "Error, this folder exists, please rename your folder";
//    else
        QDir().mkdir(folder_name);

}


 void power_recorder::get_swList(QByteArray swlist)
 {
     swChannelOrder = swlist;
     numOrder = swlist.size();
     save_swChannelOrder_to_file();
 }

void power_recorder::save_swChannelOrder_to_file()
{
    QString filename_chOrder = folderName+"/chList.txt";
    QFile file(filename_chOrder);
    int i;
    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {


        QTextStream stream(&file);
//        qint32 voltage;
//        voltage = 1;
        for(i = 0;  i< numOrder; i++)
        {
            stream << QString::number(swChannelOrder[i]);
            stream << '\t';
        }
        file.close();
    }

}
