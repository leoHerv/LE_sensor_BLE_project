#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainInclude.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QScrollBar>

#include "datamanager.h"
#include "plotmanager.h"
#include "serialmanager.h"
#include "uimanager.h"

/** Declared in the ui_mainwindow.h file **/
QT_BEGIN_NAMESPACE
    namespace Ui {
        class MainWindow;
    }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    /**
     * @brief connectionButton_clicked Triggered when the connection button is clicked.
     */
    void connectionButton_clicked();
    /**
     * @brief deconnectionButton_clicked Triggered when the deconnection button is clicked.
     */
    void deconnectionButton_clicked();
    /**
     * @brief consoleClearButton_clicked Triggered when the console clear button is clicked.
     */
    void consoleClearButton_clicked();
    /**
     * @brief plotClearButton_clicked Triggered when the plot clear button is clicked.
     */
    void plotClearButton_clicked();

private slots:
    /**
     * @brief on_connectionButton_clicked Try to connect with a serial port when the "connectionButton" is clicked.
     */
    void on_connectionButton_clicked();
    /**
     * @brief on_deconnectionButton_clicked Deconnect the serial port.
     */
    void on_deconnectionButton_clicked();
    /**
     * @brief on_consoleClearButton_clicked Clear the console.
     */
    void on_consoleClearButton_clicked();
    /**
     * @brief on_plotClearButton_clicked Clear all the graphs.
     */
    void on_plotClearButton_clicked();

private:
    /**
     * @brief m_ui The user interface (.ui) that have all the buttons, etc ...
     */
    Ui::MainWindow *m_ui;

    /**
     * @brief m_dataManager The class that manage all the datas of the application.
     */
    DataManager* m_dataManager;
    /**
     * @brief m_plotManager The class that manage all the plots of the application.
     */
    PlotManager* m_plotManager;
    /**
     * @brief m_serialManager The class that manage the serial port part.
     */
    SerialManager* m_serialManager;
    /**
     * @brief m_uiManager The class that manager the ui of the application.
     */
    UiManager* m_uiManager;

};
#endif // MAINWINDOW_H
