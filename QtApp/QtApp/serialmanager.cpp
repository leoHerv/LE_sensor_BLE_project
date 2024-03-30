#include "serialmanager.h"
#include "ui_mainwindow.h"

SerialManager::SerialManager(Ui::MainWindow *ui) :
    QObject(nullptr),
    m_ui(ui),
    m_serial(new QSerialPort()),
    m_connectedPort(false),
    m_canRead(false)
{
    // Init of the serial port.
    m_serial = new QSerialPort(this);
    updateSerialPorts();

    // Init of the timers.
    m_serialScanTimer = new QTimer(this);
    m_serialScanTimer->setInterval(5000);
    m_serialScanTimer->start();

    m_dataScanTimer = new QTimer(this);
    m_dataScanTimer->setInterval(5000);
    m_dataScanTimer->start();

    // If the serial port is ready to be read, we read it.
    connect(m_serial, &QSerialPort::readyRead,
            this, &SerialManager::serialReadyRead);

    // If the timer have finish then we update the ports.
    connect(m_serialScanTimer, &QTimer::timeout,
            this, &SerialManager::updateSerialPorts);

    // If the timer have finish then we read the datas.
    connect(m_dataScanTimer, &QTimer::timeout,
            this, &SerialManager::readSerialData);
}

SerialManager::~SerialManager()
{
    delete m_serial;
    delete m_serialScanTimer;
    delete m_dataScanTimer;
}

void SerialManager::serialReadyRead()
{
    // If we are read to read on the serial port.
    m_canRead = true;
}

void SerialManager::updateSerialPorts() {
    // Put all the ports in the list of ports.
    m_serialPorts = QSerialPortInfo::availablePorts();

    // Add all the ports list to the comboBox.
    m_ui->connectionComboBox->clear();
    for (QSerialPortInfo port : m_serialPorts) {
        m_ui->connectionComboBox->addItem(port.portName(), port.systemLocation());
    }
}

void SerialManager::connectToSerial(const QString &portName) {
    // Desactivation of the button of connection.
    m_ui->connectionButton->setEnabled(false);
    QString serialLoc = m_ui->connectionComboBox->currentData().toString();

    // If the serial port is connected, we disconnect it.
    if (m_serial->isOpen()) {
        qDebug() << "Serial already connected, disconnecting!";
        m_connectedPort = false;
        m_serial->close();
        emit connectionIndicator(false);
    }

    m_serial->setPortName(serialLoc);
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    if(m_serial->open(QIODevice::ReadWrite)) {
        qDebug() << "SERIAL: OK!";
        serialLoc = serialLoc.remove(0, 4);
        m_ui->consoleLabel->setText(serialLoc);
        m_connectedPort = true;    
        emit connectionIndicator(true);
    } else {
        qDebug() << "SERIAL: ERROR!";
    }
    // Activation of the button of connection.
    m_ui->connectionButton->setEnabled(true);
}

void SerialManager::disconnectSerial() {
    if (m_serial->isOpen()) {
        qDebug() << "SERIAL: DECONNECTED!";
        m_connectedPort = false;
        m_serial->close();
        emit connectionIndicator(false);
    }
}

void SerialManager::readSerialData()
{
    // If the serial port is connected and we can read.
    if(m_connectedPort && m_canRead)
    {
        // We read on the serial port all the data.
        QString line = m_serial->readAll();

        emit serialDataReceived(line);

        m_canRead = false;
    }
}

void SerialManager::changeDataScanTimer(int intervalTime)
{
    m_dataScanTimer->setInterval(intervalTime * 1000);
}









