#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "register.h"
#include "secwindov.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/karta/Desktop/Bank11.png");
    ui->label_pic->setPixmap(pix);


    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/karta/Desktop/BankingSystem/CBPrograming/bankadatabase.db");
    if(!mydb.open())
        ui->label->setText("Not Connected");
    else
        ui->label->setText("Connected");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit_Username->text();
    password=ui->lineEdit_Password->text();

    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }
    QSqlQuery qry;
    if(qry.exec("select * from Abankinfo where username='"+username+"' and password='"+password+"'"))
    {
        int count=0;
        while(qry.next())
        {
            count++;

        }
        if(count==1){
            ui->label->setText("username and password is correct");
            this->hide();
            Secwindov  Second;
            Second.setModal(true);
            Second.exec();
        }

        if(count>1)
            ui->label->setText("Duplicate username and password is correct");
        if(count<1)
            ui->label->setText("username and password is not correct");
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    Register reg;
    reg.setModal(true);
    reg.exec();


}

