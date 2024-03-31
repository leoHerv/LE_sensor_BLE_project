#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QSerialPort>
#include <QSerialPortInfo>

#include "../mainInclude.h"

/** Declared in the ui_mainwindow.h file **/
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class SerialManager : public QObject
{
    Q_OBJECT
public:
    SerialManager(Ui::MainWindow *ui);
    ~SerialManager();

signals:
    /**
     * @brief serialDataReceived Triggered when new datas are received from the serial port.
     * @param data The datas that have been received.
     */
    void serialDataReceived(const QString &data);
    /**
     * @brief connectionIndicator Triggered when the connection state change.
     * @param state The new state of the connection.
     */
    void connectionIndicator(bool state);

public slots:

    /**
     * @brief serialReadyRead Tell if we can read or not on the selected serial port.
     */
    void serialReadyRead();
    /**
     * @brief updateSerialPorts Update the serial ports available.
     */
    void updateSerialPorts();
    /**
     * @brief connectToSerial Try to connect to the selected serial port.
     */
    void connectToSerial();
    /**
     * @brief disconnectSerial Disconnect from the conencted serial port.
     */
    void disconnectSerial();
    /**
     * @brief readSerialData Read all the data from the selected serial port.
     */
    void readSerialData();
    /**
     * @brief changeDataScanTimer Change the interval between two data read.
     * @param intervalTime The interval of time in seconds.
     */
    void changeDataScanTimer(int intervalTime);

private:
    /**
     * @brief m_ui The user interface (.ui) that have all the buttons, etc ...
     */
    Ui::MainWindow* m_ui;

    /**
     * @brief m_Serial The serial port that we use to read our environnement data.
     */
    QSerialPort* m_serial;
    /**
     * @brief m_SerialPorts The list of serial ports available.
     */
    QList<QSerialPortInfo> m_serialPorts;
    /**
     * @brief m_SerialScanTimer The timer use to know when we need to check for new serial ports.
     */
    QTimer* m_serialScanTimer;
    /**
     * @brief m_DataScanTimer The timer use to know when we need to check new data on the serial port.
     */
    QTimer* m_dataScanTimer;
    /**
     * @brief connectedPort Tell if a port is connected or not.
     */
    bool m_connectedPort;
    /**
     * @brief m_canRead Tell if we can read on the port or not.
     */
    bool m_canRead;
};

#endif // SERIALMANAGER_H
