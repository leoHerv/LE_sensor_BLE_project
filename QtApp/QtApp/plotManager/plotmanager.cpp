#include "plotmanager.h"

PlotManager::PlotManager(Ui::MainWindow *ui, QFont font) :
    QObject(nullptr),
    m_ui(ui),
    m_font(font)
{
    initializePlots();
}

void PlotManager::setupPlot(QSharedPointer<QCPGraphDataContainer>* graphData,
                            QCustomPlot* plot, QString labelYAxe, QString graphName, Qt::GlobalColor penColor)
{
    *graphData = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);

    QFont legendFont = m_font;
    legendFont.setPointSize(10);
    QString timeLabel = "Temps (s)";

    // Init of the plot.
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    plot->legend->setVisible(true);
    plot->legend->setFont(legendFont);
    plot->legend->setSelectedFont(legendFont);
    plot->legend->setSelectableParts(QCPLegend::spItems);
    plot->yAxis->setLabel(labelYAxe);
    plot->xAxis->setLabel(timeLabel);
    plot->clearGraphs();

    plot->addGraph();
    plot->graph()->setPen(QPen(penColor));
    plot->graph()->setData(*graphData);
    plot->graph()->setName(graphName);
}

void PlotManager::initializePlots()
{
    // Init plot for the Temperature.
    setupPlot(&m_dataTemperature, m_ui->plotTemperatureWidget, "Température (°C)", "Température", Qt::black);
    // Init plot for the Humidity.
    setupPlot(&m_dataHumidity, m_ui->plotHumidityWidget, "Humidité (g/m3)", "Humidité", Qt::red);
    // Init plot for the Pressure.
    setupPlot(&m_dataPressure, m_ui->plotPressureWidget, "Pression (hPa)", "Pression", Qt::blue);
}

void replot(QCustomPlot* plot)
{
    plot->rescaleAxes();
    plot->replot();
}

void PlotManager::addDataPoint(float temperature, float humidity, float pressure, int time)
{
    // When the reading is finish, we can add the points to the plot.
    m_dataTemperature->add(QCPGraphData(time, temperature));
    m_dataHumidity->add(QCPGraphData(time, humidity));
    m_dataPressure->add(QCPGraphData(time, pressure));

    // Update the plots.
    replot(m_ui->plotTemperatureWidget);
    replot(m_ui->plotHumidityWidget);
    replot(m_ui->plotPressureWidget);
}

void PlotManager::clearPlots()
{
    // We clear all the points.
    m_dataTemperature->clear();
    m_dataHumidity->clear();
    m_dataPressure->clear();

    // We reset the graphs.
    replot(m_ui->plotTemperatureWidget);
    replot(m_ui->plotHumidityWidget);
    replot(m_ui->plotPressureWidget);

    emit restartTime(0);
}

