#include "secwindov.h"
#include "ui_secwindov.h"

Secwindov::Secwindov(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Secwindov)
{
    ui->setupUi(this);
}

Secwindov::~Secwindov()
{
    delete ui;
}

void Secwindov::on_LOADTABLE_clicked()
{
    QSqlQueryModel*modal =new QSqlQueryModel();
    connOpen();
    QSqlQuery * qry=new QSqlQuery(mydb);

    qry->prepare("select money  from Abankinfo");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    connClose();
    qDebug()<<(modal->rowCount());





}

