#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QScrollBar>
#include <QtPrintSupport>

#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief serialReadyRead Read the data from the serial port selected.
     */
    void serialReadyRead();
    /**
     * @brief on_connectionButton_clicked Try to connect with a serial port when the "connectionButton" is clicked.
     */
    void on_connectionButton_clicked();
    /**
     * @brief on_consoleClearButton_clicked Clear the console.
     */
    void on_consoleClearButton_clicked();
    /**
     * @brief on_deconnectionButton_clicked Deconnect the serial port.
     */
    void on_deconnectionButton_clicked();

private:
    /**
     * @brief m_ui The user interface (.ui) that have all the buttons, etc ...
     */
    Ui::MainWindow *m_ui;

    /**
     * @brief m_Serial The serial port that we use to read our environnement data.
     */
    QSerialPort *m_Serial;
    /**
     * @brief m_SerialPorts The list of serial ports available.
     */
    QList<QSerialPortInfo> m_SerialPorts;
    /**
     * @brief m_SerialScanTimer The timer use to say when we need to check for new serial ports.
     */
    QTimer *m_SerialScanTimer;
    /**
     * @brief m_DataScanTimer The timer use to say when we need to check new data on the serial port.
     */
    QTimer *m_DataScanTimer;
    /**
     * @brief connectedPort Tell if a port is connected or not.
     */
    bool m_connectedPort;
    /**
     * @brief m_canRead Tell if we can read on the port or not.
     */
    bool m_canRead;
    /**
     * @brief m_consoleScrollBarCanMove Tell if we can move the scroll bar or not.
     */
    bool m_consoleScrollBarCanMove;

    QSharedPointer<QCPGraphDataContainer> mData;


    /**
     * @brief updateSerialPorts Update the serial ports list and the comboBox.
     */
    void updateSerialPorts();

    /**
     * @brief updateData Update the datas (temperature, humidity and pressure).
     */
    void updateData();
    /**
     * @brief handleConsoleScrollBar If the scroll bar is used by the user then we do not
     * change the position of it.
     */
    void handleConsoleScrollBar();
    /**
     * @brief connectionDoneIndicator Make the background color of the indicator green.
     */
    void connectionDoneIndicator();
    /**
     * @brief deconnectionDoneIndicator Make the background color of the indicator red.
     */
    void deconnectionDoneIndicator();
};
#endif // MAINWINDOW_H
