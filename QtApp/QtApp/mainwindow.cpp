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

    /*
    connect(m_ui->TimerHorizontalSlider, &QSlider::valueChanged,
            this, &MainWindow::changeDataRetrieveTime);
    */
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::on_connectionButton_clicked()
{

}

void MainWindow::on_consoleClearButton_clicked()
{

}


void MainWindow::on_deconnectionButton_clicked()
{

}

void MainWindow::on_plotClearButton_clicked()
{

}


