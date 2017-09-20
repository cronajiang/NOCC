#ifndef POWER_RECORDER_H
#define POWER_RECORDER_H

#include <QtCore>
#include "LIBRARY/POWERDETECT/borlpowdetect.h"

#include "LIBRARY/SERIALCOM/serialcom.h"
#include "LIBRARY/SWITCH/borlsw.h"
class power_recorder: public QObject
{
    Q_OBJECT

public:
    power_recorder();
    void get_voltage_fromArduino();

    QTimer *timer;
    QTime time;
    int startingTime;

    void create_folder(QString);
    void recording_start();
    void recording_end();
    void set_filename();
    void set_timer_period(quint16);
    void set_timer_duration(quint64);

    QByteArray voltage;
    QString folderName;

    BORLPOWDETECT powerDet;
    SerialCom SERIAL;
    BORLSW SWITCH;

    quint8 numOrder;
    QByteArray swChannelOrder; //debug, later get values from main
    quint8 idxCurr = 0;
    void get_swList(QByteArray);
    void save_swChannelOrder_to_file();
public slots:
    void MySlot();
    void write_to_file();
    void read_from_file();
    void MyTask();

private:

    QFile file;
    QString file_name;

    quint16 timer_period;
    quint64 timer_duration;


};

#endif // POWER_RECORDER_H
