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

    // When we have new datas on the serial port, we send them to the dataManager.
    connect(m_serialManager, &SerialManager::serialDataReceived,
            m_dataManager, &DataManager::processDatas);

    connect(m_plotManager, &PlotManager::restartTimer,
            m_dataManager, &DataManager::setTime);

    connect(this, &MainWindow::connectionButton_clicked,
            m_serialManager, &SerialManager::connectToSerial);

    connect(this, &MainWindow::consoleClearButton_clicked,
            m_uiManager, &UiManager::clearConsole);

    connect(this, &MainWindow::deconnectionButton_clicked,
            m_serialManager, &SerialManager::disconnectSerial);

    connect(this, &MainWindow::plotClearButton_clicked,
            m_plotManager, &PlotManager::clearPlots);

    connect(m_serialManager, &SerialManager::connectionIndicator,
            m_uiManager, &UiManager::updateConnectionIndicator);

    connect(m_serialManager, &SerialManager::serialDataReceived,
            m_dataManager, &DataManager::processDatas);

    connect(m_dataManager, &DataManager::dataLine,
            m_uiManager, &UiManager::updateConsole);

    connect(m_dataManager, &DataManager::newDatas,
            m_plotManager, &PlotManager::addDataPoint);

    connect(m_dataManager, &DataManager::newDatas,
            m_uiManager, &UiManager::updateEnvironnementValues);

    connect(m_uiManager, &UiManager::newSliderTimerValue,
            m_serialManager, &SerialManager::changeDataScanTimer);

    connect(m_uiManager, &UiManager::newSliderTimerValue,
            m_dataManager, &DataManager::setTimeInterval);

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

void MainWindow::on_consoleClearButton_clicked()
{
    emit consoleClearButton_clicked();
}


void MainWindow::on_deconnectionButton_clicked()
{
    emit deconnectionButton_clicked();
}

void MainWindow::on_plotClearButton_clicked()
{
    emit plotClearButton_clicked();
}


