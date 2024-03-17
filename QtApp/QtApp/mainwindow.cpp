#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_connectedPort(false),
    m_canRead(false),
    m_consoleScrollBarCanMove(true),
    m_time(0),
    m_temperature(0.0),
    m_humidity(0.0),
    m_pressure(0.0)

{
    m_ui->setupUi(this);
    this->setWindowTitle("Environnement Reader");

    // Set the first tab to be display when the app is launch.
    m_ui->tabWidget->setCurrentIndex(0);

    // Init of the serial port.
    m_Serial = new QSerialPort(this);
    updateSerialPorts();

    // Init of the timers.
    m_SerialScanTimer = new QTimer(this);
    m_SerialScanTimer->setInterval(5000);
    m_SerialScanTimer->start();

    int intervalDataScan = m_ui->TimerHorizontalSlider->value() * 1000;
    m_timeInterval = intervalDataScan / 1000;

    m_DataScanTimer = new QTimer(this);
    m_DataScanTimer->setInterval(intervalDataScan);
    m_DataScanTimer->start();

    // ReadOnly is working weird, maybe add someting else.
    m_ui->ConsoleTextBrowser->setReadOnly(true);

    // Set the border color of the comboxBox in red.
    deconnectionDoneIndicator();

    // Setup the plot.
    m_dataTemperature   = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);
    m_dataHumidity      = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);
    m_dataPressure      = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);

    QFont legendFont = font();
    legendFont.setPointSize(10);
    QString timeLabel = "Temps (s)";

    // Init plot for the Temperature.
    m_ui->plotTemperatureWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    m_ui->plotTemperatureWidget->legend->setVisible(true);
    m_ui->plotTemperatureWidget->legend->setFont(legendFont);
    m_ui->plotTemperatureWidget->legend->setSelectedFont(legendFont);
    m_ui->plotTemperatureWidget->legend->setSelectableParts(QCPLegend::spItems);
    m_ui->plotTemperatureWidget->yAxis->setLabel("Température");
    m_ui->plotTemperatureWidget->xAxis->setLabel(timeLabel);
    m_ui->plotTemperatureWidget->clearGraphs();

    m_ui->plotTemperatureWidget->addGraph();
    m_ui->plotTemperatureWidget->graph()->setPen(QPen(Qt::black));
    m_ui->plotTemperatureWidget->graph()->setData(m_dataTemperature);
    m_ui->plotTemperatureWidget->graph()->setName("Température");

    // Init plot for the Humidity.
    m_ui->plotHumidityWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    m_ui->plotHumidityWidget->legend->setVisible(true);
    m_ui->plotHumidityWidget->legend->setFont(legendFont);
    m_ui->plotHumidityWidget->legend->setSelectedFont(legendFont);
    m_ui->plotHumidityWidget->legend->setSelectableParts(QCPLegend::spItems);
    m_ui->plotHumidityWidget->yAxis->setLabel("Humidité");
    m_ui->plotHumidityWidget->xAxis->setLabel(timeLabel);
    m_ui->plotHumidityWidget->clearGraphs();

    m_ui->plotHumidityWidget->addGraph();
    m_ui->plotHumidityWidget->graph()->setPen(QPen(Qt::red));
    m_ui->plotHumidityWidget->graph()->setData(m_dataHumidity);
    m_ui->plotHumidityWidget->graph()->setName("Humidité");

    // Init plot for the Pressure.
    m_ui->plotPressureWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    m_ui->plotPressureWidget->legend->setVisible(true);
    m_ui->plotPressureWidget->legend->setFont(legendFont);
    m_ui->plotPressureWidget->legend->setSelectedFont(legendFont);
    m_ui->plotPressureWidget->legend->setSelectableParts(QCPLegend::spItems);
    m_ui->plotPressureWidget->yAxis->setLabel("Pression");
    m_ui->plotPressureWidget->xAxis->setLabel(timeLabel);
    m_ui->plotPressureWidget->clearGraphs();

    m_ui->plotPressureWidget->addGraph();
    m_ui->plotPressureWidget->graph()->setPen(QPen(Qt::blue));
    m_ui->plotPressureWidget->graph()->setData(m_dataPressure);
    m_ui->plotPressureWidget->graph()->setName("Pression");


    // Add tick names for the slider.
    QHBoxLayout *sliderLabelsTickLayout = new QHBoxLayout;

    int sliderMin = m_ui->TimerHorizontalSlider->minimum();
    int sliderMax = m_ui->TimerHorizontalSlider->maximum();

    for (int i = sliderMin; i <= sliderMax; ++i) {
        QLabel *label = new QLabel(QString::number(i));
        sliderLabelsTickLayout->addWidget(label);
    }
    m_ui->sliderVerticalLayout->addLayout(sliderLabelsTickLayout);


    // If the timer have finish then we update the ports.
    connect(m_SerialScanTimer, &QTimer::timeout,
            this, &MainWindow::updateSerialPorts);

    // If the timer have finish then we update the datas.
    connect(m_DataScanTimer, &QTimer::timeout,
            this, &MainWindow::updateData);

    // If the serial port is ready to be read, we read it.
    connect(m_Serial, &QSerialPort::readyRead,
            this, &MainWindow::serialReadyRead);

    // If the scroll bar of the console is change by the user, we handle it.
    connect(m_ui->ConsoleTextBrowser->verticalScrollBar(), &QScrollBar::actionTriggered,
            this, &MainWindow::handleConsoleScrollBar);

    connect(m_ui->TimerHorizontalSlider, &QSlider::valueChanged,
            this, &MainWindow::changeDataRetrieveTime);
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_Serial;
    delete m_SerialScanTimer;
    delete m_DataScanTimer;
}

void MainWindow::updateSerialPorts()
{
    // Put all the ports in the list of ports.
    m_SerialPorts = QSerialPortInfo::availablePorts();

    // Add all the ports list to the comboBox.
    m_ui->connectionComboBox->clear();
    for (QSerialPortInfo port : m_SerialPorts) {
        m_ui->connectionComboBox->addItem(port.portName(), port.systemLocation());
    }
}

void MainWindow::on_connectionButton_clicked()
{
    // Desactivation of the button of connection.
    m_ui->connectionButton->setEnabled(false);
    QString serialLoc = m_ui->connectionComboBox->currentData().toString();

    // If the serial port is connected, we disconnect it.
    if (m_Serial->isOpen()) {
        qDebug() << "Serial already connected, disconnecting!";
        m_connectedPort = false;
        m_Serial->close();
        deconnectionDoneIndicator();
    }

    m_Serial->setPortName(serialLoc);
    m_Serial->setBaudRate(QSerialPort::Baud115200);
    m_Serial->setDataBits(QSerialPort::Data8);
    m_Serial->setParity(QSerialPort::NoParity);
    m_Serial->setStopBits(QSerialPort::OneStop);
    m_Serial->setFlowControl(QSerialPort::NoFlowControl);

    if(m_Serial->open(QIODevice::ReadWrite)) {
        qDebug() << "SERIAL: OK!";
        serialLoc = serialLoc.remove(0, 4);
        m_ui->consoleLabel->setText(serialLoc);
        m_connectedPort = true;
        connectionDoneIndicator();
    } else {
        qDebug() << "SERIAL: ERROR!";
    }
    // Activation of the button of connection.
    m_ui->connectionButton->setEnabled(true);
}

void MainWindow::serialReadyRead()
{
    // If we are read to read on the serial port.
    m_canRead = true;
}

void MainWindow::updateData()
{
    // If the serial port is connected and we can read.
    if(m_connectedPort && m_canRead)
    {
        // We read on the serial port all the data.
        QString line = m_Serial->readAll();

        // We split the string into multiple lines.
        QStringList lines = line.split( "\r\n" );
        for(QString l : lines){
            if(l != ""){
                // We print all the lines in the console.
                m_ui->ConsoleTextBrowser->insertPlainText(l + "\n");

                // If we can move the scroll bar then we put it at the end.
                if(m_consoleScrollBarCanMove){
                    QScrollBar *sb = m_ui->ConsoleTextBrowser->verticalScrollBar();
                    sb->setValue(sb->maximum());
                }

                // We take our data that we need.
                if(l.startsWith("temperature :")){
                    QStringList temperature = l.split(':');
                    if(temperature.length() == 2 && !temperature[1].isEmpty()){
                        m_ui->temperatureDisplay->setText(temperature[1]);
                        m_temperature = temperature[1].toFloat();
                    }
                }
                else if(l.startsWith("humidity :")){
                    QStringList humidity = l.split(':');
                    if(humidity.length() == 2 && !humidity[1].isEmpty()){
                        m_ui->humididyDisplay->setText(humidity[1]);
                        m_humidity = humidity[1].toFloat();
                    }
                }
                else if(l.startsWith("pressure :")){
                    QStringList pressure = l.split(':');
                    if(pressure.length() == 2 && !pressure[1].isEmpty()){
                        m_ui->pressureDisplay->setText(pressure[1]);
                        m_pressure = pressure[1].toFloat();
                    }
                }
            }
        }
        // When the reading is finish, we can add the points to the plot.
        m_dataTemperature->add(QCPGraphData(m_time, m_temperature));
        m_dataHumidity->add(QCPGraphData(m_time, m_humidity));
        m_dataPressure->add(QCPGraphData(m_time, m_pressure));

        // Update the plots.
        m_ui->plotTemperatureWidget->rescaleAxes();
        m_ui->plotTemperatureWidget->replot();
        m_ui->plotHumidityWidget->rescaleAxes();
        m_ui->plotHumidityWidget->replot();
        m_ui->plotPressureWidget->rescaleAxes();
        m_ui->plotPressureWidget->replot();

        // We increase the time by 1.
        m_time += m_timeInterval;
        m_canRead = false;
    }
}

void MainWindow::on_consoleClearButton_clicked()
{
    m_ui->ConsoleTextBrowser->clear();
}


void MainWindow::on_deconnectionButton_clicked()
{
    if (m_Serial->isOpen()) {
        qDebug() << "SERIAL: DECONNECTED!";
        m_connectedPort = false;
        m_Serial->close();
        deconnectionDoneIndicator();
    }
}

void MainWindow::handleConsoleScrollBar()
{
    QScrollBar *sb = m_ui->ConsoleTextBrowser->verticalScrollBar();
    int max = sb->maximum();
    int value = sb->value();
    // If the scroll bar is near the end, then the program can move it.
    if(value >= (max - (max * 0.1))){
        m_consoleScrollBarCanMove = true;
    }
    else{
        m_consoleScrollBarCanMove = false;
    }
}

void MainWindow::connectionDoneIndicator()
{
    // Background to green.
    m_ui->connectionIndicator->setStyleSheet("QWidget { background-color: rgb(124,252,0); border-radius: 10px; }");
}

void MainWindow::deconnectionDoneIndicator()
{
    // Background to red.
    m_ui->connectionIndicator->setStyleSheet("QWidget { background-color: rgb(255,160,122); border-radius: 10px; }");
}


void MainWindow::on_plotClearButton_clicked()
{
    // We clear all the points.
    m_dataTemperature->clear();
    m_dataHumidity->clear();
    m_dataPressure->clear();

    // We reset the graphs.
    m_ui->plotTemperatureWidget->rescaleAxes();
    m_ui->plotTemperatureWidget->replot();
    m_ui->plotHumidityWidget->rescaleAxes();
    m_ui->plotHumidityWidget->replot();
    m_ui->plotPressureWidget->rescaleAxes();
    m_ui->plotPressureWidget->replot();
}

void MainWindow::changeDataRetrieveTime()
{
    int interval = m_ui->TimerHorizontalSlider->value() * 1000;
    m_timeInterval = interval / 1000;
    m_DataScanTimer->setInterval(interval);
}

