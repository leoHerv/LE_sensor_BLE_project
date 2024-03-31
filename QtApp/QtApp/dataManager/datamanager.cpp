#include "datamanager.h"

DataManager::DataManager() :
    QObject(nullptr),
    m_time(0),
    m_timeInterval(5),
    m_temperature(0.0),
    m_humidity(0.0),
    m_pressure(0.0)
{}

DataManager::~DataManager() {}

void DataManager::setTime(int time)
{
    m_time = time;
}

void DataManager::setTimeInterval(int timeInterval)
{
    m_timeInterval = timeInterval;
}

void DataManager::processDatas(const QString datas)
{
    // We split the string into multiple lines.
    QStringList lines = datas.split( "\r\n" );
    for(QString l : lines){
        if(l != ""){

            emit dataLine(l);

            // We take our data that we need.
            if(l.startsWith("temperature :")){
                QStringList temperature = l.split(':');
                if(temperature.length() == 2 && !temperature[1].isEmpty()){
                    m_temperature = temperature[1].toFloat();
                }
            }
            else if(l.startsWith("humidity :")){
                QStringList humidity = l.split(':');
                if(humidity.length() == 2 && !humidity[1].isEmpty()){
                    m_humidity = humidity[1].toFloat();
                }
            }
            else if(l.startsWith("pressure :")){
                QStringList pressure = l.split(':');
                if(pressure.length() == 2 && !pressure[1].isEmpty()){
                    m_pressure = pressure[1].toFloat();
                }
            }
        }
    }
    emit newDatas(m_temperature, m_humidity, m_pressure, m_time);

    m_time += m_timeInterval;
}

