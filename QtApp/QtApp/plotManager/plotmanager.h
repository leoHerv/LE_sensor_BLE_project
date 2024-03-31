#ifndef PLOTMANAGER_H
#define PLOTMANAGER_H

#include "../mainInclude.h"
#include "customPlot/qcustomplot.h"

/** Declared in the ui_mainwindow.h file **/
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class PlotManager : public QObject
{
    Q_OBJECT
public:
    PlotManager(Ui::MainWindow *ui, QFont font);
    ~PlotManager(){};

signals:
    /**
     * @brief restartTime Triggered when the plot is cleared and we need to restart the time.
     * @param time The time from which we restart the time.
     */
    void restartTime(int time);

public slots:
    /**
     * @brief addDataPoint Add the environnement values to the plots.
     * @param temperature The temperature point added in the temperature plot.
     * @param humidity The humidity point added in the humidity plot.
     * @param pressure The pressure point added in the pressure plot.
     * @param time The time at which the point are added.
     */
    void addDataPoint(float temperature, float humidity, float pressure, int time);
    /**
     * @brief clearPlots Clear all the plots.
     */
    void clearPlots();

private:
    /**
     * @brief m_ui The user interface (.ui) that have all the buttons, etc ...
     */
    Ui::MainWindow* m_ui;

    /**
     * @brief m_font The font of the legend of the plots.
     */
    QFont m_font;

    /**
     * @brief m_dataTemperature All the points for the temperature in the plot.
     */
    QSharedPointer<QCPGraphDataContainer> m_dataTemperature;
    /**
     * @brief m_dataHumidity All the points for the humidity in the plot.
     */
    QSharedPointer<QCPGraphDataContainer> m_dataHumidity;
    /**
     * @brief m_dataPressure All the points for pressure in the plot.
     */
    QSharedPointer<QCPGraphDataContainer> m_dataPressure;

    /**
     * @brief setupPlot Setup a plot.
     * @param graphData The graph data that use to draw the plot.
     * @param plot The plot that we setup.
     * @param labelYAxe The label of the Y axe.
     * @param graphName The name of the graph
     * @param penColor The color of the graph.
     */
    void setupPlot(QSharedPointer<QCPGraphDataContainer>* graphData,
                   QCustomPlot* plot, QString labelYAxe, QString graphName, Qt::GlobalColor penColor);
    /**
     * @brief initializePlots Initialize all the plots.
     */
    void initializePlots();
};

#endif // PLOTMANAGER_H
