#include "ajouter.h"
#include "ui_ajouter.h"
#include <QMessageBox>
Ajouter::Ajouter(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ajouter)
{
    ui->setupUi(this);
    MainWindow conn;
    if(!conn.connOpen())
        ui->label->setText("Fail");
    else
        ui->label->setText("Conn");
}

Ajouter::~Ajouter()
{
    delete ui;
}

void Ajouter::on_pushButton_clicked()
{
    hide();
}




void Ajouter::on_pushButton_2_clicked()
{
    MainWindow conn;
    QString  nom, prenom, cpp, js, sql, network;
    nom = ui->txt_nom->text();
    prenom = ui->txt_prenom->text();
    cpp = ui->txt_cpp->text();
    js = ui->txt_js->text();
    sql = ui->txt_sql->text();
    network = ui->txt_network->text();
    if(!conn.connOpen())
    {
        qDebug()<<"Fail";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into etudiant ( nom,prenom,cpp,javascript,sql,network) values ( '"+nom+"', '"+prenom+"', '"+cpp+"', '"+js+"', '"+sql+"', '"+network+"')");
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

