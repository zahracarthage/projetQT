#include "emplacement.h"
#include <iostream>
#include<QDebug>

using namespace std;
emplacement::emplacement()
{

}
emplacement::emplacement(QString REF,QString id,QString nm,QString et)
{
    this-> ref=REF;
    this-> id_v=id;
    this-> nom=nm;
    this-> etat=et;
}

void emplacement::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into EMPLACEMENT (REF_EMPLACEMENT,ID_VOITURE,NOM,ETAT) values (:REF,:DESCRIP,:MONT,:DAT)");
    query.bindValue(":REF", ref);
    query.bindValue(":DESCRIP", id_v);
    query.bindValue(":MONT", nom);
    query.bindValue(":DAT", etat);
    if(query.exec()){qDebug()<<"saved\n";}

       else{qDebug()<<"not saved!!!\n";}
}
bool emplacement::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("delete from EMPLACEMENT where REF_EMPLACEMENT = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel * emplacement::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from EMPLACEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_EMPLACEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_VOITURE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}
void emplacement::modifier()
{
    QSqlQuery query ;
       query.prepare("update  EMPLACEMENT set  REF_EMPLACEMENT=:ref, ID_VOITURE=:des, NOM=:mon,ETAT=:d where(REF_EMPLACEMENT=:ref)");
       query.bindValue(":ref",ref);
       query.bindValue(":des",id_v);
       query.bindValue(":mon",nom);
       query.bindValue(":d",etat);

       if(query.exec())
      {


       qDebug()<<" mis a jour effectuuer!!\n";
   }

    else{ qDebug()<<" echec de la mis a jour!!\n";
}
}
QSqlQueryModel * emplacement::rechercher(QString id)
{


    QSqlQueryModel *mqy=new::QSqlQueryModel;
               mqy->setQuery("select * from  EMPLACEMENT where REF_EMPLACEMENT like '%"+id+"%'");
               return mqy;

}
QSqlQueryModel * emplacement::tri1()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLACEMENT ORDER BY REF_EMPLACEMENT ASC");
        return model;
}
QSqlQueryModel * emplacement::tri2()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLACEMENT ORDER BY REF_EMPLACEMENT DESC");
        return model;
}
