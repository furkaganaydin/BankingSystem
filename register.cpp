#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"
#include <QMessageBox>


Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/karta/Desktop/BankingSystem/CBPrograming/bankadatabase.db");
    if(!mydb.open())
        ui->label_info->setText("Not Connected");
    else
        ui->label_info->setText("Connected");
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    QString Id,Name,Surname,username,password,money;
    Id=ui->txt_Id->text();
    Name=ui->txt_name->text();
    Surname=ui->txt_surname->text();
    username=ui->text_username->text();
    password=ui->text_password->text();
    money=ui->text_money->text();


    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    connOpen();

    QSqlQuery qry;
    qry.prepare("insert into Abankinfo (Id,Name,Surname,password,username,money) values('"+Id+"','"+Name+"','"+Surname+"','"+password+"','"+username+"','"+money+"')");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

