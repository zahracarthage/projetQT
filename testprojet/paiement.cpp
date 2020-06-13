#include "paiement.h"
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include "QString"


paiement::paiement()
{
    idc=0;
    idv=0;
    marque="";
    prix=0;
    date_paiement.setDate(2020,07,01);
}

paiement::paiement(int idv,int idc,QString marque,int prix,QDate date_paiement)
{
    this->idv=idv;
    this->idc=idc;
    this->marque=marque;
    this->prix=prix;
    this->date_paiement=date_paiement;
}

bool paiement::ajouter()
{
QSqlQuery query;
QString res= QString::number(idv);
query.prepare("INSERT INTO paiement (idv,idc,marque,prix,date_paiement) "
                    "VALUES (:idv, :idc, :marque, :prix, :date_paiement)");
query.bindValue(":idv", res);
query.bindValue(":idc", idc);
query.bindValue(":marque", marque);
query.bindValue(":prix", prix);
query.bindValue(":date_paiement", date_paiement);
return    query.exec();
}

QSqlQueryModel* paiement::afficher()
{

    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from paiement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idv"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_paiement"));

        return model;
}

bool paiement::supprimer(int idv)
{
QSqlQuery query;
QString res= QString::number(idv);
query.prepare("Delete from paiement where IDV = :idv ");
query.bindValue(":idv", res);
return    query.exec();
}

QSqlQueryModel* paiement::chercher(int idv)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    model->setQuery("select * from paiement where IDV = :idv");


    query.addBindValue(idv);
    query.exec();




model->setHeaderData(0, Qt::Horizontal, QObject::tr("idv"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("idc"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_paiement"));

return model;
}

QSqlQueryModel* paiement::trier_location_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from paiement ORDER BY IDV ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idv"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_paiement"));
    return model;
}

QSqlQueryModel* paiement::trier_location_decroi_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from paiement ORDER BY IDV DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idv"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_paiement"));
    return model;
}


