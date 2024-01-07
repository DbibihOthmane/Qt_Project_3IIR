#include "afficher.h"
#include "ui_afficher.h"
#include <QMessageBox>
Afficher::Afficher(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Afficher)
{
    ui->setupUi(this);
    MainWindow conn;
    if(!conn.connOpen())
        ui->label->setText("Fail");
    else
        ui->label->setText("Conn");
}

Afficher::~Afficher()
{
    delete ui;
}

void Afficher::on_pushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from etudiant");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();

}

