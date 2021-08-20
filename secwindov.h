#ifndef SECWINDOV_H
#define SECWINDOV_H
#include "mainwindow.h"
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQuery>


namespace Ui {
class Secwindov;
}

class Secwindov : public QDialog
{
    Q_OBJECT

public:
    void connClose(){

        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/karta/Desktop/BankingSystem/CBPrograming/bankadatabase.db");
        if(!mydb.open()){
            qDebug()<<("Not Connected");
            return false;
        }
        else{
           qDebug()<<("Connected");
           return true;
        }
    }
public:

    explicit Secwindov(QWidget *parent = nullptr);
    ~Secwindov();

private slots:
    void on_LOADTABLE_clicked();

private:
    Ui::Secwindov *ui;
    QSqlDatabase mydb;
};

#endif // SECWINDOV_H
