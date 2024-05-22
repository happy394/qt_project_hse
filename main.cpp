#include <QApplication>
#include <QMainWindow>
#include <QIcon>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the application icon
    a.setWindowIcon(QIcon(":/icons/appicon.ico"));

    MainWindow w;
    w.show();

    return a.exec();
}
