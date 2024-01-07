#include "modif.h"
#include "ui_modif.h"
#include <QMessageBox>
Modif::Modif(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Modif)
{
    ui->setupUi(this);
    MainWindow conn;
    if(!conn.connOpen())
        ui->label->setText("Fail");
    else
        ui->label->setText("Conn");
}



Modif::~Modif()
{
    delete ui;
}

void Modif::on_pushButton_clicked()
{
    MainWindow conn;
    QString id, note, matiere;
    id = ui->txt_id->text();
    note = ui->txt_note->text();
    matiere = ui->comboBox->currentText();

    if(!conn.connOpen())
    {
        qDebug()<<"Fail";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update etudiant set '"+matiere+"'='"+note+"' where id='"+id+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Edit") , tr("Updated"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this, tr("Error") , qry.lastError().text());
    }
}

