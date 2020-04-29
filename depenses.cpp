#include "depenses.h"
#include <iostream>
#include <QDate>
#include<QDebug>
using namespace std;
depenses::depenses()
{

}
depenses::depenses(QString REF_DEPENSE,QString DESCRIPTION,QString MONTANT,QString DATE)
{
    this-> REF=REF_DEPENSE;
    this-> DESCRIPTION=DESCRIPTION;
    this-> MONTANT=MONTANT;
    this-> DATE=DATE;
}
void depenses::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into DEPENSE (REF,DESCRIPTION,MONTANT,DATE_D) values (:REF,:DESCRIP,:MONT,:DAT)");
    query.bindValue(":REF", REF);
    query.bindValue(":DESCRIP", DESCRIPTION);
    query.bindValue(":MONT", MONTANT);
    query.bindValue(":DAT", DATE);
    if(query.exec()){qDebug()<<"saved\n";}

       else{qDebug()<<"not saved!!!\n";}
}
QSqlQueryModel * depenses::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from DEPENSE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_D"));
    return model;
}
bool depenses::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("delete from DEPENSE where REF = :id");
    query.bindValue(":id", id);
    return query.exec();
}
void depenses::modifier()
{
    QSqlQuery query ;
       query.prepare("update  DEPENSE set  REF=:ref, DESCRIPTION=:des, MONTANT=:mon,DATE_D=:EMAIL_E where(REF=:ref)");
       query.bindValue(":ref",REF);
       query.bindValue(":des",DESCRIPTION);
       query.bindValue(":mon",MONTANT);
       query.bindValue(":d",DATE);

       if(query.exec())
      {


       qDebug()<<" mis a jour effectuuer!!\n";
   }

    else{ qDebug()<<" echec de la mis a jour!!\n";
}
}
QSqlQueryModel * depenses::rechercher(QString id)
{


    QSqlQueryModel *mqy=new::QSqlQueryModel;
               mqy->setQuery("select * from  DEPENSE where REF like '%"+id+"%'");
               return mqy;


}
QSqlQueryModel * depenses::tri1()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM DEPENSE ORDER BY REF ASC");
        return model;
}
QSqlQueryModel * depenses::tri2()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM DEPENSE ORDER BY REF DESC");
        return model;
}
