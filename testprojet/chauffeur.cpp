#include "chauffeur.h"
#include <QDebug>
chauffeure::chauffeure()
{
MATRICULE_FISCALE=0;
NOM="";
}
chauffeure::chauffeure(int MATRICULE_FISCALE,QString NOM)
{
  this->MATRICULE_FISCALE=MATRICULE_FISCALE;
  this->NOM=NOM;


}
int chauffeure::get_MATRICULE_FISCALE(){return  MATRICULE_FISCALE;}
QString chauffeure::get_NOM(){return NOM;}


/* ----- */


bool chauffeure::ajouter()
{
QSqlQuery query;
QString res= QString::number(MATRICULE_FISCALE);
query.prepare("INSERT INTO chauffeure (MATRICULE_FISCALE, NOM) "
                    "VALUES (:MATRICULE_FISCALE, :NOM)");
query.bindValue(":MATRICULE_FISCALE",MATRICULE_FISCALE );
query.bindValue(":NOM", NOM);


return    query.exec();
}

QSqlQueryModel * chauffeure::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from chauffeure");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE_FISCALE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));

    return model;
}

bool chauffeure::supprimer(int MATRICULE_FISCALEE)
{
QSqlQuery query;
QString res= QString::number(MATRICULE_FISCALEE);
query.prepare("Delete from chauffeure where MATRICULE_FISCALE = :MAT ");
query.bindValue(":MAT", res);
return    query.exec();
}
bool chauffeure::modifier(int MATRICULE_FISCALE)
{
    QSqlQuery query;
    QString res= QString::number(MATRICULE_FISCALE);
    query.prepare("UPDATE chauffeure SET MATRICULE_FISCALE=:MATRICULE_FISCALE, NOM=:NOM, WHERE MATRICULE_FISCALE=:MATRICULE_FISCALE");
    query.bindValue(":MATRICULE_FISCALE", MATRICULE_FISCALE);
    query.bindValue(":NOM", NOM);
    return    query.exec();

}
