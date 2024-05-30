#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QTableWidgetItem>
#include "offerslist.h"
#include "profilewindow.h"
#include "profile.h"

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
    void loggedIn (QString);

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

     void showAboutDialog();

    void on_OffersList_cellDoubleClicked(int row, int column);

<<<<<<< HEAD
    void on_SortFilter_textActivated(const QString &arg1);

    void on_FavoriteButton_clicked();

    void on_checkBox_stateChanged(int arg1);

=======
>>>>>>> 554c83b (cleaned code to start remaking offerstable)
private:
    Ui::MainWindow *ui;
    offersList *offerslist; // class with offers of used cars

    std::shared_ptr<ProfileWindow> profileWindow;
    std::shared_ptr<Profile> profile;



    // models for app objects
    QTableWidgetItem *offerModel;
    QStringListModel *brandModel;
    QStringListModel *modelModel;
    QStringListModel *sortModel;

<<<<<<< HEAD
    QStringList sortList = {"", "brand", "model", "price", "city", "fuel", "transmission", "drive", "mileage",
"country", "engine capacity", "engine hp", "age","id"};
=======
    QStringList sortList = {"",
                            "brand",
                            "model",
                            "price",
                            "city",
                            "fuel",
                            "transmission",
                            "drive",
                            "mileage",
                            "country",
                            "engine capacity",
                            "engine hp",
                            "age"};
>>>>>>> 554c83b (cleaned code to start remaking offerstable)

    QStringList carInfoList;

    int minPrice = 0;
    long int maxPrice = 10000000000;
    int minMileage = 0;
    long int maxMileage = 10000000000;
    int minAge = 0;
    int maxAge = 1000;

    QString searchInput = "";

    void applyFilter();
    bool onlyFavourites = false;
};

#endif // MAINWINDOW_H
