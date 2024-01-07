#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);
}

Application::~Application()
{
    delete ui;
}

void Application::on_pushButton_clicked()
{
    Ajouter ajouter;
    ajouter.setModal(true);
    ajouter.exec();
}


void Application::on_pushButton_2_clicked()
{
    Modif modif;
    modif.setModal(true);
    modif.exec();
}


void Application::on_pushButton_3_clicked()
{
    Supprimer supprimer;
    supprimer.setModal(true);
    supprimer.exec();
}


void Application::on_pushButton_4_clicked()
{
    Afficher afficher;
    afficher.setModal(true);
    afficher.exec();
}

