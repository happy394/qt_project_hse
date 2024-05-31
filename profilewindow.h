#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include "profile.h"
#include <QDialog>

//Please don't delte without telling me!(confier)

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
    void on_RegistereButton_clicked();

    void on_Login_Button_clicked();


private:
    Ui::ProfileWindow *ui;
    std::shared_ptr<Profile> profile;
    //std::weak_ptr<MainWindow> mainwindow;
    bool logIn(QString email, QString password);
};

#endif // PROFILEWINDOW_H
