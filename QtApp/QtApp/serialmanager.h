#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

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
     * @brief serialDataReceived Send when new datas are received.
     * @param data The datas that have been received.
     */
    void serialDataReceived(const QString &data);
    /**
     * @brief connectionIndicator Is the state of the connection change, a signal is send.
     * @param state The new state of the connection.
     */
    void connectionIndicator(bool state);

public slots:

    /**
     * @brief serialReadyRead Read the data from the serial port selected.
     */
    void serialReadyRead();
    void updateSerialPorts();
    void connectToSerial();
    void disconnectSerial();
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
