#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "application.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/poste/Desktop/database/dbothmane.db");
        if(!mydb.open())
        {
            qDebug()<<("Fail");
            return false;
        }
        else
        {
            qDebug()<<("conn");
            return true;
        }

    }


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonConnection_clicked();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
