#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include "profile.h"
#include <QDialog>

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileWindow(std::shared_ptr<Profile> pr,QWidget *parent = nullptr);
    ~ProfileWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ProfileWindow *ui;
    std::shared_ptr<Profile> profile;
};

#endif // PROFILEWINDOW_H
