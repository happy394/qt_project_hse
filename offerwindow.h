#ifndef OFFERWINDOW_H
#define OFFERWINDOW_H

#include <QStringListModel>
#include <QWidget>
#include "car.h"

#include "profile.h"



namespace Ui {
class OfferWindow;
}

class OfferWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OfferWindow(std::shared_ptr<Profile> profile, car currCar = car(), QWidget *parent = nullptr);
    ~OfferWindow();

private slots:
    void on_FavoriteButton_clicked();


    void on_pushButton_clicked();

private:
    std::shared_ptr<Profile> profile;
    Ui::OfferWindow *ui;
    QStringListModel *carInfoModel;
    QStringListModel *carName;
    car currCar;

};

#endif // OFFERWINDOW_H
