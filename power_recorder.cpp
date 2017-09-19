#include <QDebug>
#include <QtCore>
#include "power_recorder.h"
#include <QTime>
power_recorder::power_recorder()
{

     //timer->start(1000);

}



void power_recorder::MySlot()
{
    qDebug() << "Timer executed";
    if (time.elapsed() >= timer_duration)
        timer->stop();
    else
        write_to_file();
}


void power_recorder::set_filename()
{
    file_name = QDate::currentDate().toString("'data_'yyyy_MM_dd_'") +
            QTime::currentTime().toString("hhmmss")+".txt";
   // qDebug()<<file_name;
}

void power_recorder::get_voltage_fromArduino()
{
    voltage = 1;// debug

}



void power_recorder::write_to_file()
{

    QFile file(file_name);

    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream stream(&file);
        qint32 voltage;
        voltage = 1;
        stream << QTime::currentTime().toString("hhmmss");
        stream << ',';
        stream << voltage;
        stream << "\r\n";
//        stream << "Hello\r\n";
//        stream << "World\r\n";

        stream.flush();
        file.close();
        qDebug()     << "File Written";
    }

}
void power_recorder::read_from_file()
{

}


void power_recorder::set_timer_period(quint16 t)
{
    timer_period = t;
}

void power_recorder::set_timer_duration(quint16 t)
{
    timer_duration = t;
}

void power_recorder::recording_start()
{
    set_filename();


    timer = new QTimer(this);
    //QTime time= QTime::currentTime();
    //startingTime = time.second();

    time.start();
    connect(timer,SIGNAL(timeout()), this, SLOT(MySlot()));
    //startingTime = QTime.currentTime();
    qDebug() << startingTime;

   timer->start(timer_period);

}

void power_recorder::create_folder() // create a folder under current dir
{

}

