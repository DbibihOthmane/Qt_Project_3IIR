#ifndef AJOUTER2_H
#define AJOUTER2_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "mainwindow.h"
namespace Ui {
class Ajouter2;
}

class Ajouter2 : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter2(QWidget *parent = nullptr);
    ~Ajouter2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ajouter2 *ui;
};

#endif // AJOUTER2_H
