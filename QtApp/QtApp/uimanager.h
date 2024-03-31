#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class UiManager : public QObject
{
    Q_OBJECT
public:
    UiManager(Ui::MainWindow *ui);
    ~UiManager();

signals:
    void newSliderTimerValue(int intervalTimer);

public slots:
    void updateConsole(const QString line);
    void updateEnvironnementValues(float temperature, float humidity, float pressure, int time);
    void updateTemperature(float temperature);
    void updateHumidity(float humidity);
    void updatePressure(float pressure);
    void updateConnectionIndicator(bool connected);
    void clearConsole();
    void updateSliderTimerValue();
    void clearEnvironnementValues();

private:
    Ui::MainWindow* m_ui;

    bool m_consoleScrollBarCanMove;

    /**
     * @brief handleConsoleScrollBar If the scroll bar is used by the user then we do not
     * change the position of it.
     */
    void handleConsoleScrollBar();
};

#endif // UIMANAGER_H
