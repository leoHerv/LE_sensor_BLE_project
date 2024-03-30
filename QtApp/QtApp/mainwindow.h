#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./ui_mainwindow.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QScrollBar>

#include "datamanager.h"
#include "plotmanager.h"
#include "serialmanager.h"
#include "uimanager.h"

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

private slots:
    /**
     * @brief on_connectionButton_clicked Try to connect with a serial port when the "connectionButton" is clicked.
     */
    void on_connectionButton_clicked();
    /**
     * @brief on_consoleClearButton_clicked Clear the console.
     */
    void on_consoleClearButton_clicked();
    /**
     * @brief on_deconnectionButton_clicked Deconnect the serial port.
     */
    void on_deconnectionButton_clicked();
    /**
     * @brief on_plotClearButton_clicked Clear all the graphs.
     */
    void on_plotClearButton_clicked();

private:
    /**
     * @brief m_ui The user interface (.ui) that have all the buttons, etc ...
     */
    Ui::MainWindow *m_ui;


    DataManager* m_dataManager;
    PlotManager* m_plotManager;
    SerialManager* m_serialManager;
    UiManager* m_uiManager;

};
#endif // MAINWINDOW_H
