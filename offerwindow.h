#ifndef OFFERWINDOW_H
#define OFFERWINDOW_H

#include <QWidget>
#include <QStringListModel>
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

private:
    std::shared_ptr<Profile> profile;
    Ui::OfferWindow *ui;
    QStringListModel *carInfoModel;
    QStringListModel *carName;
    car currCar;
};

#endif // OFFERWINDOW_H
