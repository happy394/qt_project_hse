#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QStringListModel>
#include "offerslist.h"

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
    void on_BrandFilter_textActivated(const QString &arg1);

    void on_CountryFilter_textActivated(const QString &arg1);

    void on_ModelFilter_textActivated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QStringListModel *list;
    QStringList *stringlist;
    offersList *offerslist; // offers of used cars
    QStringListModel *brand;
    QStringListModel *model;
    QStringListModel *country;
};
#endif // MAINWINDOW_H
