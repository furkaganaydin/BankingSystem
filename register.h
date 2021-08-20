#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQuery>

namespace Ui {
class Register;
}

class Register : public QDialog
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
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Register *ui;
    QSqlDatabase mydb;
};

#endif // REGISTER_H
