#include "ajouter2.h"
#include "ui_ajouter2.h"
#include <QMessageBox>

Ajouter2::Ajouter2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ajouter2)
{
    ui->setupUi(this);
    MainWindow conn;
    if(!conn.connOpen())
        ui->label->setText("Fail");
    else
        ui->label->setText("Conn");
}

Ajouter2::~Ajouter2()
{
    delete ui;
}

void Ajouter2::on_pushButton_clicked()
{
    MainWindow conn;
    QString  note, combo;
    note = ui->txt_note->text();
    combo = ui->comboBox->currentText();
    if(!conn.connOpen())
    {
        qDebug()<<"Fail";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into etudiant ( matiere, note) values ( '"+combo+"', '"+note+"')");
    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Save") , tr("Saved"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this, tr("Error") , qry.lastError().text());
    }

}

