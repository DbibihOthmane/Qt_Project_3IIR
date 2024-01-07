#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!connOpen())
        ui->label->setText("Fail");
    else
        ui->label->setText("Conn");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonConnection_clicked()
{
    QString userName = ui->userName->text();
    QString password = ui->password->text();
    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from admin where username ='"+userName+"' and password='"+password+"'");
    if(qry.exec())
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }
        if(count > 0)
        {
            QMessageBox::information(this, "Login" , "Connected succesfully");
            connClose();
            this->hide();
            Application application;
            application.setModal(true);
            application.exec();
        }
        else if(count == 0)
        {
            QMessageBox::warning(this, "Login", "Connection failed , Wrong informations");
        }

    }


}


