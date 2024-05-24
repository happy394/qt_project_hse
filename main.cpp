#include "mainwindow.h"
#include "datapath.h"
#include <QApplication>
#include <QSettings>

void initialCheck(QSettings &s)
{
    if (!s.contains("id"))
        s.setValue("id", -1);
    if (!s.contains("path_amount"))
        s.setValue("path_amount", 0);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::mutex mtx;
    std::condition_variable cv;
    QSettings settings("drumdrum");

    initialCheck(settings);
    if (settings.value("path_amount").toInt() == 0)
    {
        dataPath d;
        d.exec();
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&d] { return d.functionCalled || !d.isVisible(); });
    }
    MainWindow w;
    w.show();
    return a.exec();
}
