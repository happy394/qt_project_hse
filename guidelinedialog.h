#ifndef GUIDELINEDIALOG_H
#define GUIDELINEDIALOG_H

#include <QDialog>

namespace Ui {
class GuidelineDialog;
}

class GuidelineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GuidelineDialog(QWidget *parent = nullptr);
    ~GuidelineDialog();

private:
    Ui::GuidelineDialog *ui;
};

#endif
