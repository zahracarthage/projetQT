#include "voiture.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>

voiture::voiture()
{
id_voiture="";
nom_voiture="";
prix="";
nbr_location="";
nbr_reparation="";
disponibilite="";

}
voiture::voiture(QString id_voiture, QString nom_voiture, QString prix, QString nbr_location, QString nbr_reparation, QString disponibilite)

{
    this->id_voiture=id_voiture;
    this->nom_voiture=nom_voiture;
    this->prix=prix;
    this->nbr_location=nbr_location;
    this->nbr_reparation=nbr_reparation;
    this->disponibilite=disponibilite;
}
voiture::voiture(QString nom_voiture, QString prix, QString nbr_location, QString nbr_reparation, QString disponibilite)
{
    this->nom_voiture=nom_voiture;
    this->prix=prix;
    this->nbr_location=nbr_location;
    this->nbr_reparation=nbr_reparation;
    this->disponibilite=disponibilite;
}

QString voiture::getid()
{
    return  id_voiture;
}

QString voiture::getnom()
{
    return nom_voiture;
}
QString voiture::getprix()
{
    return prix;
}
QString voiture::getnbrlocation()
{
    return nbr_location;
}
QString voiture::getnbrreparation()
{
   return nbr_reparation;
}
QString voiture::getdispo(){
    return disponibilite;
}

bool voiture::ajouter_voiture()
{
    QSqlQuery query;



    query.prepare("INSERT INTO voiture (nom_voiture, prix, nbr_location, nbr_reparation, disponibilite) "
                        "VALUES (:nom_voiture, :prix, :nbr_location, :nbr_reparation, :disponibilite)");


    query.bindValue(":nom_voiture", nom_voiture);
    query.bindValue(":prix", prix);
    query.bindValue(":nbr_location", nbr_location);
    query.bindValue(":nbr_reparation", nbr_reparation);
    query.bindValue(":disponibilite", disponibilite);


    return    query.exec();
}

bool voiture::verif(QString id)
{
    int i=0;

    QSqlQuery query;
    query.prepare("select * from authentification where id= ? ");
   query.addBindValue(id);
    if(query.exec())
    {while(query.next())
        {
            i++;

        }}

    if(i!=0)
        return true ;
    else
        return false;

}



QSqlQueryModel *voiture::chercher_voiture(QString id_voiture)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from voiture where id_voiture= ? ");
    query.addBindValue(id_voiture);
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_voiture"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_voiture"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nbr_location"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nbr_reparation"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("disponibilite"));



  return model;
}

QSqlQueryModel * voiture::afficher_voiture()

{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from voiture");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_voiture"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_voiture"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("nbr_location"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("nbr_reparation"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("disponibilite"));

    return model;
}


bool voiture::modifier_voiture()
{
     QSqlQuery query;



    query.prepare(" UPDATE voiture set nom_voiture = :nom_voiture, prix = :prix, nbr_location = :nbr_location, nbr_reparation = :nbr_reparation, disponibilite = :disponibilite  where id_voiture = :id_voiture");

    query.bindValue(":id_voiture", id_voiture);
    query.bindValue(":nom_voiture",nom_voiture);
    query.bindValue(":prix",prix);
    query.bindValue(":nbr_location",nbr_location);
    query.bindValue(":nbr_reparation",nbr_reparation);
    query.bindValue(":disponibilite",disponibilite);

    return query.exec();
}

bool voiture::supprimer_voiture(QString id_voiture)
{

    QSqlQuery query;
    query.prepare("Delete from voiture where id_voiture = :id_voiture ");
    query.bindValue(":id_voiture", id_voiture);
    return    query.exec();
}

QSqlQueryModel *voiture::sortprix()
{


    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from voiture ORDER BY PRIX ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_voiture"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_voiture"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nbr_location"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nbr_reparation"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("disponibilite"));

    return model;
}

QSqlQueryModel *voiture::sortnom()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from voiture ORDER BY NOM_VOITURE ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_voiture"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_voiture"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nbr_location"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nbr_reparation"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("disponibilite"));

    return model;

}
QSqlQueryModel *voiture::sortnbrloca()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select * from voiture ORDER BY NBR_LOCATION ");

model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_voiture"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_voiture"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("nbr_location"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("nbr_reparation"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("disponibilite"));

return model;
}
