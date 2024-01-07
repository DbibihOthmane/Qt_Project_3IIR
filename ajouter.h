#ifndef AJOUTER_H
#define AJOUTER_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "mainwindow.h"
namespace Ui {
class Ajouter;
}

class Ajouter : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter(QWidget *parent = nullptr);
    ~Ajouter();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Ajouter *ui;
};

#endif // AJOUTER_H
