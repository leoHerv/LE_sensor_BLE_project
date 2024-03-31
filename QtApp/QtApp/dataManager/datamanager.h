#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QMainWindow>

class DataManager : public QObject
{
    Q_OBJECT
public:
    DataManager();
    ~DataManager();

signals:
    /**
     * @brief dataLine Triggered when a new data line is process.
     * @param line The data line that we have process.
     */
    void dataLine(const QString line);
    /**
     * @brief newDatas Triggered when new environnement values are read.
     * @param temperature The new temperature value.
     * @param humidity The new humidity value.
     * @param pressure The new pressure value.
     * @param time The new time value.
     */
    void newDatas(float temperature, float humidity, float pressure, int time);

public slots:

    /**
     * @brief setTime Set the m_time value with new 'time'.
     * @param time The new time value.
     */
    void setTime(int time);
    /**
     * @brief setTimeInterval Set the m_timeInterval value with the new 'timeInterval'.
     * @param timeInterval The new time interval value.
     */
    void setTimeInterval(int timeInterval);
    /**
     * @brief processDatas Process the datas of the passed string.
     * @param datas The datas to process.
     */
    void processDatas(const QString datas);

private:
    /**
     * @brief m_time The time in secondes.
     */
    int m_time;
    /**
     * @brief m_timeInterval The interval in secondes to add to the time.
     */
    int m_timeInterval;
    /**
     * @brief m_temperature The current temperature.
     */
    float m_temperature;
    /**
     * @brief m_humidity The current humidity.
     */
    float m_humidity;
    /**
     * @brief m_pressure The current pressure.
     */
    float m_pressure;
};

#endif // DATAMANAGER_H
