#include "contrat.h"
#include <QDebug>
#include "connexion.h"
#include <QDate>
#include <QDateEdit>
contrat::contrat()
{
    id_voiture=0;
    nom="";
    prenom="";
    tel="";


}
contrat::contrat(int id_voiture,QString nom,QString prenom,QString tel,QDate datee){

    this->id_voiture=id_voiture;
    this->nom=nom;
    this->prenom=prenom;
    this->tel=tel;
    this->datee=datee;

}
QSqlQueryModel* contrat::afficher()
{
QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from contrat");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_voiture"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("datee"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));

    return model;
}
bool contrat::ajouter()
{

    QSqlQuery query;


    query.prepare("INSERT INTO contrat (ID_VOITURE,NOM, PRENOM,TEL,DATEE) "
                        "VALUES (:id_voiture,:nom,:prenom,:tel,:datee)");
    query.bindValue(":id_voiture",id_voiture);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);
    query.bindValue(":datee", datee);
    return    query.exec();
    }
bool contrat::supprimer(int id_voiture)
{
QSqlQuery query;
QString res= QString::number(id_voiture);
query.prepare("Delete from contrat where ID_VOITURE = :id_voiture ");
query.bindValue(":id_voiture", res);
return    query.exec();
}
bool contrat::modifier(int id_voiture,QString nom,QString prenom,QString tel,QDate datee)
{
    QSqlQuery query;
    query.prepare("update contrat set  nom=:nom,prenom=:prenom,tel=:tel,datee=:datee where id_voiture=:id_voiture");
  /*,,,,
    */

    query.bindValue(":id_voiture",id_voiture);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);
    query.bindValue(":datee",datee);

    return query.exec();
}
QSqlQueryModel * contrat:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from contrat order by id_voiture");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_voiture"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr(" nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr(" date"));
return model;
}

QSqlQueryModel * contrat::chercher_voiture(QString id)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
id='%'+id+'%';
query.prepare(" select * from contrat where id_voiture like :id order by id_voiture  ");
query.bindValue(":id",id);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_voiture"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr(" nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr(" date"));
    return model;
}
bool contrat::verifierId_voiture(int Id_voiture)
{

    QSqlQuery query;
    QString n;
    QString  num = QString::number(Id_voiture);
            query.exec("SELECT id_voiture from contrat");
            while (query.next())
            {
                n=query.value("id_voiture").toString();
                if (n==num)
                {
                    return true;
                }
            }
    return false;

      }
