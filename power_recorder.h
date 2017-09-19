#ifndef POWER_RECORDER_H
#define POWER_RECORDER_H

 #include <QtCore>
 #include "LIBRARY/POWERDETECT/borlpowdetect.h"
class power_recorder: public QObject
{
    Q_OBJECT

public:
    power_recorder();
    void get_voltage_fromArduino();

    QTimer *timer;
    QTime time;
    int startingTime;

    void create_folder();
    void recording_start();
    void recording_end();
    void set_filename();
    void set_timer_period(quint16);
    void set_timer_duration(quint16);

    BORLPOWDETECT powerDet;
     qint16 voltage;

public slots:
    void MySlot();
    void write_to_file();
    void read_from_file();

private:

    QFile file;
    QString file_name;

    quint16 timer_period;
    quint16 timer_duration;


};

#endif // POWER_RECORDER_H
