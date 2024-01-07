#ifndef AFFICHER_H
#define AFFICHER_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "mainwindow.h"

namespace Ui {
class Afficher;
}

class Afficher : public QDialog
{
    Q_OBJECT

public:
    explicit Afficher(QWidget *parent = nullptr);
    ~Afficher();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Afficher *ui;
};

#endif // AFFICHER_H
