#include "reclamation.h"

reclamation::reclamation()
{
  id_reclamation="";
  etat="";
  idc="";
    idv="";
    description="";
}

reclamation::reclamation(QString id_reclamation,QString idc, QString idv, QString description, QString etat)
{
    this->id_reclamation=id_reclamation;
    this->etat=etat;
    this->idc=idc;
    this->idv=idv;
    this->description=description;
}
reclamation::reclamation(QString idc, QString idv, QString description, QString etat)
{
    this->etat=etat;
    this->idc=idc;
    this->idv=idv;
    this->description=description;
}


QString reclamation::getid() {
    return id_reclamation;
}
QString reclamation::getidc(){
    return idc;
}
QString reclamation::getidv(){
    return idv;
}
QString reclamation::getetat()
{
    return etat;
}
QString reclamation::getdescription()
{
    return description;
}

bool reclamation::ajouter_reclamation()
{
    QSqlQuery query;



    query.prepare("INSERT INTO reclamation (id_reclamation, idc, idv, description, etat) "
                        "VALUES (:id_reclamation, :idc, :idv, :description, :etat)");


    query.bindValue(":id_reclamation", id_reclamation);
    query.bindValue(":idc", idc);
    query.bindValue(":idv", idv);
    query.bindValue(":description", description);
    query.bindValue(":etat", etat);


    return    query.exec();
}



QSqlQueryModel *reclamation::chercher_reclamation(QString id_reclamation)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from reclamation where id_reclamation= ? ");
    query.addBindValue(id_reclamation);
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_reclamation"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("idc"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("idv"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));



  return model;
}

QSqlQueryModel * reclamation::afficher_reclamation()

{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamation");
model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_reclamation"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("idc"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("idv"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("description"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));


    return model;
}



bool reclamation::modifier_reclamation()
{
     QSqlQuery query;



    query.prepare(" UPDATE reclamation set etat = :etat, idc = :idc, idv = :idv, description = :description where id_reclamation = :id_reclamation");

    query.bindValue(":id_reclamation", id_reclamation);
    query.bindValue(":etat",etat);
    query.bindValue(":idc",idc);
    query.bindValue(":idv",idv);
    query.bindValue(":description",description);

    return query.exec();
}
bool reclamation::supprimer_reclamation(QString id_reclamation)
{

    QSqlQuery query;
    query.prepare("Delete from reclamation where id_reclamation = :id_reclamation ");
    query.bindValue(":id_reclamation", id_reclamation);
    return    query.exec();
}


QSqlQueryModel *reclamation::sort()
{


    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from reclamation ORDER BY id_reclamation ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_reclamation"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("idc"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("idv"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("description"));

    return model;
}


