#include "supprimer.h"
#include "ui_supprimer.h"
#include <QMessageBox>
Supprimer::Supprimer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Supprimer)
{
    ui->setupUi(this);
    MainWindow conn;
    if(!conn.connOpen())
        ui->label->setText("Fail");
    else
        ui->label->setText("Conn");
}

Supprimer::~Supprimer()
{
    delete ui;
}

void Supprimer::on_pushButton_clicked()
{
    MainWindow conn;
    QString id, note;
    id = ui->txt_id->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Fail";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("Delete from etudiant where id='"+id+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Delete") , tr("Deleted"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this, tr("Error") , qry.lastError().text());
    }
}

