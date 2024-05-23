#ifndef DATAPATH_H
#define DATAPATH_H

#include <QDialog>

namespace Ui {
class dataPath;
}

class dataPath : public QDialog
{
    Q_OBJECT

public:
    explicit dataPath(QWidget *parent = nullptr);
    ~dataPath();
    bool functionCalled = false;

private slots:
    void on_addPath_clicked();

private:
    Ui::dataPath *ui;
};

#endif // DATAPATH_H
