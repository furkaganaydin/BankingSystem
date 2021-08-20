#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

#include "register.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
     QSqlDatabase mydb;

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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H
