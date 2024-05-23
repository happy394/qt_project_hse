#include "profilewindow.h"
#include "ui_profilewindow.h"
#include <QDebug>
ProfileWindow::ProfileWindow(std::shared_ptr<Profile> pr,QWidget *parent)
    : QDialog(parent)
    , profile(pr)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}

void ProfileWindow::on_buttonBox_accepted()
{
    profile ->setEmail(ui->EmailEdit->text());
    profile ->setPassword(ui->PasswordEdit->text());
    qInfo(qUtf8Printable(profile->getEmail()));
}
