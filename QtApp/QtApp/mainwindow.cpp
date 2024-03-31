#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_dataManager(nullptr),
    m_plotManager(nullptr),
    m_serialManager(nullptr),
    m_uiManager(nullptr)
{
    m_ui->setupUi(this);
    this->setWindowTitle("Environnement Reader");

    m_dataManager = new DataManager();
    m_plotManager = new PlotManager(m_ui, font());
    m_serialManager = new SerialManager(m_ui);
    m_uiManager = new UiManager(m_ui);


    /**----- Connect DataManager Signals -----**/

    // When a new line of data is process, we add this line to the console.
    connect(m_dataManager, &DataManager::dataLine,
            m_uiManager, &UiManager::updateConsole);

    // When new environnement datas are read, we add them to the plots.
    connect(m_dataManager, &DataManager::newDatas,
            m_plotManager, &PlotManager::addDataPoint);

    // When new environnement datas are read, we update the Ui.
    connect(m_dataManager, &DataManager::newDatas,
            m_uiManager, &UiManager::updateEnvironnementValues);

    /**----- Connect PlotManager Signals -----**/

    // When the plot are cleared, we set the time back to 0.
    connect(m_plotManager, &PlotManager::restartTime,
            m_dataManager, &DataManager::setTime);

    /**----- Connect SerialManager Signals -----**/

    // When we have new datas on the serial port, we send them to the dataManager.
    connect(m_serialManager, &SerialManager::serialDataReceived,
            m_dataManager, &DataManager::processDatas);

    // When we connect or disconnect from a serial port, we update the connection indicator.
    connect(m_serialManager, &SerialManager::connectionIndicator,
            m_uiManager, &UiManager::updateConnectionIndicator);

    /**----- Connect UiManager Signals -----**/

    // When the slider for the timer change, we change the time between two scan on the serial port.
    connect(m_uiManager, &UiManager::newSliderTimerValue,
            m_serialManager, &SerialManager::changeDataScanTimer);

    // When the slider for the timer change, we change the time interval in the data manager.
    connect(m_uiManager, &UiManager::newSliderTimerValue,
            m_dataManager, &DataManager::setTimeInterval);

    /**----- Connect MainWindow Signals -----**/

    // When the clear plot button is clicked, we clear the plots.
    connect(this, &MainWindow::plotClearButton_clicked,
            m_plotManager, &PlotManager::clearPlots);

    // When the clear plot button is clicked, we clear the environnement values in the Uis.
    connect(this, &MainWindow::plotClearButton_clicked,
            m_uiManager, &UiManager::clearEnvironnementValues);

    // When the connection button is clicked, we try to connect to the selected serial port.
    connect(this, &MainWindow::connectionButton_clicked,
            m_serialManager, &SerialManager::connectToSerial);

    // When the deconnection button is clicked, we disconnect from the connected serial port.
    connect(this, &MainWindow::deconnectionButton_clicked,
            m_serialManager, &SerialManager::disconnectSerial);

    // When the console clear button is clicked, we clear the console.
    connect(this, &MainWindow::consoleClearButton_clicked,
            m_uiManager, &UiManager::clearConsole);
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_dataManager;
    delete m_plotManager;
    delete m_serialManager;
    delete m_uiManager;
}

void MainWindow::on_connectionButton_clicked()
{
    emit connectionButton_clicked();
}

void MainWindow::on_deconnectionButton_clicked()
{
    emit deconnectionButton_clicked();
}

void MainWindow::on_consoleClearButton_clicked()
{
    emit consoleClearButton_clicked();
}

void MainWindow::on_plotClearButton_clicked()
{
    emit plotClearButton_clicked();
}


