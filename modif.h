#ifndef MODIF_H
#define MODIF_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "mainwindow.h"
namespace Ui {
class Modif;
}

class Modif : public QDialog
{
    Q_OBJECT

public:
    explicit Modif(QWidget *parent = nullptr);
    ~Modif();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Modif *ui;
};

#endif // MODIF_H
