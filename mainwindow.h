#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QTableWidgetItem>
#include "profilewindow.h"
#include "profile.h"
#include "offersmodel.h"
#include "proxymodel.h"

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

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_FavoriteButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    offersmodel *offersModel;
    ProxyModel *proxyModel;

    std::shared_ptr<ProfileWindow> profileWindow;
    std::shared_ptr<Profile> profile;



    // models for app objects
    QTableWidgetItem *offerModel;
    QStringListModel *brandModel;
    QStringListModel *modelModel;
    QStringListModel *sortModel;

    QStringList sortList = {"", "brand", "model", "price", "city", "fuel", "transmission", "drive", "mileage",
"country", "engine capacity", "engine hp", "age","id"};

    QStringList carInfoList;

    QString searchInput = "";

    bool onlyFavourites = false;
};

#endif // MAINWINDOW_H
