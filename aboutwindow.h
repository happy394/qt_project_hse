#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

namespace Ui {
class AboutWindow;
}

class Aboutwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Aboutwindow(QWidget *parent = nullptr);
    ~Aboutwindow();

private:
    Ui::AboutWindow *ui;
};

#endif
