#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_LoginBar_textChanged(const QString &arg1);

    void on_PasswordBar_textChanged(const QString &arg1);

    void on_CheckUser_clicked();

private:
    Ui::LoginWindow *ui;
    QString login;
    QString password;
};

#endif // LOGINWINDOW_H
