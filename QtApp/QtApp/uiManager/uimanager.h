#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "../mainInclude.h"

/** Declared in the ui_mainwindow.h file **/
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
    /**
     * @brief newSliderTimerValue Triggered when the slider for the data read timer change.
     * @param intervalTimer The new value of the slider.
     */
    void newSliderTimerValue(int intervalTimer);

public slots:
    /**
     * @brief updateConsole Add a new line to the console.
     * @param line The line that is added.
     */
    void updateConsole(const QString line);
    /**
     * @brief clearConsole Clear the console.
     */
    void clearConsole();
    /**
     * @brief updateEnvironnementValues Update the environnement values.
     * @param temperature The new temperature value in the Ui.
     * @param humidity The new humidity value in the Ui.
     * @param pressure The new pressure value in the Ui.
     * @param time We don't use the time, is just for the connnect
     */
    void updateEnvironnementValues(float temperature, float humidity, float pressure, int time);
    /**
     * @brief updateTemperature Update the temperature in the Ui.
     * @param temperature The new temperature.
     */
    void updateTemperature(float temperature);
    /**
     * @brief updateHumidity Update the humidity in the Ui.
     * @param humidity The new humidity.
     */
    void updateHumidity(float humidity);
    /**
     * @brief updatePressure Update the pressure in the Ui.
     * @param pressure The new pressure.
     */
    void updatePressure(float pressure);
    /**
     * @brief updateConnectionIndicator Upadate the indicator in the Ui.
     * @param connected Tell if the indicator need to be green or red.
     */
    void updateConnectionIndicator(bool connected);

    /**
     * @brief updateSliderTimerValue Update when the slider change of value.
     */
    void updateSliderTimerValue();
    /**
     * @brief clearEnvironnementValues Clear all the environnement values.
     */
    void clearEnvironnementValues();

private:
    Ui::MainWindow* m_ui;

    /**
     * @brief m_consoleScrollBarCanMove Tell if the scroll bar of the console can move or not.
     */
    bool m_consoleScrollBarCanMove;

    /**
     * @brief handleConsoleScrollBar If the scroll bar is used by the user then we do not
     * change the position of it.
     */
    void handleConsoleScrollBar();
};

#endif // UIMANAGER_H
