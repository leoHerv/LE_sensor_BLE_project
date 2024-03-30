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
    void dataLine(const QString line);
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
     * @brief m_time The time for the plot in secondes.
     */
    int m_time;
    /**
     * @brief m_timeInterval The time between each graph update in secondes.
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
