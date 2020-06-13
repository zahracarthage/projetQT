#include "location.h"
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include "QString"

location::location()
{
    idc=0;
    idv=0;
    marque="";
    date_location.setDate(2020,06,01);
    date_expiration.setDate(2020,07,01);
    status="";
    montant_location=0;
}

location::location(int idv,int idc,QString marque,QDate date_loc,QDate date_exp,QString status, int montant_loc)
{
    this->idc=idc;
    this->idv=idv;
    this->marque=marque;
    this->date_location=date_loc;
    this->date_expiration=date_exp;
    this->status=status;
    this->montant_location=montant_loc;
}

bool location::ajouter()
{
QSqlQuery query;
QString res= QString::number(idv);
query.prepare("INSERT INTO location (idv,idc,marque,date_location,date_expiration,status,montant_location) "
                    "VALUES (:idv, :idc, :marque, :date_location, :date_expiration, :status, :montant_location)");
query.bindValue(":idv", res);
query.bindValue(":idc", idc);
query.bindValue(":marque", marque);
query.bindValue(":date_location", date_location);
query.bindValue(":date_expiration", date_expiration);
query.bindValue(":status", status);
query.bindValue(":montant_location", montant_location);

return    query.exec();
}

QSqlQueryModel* location::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from location");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idv"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_loc"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_exp"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("status"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("montant"));




    return model;
}

bool location::supprimer(int idv)
{
QSqlQuery query;
QString res= QString::number(idv);
query.prepare("Delete from location where IDV = :idv ");
query.bindValue(":idv", res);
return    query.exec();
}

QSqlQueryModel* location::chercher(int idv)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from location where IDV = :idv  ");
    query.addBindValue(idv);
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idv"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("idc"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_loc"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_ex"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("status"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("montant"));

return model;
}

QSqlQueryModel* location::trier_location_id()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from location ORDER BY IDV ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idv"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("idc"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_loc"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_ex"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("status"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("montant"));
    return model;
}

QSqlQueryModel* location::trier_location_decroi_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from location ORDER BY IDV DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idv"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("idc"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_loc"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_ex"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("status"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("montant"));
    return model;
}

