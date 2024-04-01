#include "uimanager.h"

UiManager::UiManager(Ui::MainWindow *ui) :
    QObject(nullptr),
    m_ui(ui),
    m_consoleScrollBarCanMove(true)
{
    // Set the first tab to be display when the app is launch.
    m_ui->tabWidget->setCurrentIndex(0);

    // ReadOnly is working weird, maybe add someting else.
    m_ui->ConsoleTextBrowser->setReadOnly(true);

    // Not serial port connected.
    updateConnectionIndicator(false);

    // Add tick labels for the slider.
    QHBoxLayout *sliderLabelsTickLayout = new QHBoxLayout;

    int sliderMin = m_ui->TimerHorizontalSlider->minimum();
    int sliderMax = m_ui->TimerHorizontalSlider->maximum();

    for (int i = sliderMin; i <= sliderMax; ++i) {
        QLabel *label = new QLabel(QString::number(i));
        sliderLabelsTickLayout->addWidget(label);
    }
    m_ui->sliderVerticalLayout->addLayout(sliderLabelsTickLayout);

    // If the scroll bar of the console is change by the user, we handle it.
    connect(m_ui->ConsoleTextBrowser->verticalScrollBar(), &QScrollBar::actionTriggered,
            this, &UiManager::handleConsoleScrollBar);

    // If the slider change of value, we trigger a signal.
    connect(m_ui->TimerHorizontalSlider, &QSlider::valueChanged,
            this, &UiManager::updateSliderTimerValue);
}

UiManager::~UiManager() {}


void UiManager::updateConsole(const QString line) {
    m_ui->ConsoleTextBrowser->insertPlainText(line + "\n");

    // If we can move the scroll bar then we put it at the end.
    if(m_consoleScrollBarCanMove){
        QScrollBar *sb = m_ui->ConsoleTextBrowser->verticalScrollBar();
        sb->setValue(sb->maximum());
    }
}

void UiManager::clearConsole()
{
    m_ui->ConsoleTextBrowser->clear();
}

void UiManager::updateEnvironnementValues(float temperature, float humidity, float pressure, int time)
{
    updateTemperature(temperature);
    updateHumidity(humidity);
    updatePressure(pressure);
}

void UiManager::updateTemperature(float temperature) {
    m_ui->temperatureDisplay->setText(QString::number(temperature) + " °C");
}

void UiManager::updateHumidity(float humidity) {
    m_ui->humididyDisplay->setText(QString::number(humidity) + " %");
}

void UiManager::updatePressure(float pressure) {
    m_ui->pressureDisplay->setText(QString::number(pressure) + " hPa");
}

void UiManager::updateConnectionIndicator(bool connected) {
    if(connected){
        // Background to green.
        m_ui->connectionIndicator->setStyleSheet("QWidget { background-color: rgb(124,252,0); border-radius: 10px; }");
    }
    else{
        // Background to red.
        m_ui->connectionIndicator->setStyleSheet("QWidget { background-color: rgb(255,160,122); border-radius: 10px; }");
    }
}

void UiManager::handleConsoleScrollBar()
{
    QScrollBar* sb = m_ui->ConsoleTextBrowser->verticalScrollBar();
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

void UiManager::updateSliderTimerValue()
{
    int interval = m_ui->TimerHorizontalSlider->value();
    emit newSliderTimerValue(interval);
}

void UiManager::clearEnvironnementValues()
{
    m_ui->temperatureDisplay->setText(QString::number(0));
    m_ui->humididyDisplay->setText(QString::number(0));
    m_ui->pressureDisplay->setText(QString::number(0));
}

