#ifndef OFFERWINDOW_H
#define OFFERWINDOW_H

#include <QWidget>

namespace Ui {
class OfferWindow;
}

class OfferWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OfferWindow(QWidget *parent = nullptr);
    ~OfferWindow();

private:
    Ui::OfferWindow *ui;
};

#endif // OFFERWINDOW_H
