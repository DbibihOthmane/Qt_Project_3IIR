#ifndef APPLICATION_H
#define APPLICATION_H

#include <QDialog>
#include "ajouter.h"
#include "modif.h"
#include "supprimer.h"
#include "afficher.h"
namespace Ui {
class Application;
}

class Application : public QDialog
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Application *ui;
};

#endif // APPLICATION_H
