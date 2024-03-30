#ifndef PLOTMANAGER_H
#define PLOTMANAGER_H

#include <QMainWindow>

#include "qcustomplot.h"

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

    void initializePlots();

public slots:
    void addDataPoint(float temperature, float humidity, float pressure, int time);
    void clearPlots();

private:
    /**
     * @brief m_ui The user interface (.ui) that have all the buttons, etc ...
     */
    Ui::MainWindow* m_ui;

    /**
     * @brief m_font The font of legend plot.
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
     * @brief m_time The time for the plot in secondes.
     */
    int m_time;

    /**
     * @brief setupPlot
     * @param graphData
     * @param plot
     * @param labelYAxe
     * @param graphName
     * @param penColor
     */
    void setupPlot(QSharedPointer<QCPGraphDataContainer>* graphData,
                   QCustomPlot* plot, QString labelYAxe, QString graphName, Qt::GlobalColor penColor);
};

#endif // PLOTMANAGER_H
