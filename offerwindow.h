#ifndef OFFERWINDOW_H
#define OFFERWINDOW_H

#include <QWidget>
#include <QStringListModel>
#include "car.h"

namespace Ui {
class OfferWindow;
}

class OfferWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OfferWindow(car currCar = car(), QWidget *parent = nullptr);
    ~OfferWindow();

private:
    Ui::OfferWindow *ui;
    QStringListModel *carInfoModel;
    car currCar;
};

#endif // OFFERWINDOW_H
