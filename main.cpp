#include <QApplication>
#include <QSettings>
<<<<<<< HEAD
#include <QMainWindow>
#include <QIcon>
=======
#include "datapath.h"
#include "mainwindow.h"
>>>>>>> 554c83b (cleaned code to start remaking offerstable)

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
    // Set the application icon
    a.setWindowIcon(QIcon(":/icons/appicon.ico"));
    qInfo() << settings.fileName();
    initialCheck(settings);
    if (settings.value("path_amount").toInt() == 0) {
        dataPath d;
        d.exec();
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&d] { return d.functionCalled || !d.isVisible(); });
    }

    MainWindow w;
    w.show();

    return a.exec();
}
