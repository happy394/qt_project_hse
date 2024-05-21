#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QTableWidgetItem>
#include "offerslist.h"
#include "car.h"

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

    void on_ModelFilter_textActivated(const QString &arg1);

    void on_pushButton_clicked();

    void on_PriceMin_textEdited(const QString &arg1);

    void on_PriceMax_textEdited(const QString &arg1);

    void on_MileageMin_textEdited(const QString &arg1);

    void on_MileageMax_textEdited(const QString &arg1);

    void on_AgeMin_textEdited(const QString &arg1);

    void on_AgeMax_textEdited(const QString &arg1);

    void on_SearchButton_clicked();

    void showGuideline();

    void on_OffersList_cellDoubleClicked(int row, int column);

    void on_SortFilter_textActivated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    offersList *offerslist; // class with offers of used cars

    // models for app objects
    QTableWidgetItem *offerModel;
    QStringListModel *brandModel;
    QStringListModel *modelModel;

    QStringList carInfoList;

    int minPrice = 0;
    long int maxPrice = 10000000000;
    int minMileage = 0;
    long int maxMileage = 10000000000;
    int minAge = 0;
    int maxAge = 1000;

    QString searchInput = "";

    void applyFilter();
};

#endif // MAINWINDOW_H
