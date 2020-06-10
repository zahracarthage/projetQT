#include "client_fidele.h"
#include <QDebug>
client_fidele::client_fidele()
{
MATRICULE_FISCALE=0;
NOM="";
CIN="";
ADRESSE="";
ADRESSE_MAIL="";
}
client_fidele::client_fidele(int MATRICULE_FISCALE,QString NOM,QString CIN,QString ADRESSE,QString ADRESSE_MAIL)
{
  this->MATRICULE_FISCALE=MATRICULE_FISCALE;
  this->NOM=NOM;
  this->CIN=CIN;
    this->ADRESSE=ADRESSE;
    this->ADRESSE_MAIL=ADRESSE_MAIL;

}
int client_fidele::get_MATRICULE_FISCALE(){return  MATRICULE_FISCALE;}
QString client_fidele::get_NOM(){return NOM;}
QString client_fidele::get_CIN(){return CIN;}
QString client_fidele::get_ADRESSE(){return ADRESSE;}
QString client_fidele::get_ADRESSE_MAIL(){return ADRESSE_MAIL;}


/* ----- */


bool client_fidele::ajouter()
{
QSqlQuery query;
QString res= QString::number(MATRICULE_FISCALE);
query.prepare("INSERT INTO client_fidele (MATRICULE_FISCALE, NOM,CIN,ADRESSE,ADRESSE_MAIL) "
                    "VALUES (:MATRICULE_FISCALE, :NOM, :CIN,:ADRESSE,:ADRESSE_MAIL)");
query.bindValue(":MATRICULE_FISCALE",MATRICULE_FISCALE );
query.bindValue(":NOM", NOM);
query.bindValue(":CIN", CIN );
query.bindValue(":ADRESSE", ADRESSE);
query.bindValue(":ADRESSE_MAIL",ADRESSE_MAIL );


return    query.exec();
}

QSqlQueryModel * client_fidele::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client_fidele");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE_FISCALE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));
    return model;
}

bool client_fidele::supprimer(int MATRICULE_FISCALEE)
{
QSqlQuery query;
QString res= QString::number(MATRICULE_FISCALEE);
query.prepare("Delete from client_fidele where MATRICULE_FISCALE = :MAT ");
query.bindValue(":MAT", res);
return    query.exec();
}
bool client_fidele::modifier(int MATRICULE_FISCALE)
{
    QSqlQuery query;
    QString res= QString::number(MATRICULE_FISCALE);
    query.prepare("UPDATE client_fidele SET MATRICULE_FISCALE=:MATRICULE_FISCALE,NOM=:NOM,CIN=:CIN,ADRESSE=:ADRESSE,ADRESSE_MAIL=:ADRESSE_MAIL WHERE MATRICULE_FISCALE=:MATRICULE_FISCALE");
    query.bindValue(":MATRICULE_FISCALE", MATRICULE_FISCALE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":CIN", CIN );
    query.bindValue(":ADRESSE", ADRESSE);
    query.bindValue(":ADRESSE_MAIL", ADRESSE_MAIL);
    return    query.exec();

}

