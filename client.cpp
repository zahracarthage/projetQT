#include "client.h"
#include <QDebug>
client::client()
{
REF=0;
NOM="";
PRENOM="";
CIN=0;
ADRESSE="";
DATE1="";
NBR_JOURS="";
}
client::client(int REF,QString NOM,QString PRENOM,int CIN,QString ADRESSE,QString DATE1,QString NBR_JOURS)
{
  this->REF=REF;
  this->NOM=NOM;
  this->PRENOM=PRENOM;
    this->CIN=CIN;
    this->ADRESSE=ADRESSE;
    this->DATE1=DATE1;
    this->NBR_JOURS=NBR_JOURS;
}
QString client::get_NOM(){return  NOM;}
QString client::get_PRENOM(){return PRENOM;}
QString client::get_ADRESSE(){return ADRESSE;}
QString client::get_DATE1(){return DATE1;}
QString client::get_NBR_JOURS(){return NBR_JOURS;}
int client::get_REF(){return  REF;}
int client::get_CIN(){return  CIN;}


/* ----- */


bool client::ajouter()
{
QSqlQuery query;
QString res= QString::number(REF);
query.prepare("INSERT INTO client (REF, NOM, PRENOM,CIN,ADRESSE,DATE1,NBR_JOURS) "
                    "VALUES (:REF, :NOM, :PRENOM,:CIN,:ADRESSE,:DATE1,:NBR_JOURS)");
query.bindValue(":REF", REF);
query.bindValue(":NOM", NOM);
query.bindValue(":PRENOM", PRENOM);
query.bindValue(":CIN", CIN );
query.bindValue(":ADRESSE", ADRESSE);
query.bindValue(":DATE1", DATE1);
query.bindValue(":NBR_JOURS", NBR_JOURS);


return    query.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE1"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NBR_JOURS"));
    return model;
}

bool client::supprimer(int REFF)
{
QSqlQuery query;
QString res= QString::number(REFF);
query.prepare("Delete from client where REF = :ref ");
query.bindValue(":ref", res);
return    query.exec();
}

bool client::modifier(int REF)
{
    QSqlQuery query;
    QString res= QString::number(REF);
    query.prepare("UPDATE client SET REF=:REF,NOM=:NOM,PRENOM=:PRENOM,CIN=:CIN,ADRESSE=:ADRESSE,DATE1=:DATE1,NBR_JOURS=:NBR_JOURS WHERE REF=:REF");
    query.bindValue(":REF", REF);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":CIN", CIN );
    query.bindValue(":ADRESSE", ADRESSE);
    query.bindValue(":DATE1", DATE1);
    query.bindValue(":NBR_JOURS", NBR_JOURS);
    return    query.exec();

}

QSqlQueryModel * client::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString recher="select * from client where nom like '%"+rech+"%' or prenom like '%"+rech+"%'";
    model->setQuery(recher);
    return model;
}

QSqlQueryModel * client::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM client ORDER BY REF");
        return model;
}
