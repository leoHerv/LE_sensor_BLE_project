#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Set the app style sheet
    QFile styleSheetFile("./Toolery.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet (styleSheet);


    MainWindow w;
    w.show();
    w.resize(900, 600);
    return a.exec();
}
