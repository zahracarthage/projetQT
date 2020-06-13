#include <QDebug>
#include "personnel.h"
personnel::personnel()
{
    id_personnel=0;
    nom="";
    prenom="";
    adresse="";
    grade="";
    salaire=0;
    num=0;
    dep="";
}

personnel::personnel(int id_personnel, QString nom,QString prenom,QString adresse,QString grade,int salaire,int num, QString dep)
{
    this->id_personnel=id_personnel;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->grade=grade;
    this->salaire=salaire;
    this->num=num;
    this->dep=dep;
}



bool personnel::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO personnel (id_personnel,nom, prenom,adresse,grade, salaire,num, dep) "
                    "VALUES (:id_personnel, :nom, :prenom,:adresse, :grade, :salaire,:num, :dep)");
query.bindValue(":id_personnel",id_personnel);
query.bindValue(":nom", nom);
query.bindValue(":prenom",prenom);
query.bindValue(":adresse",adresse);
query.bindValue(":grade", grade);
query.bindValue(":salaire",salaire);
query.bindValue(":num",num);
query.bindValue(":dep",dep);

return    query.exec();
}

QSqlQueryModel* personnel::afficher()
{
QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from personnel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_personnel"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr(" nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr(" grade"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("num"));
    return model;
}

bool personnel::supprimer(int id_personnell)
{
QSqlQuery query;
QString res= QString::number(id_personnell);
query.prepare("Delete from personnel where id_personnel= :id_personnel ");
query.bindValue(":id_personnel", res);
return    query.exec();
}
bool personnel::modifier(int id_personnel, QString nom,QString prenom,QString adresse,QString grade,int salaire,int num,QString dep)
{
    QSqlQuery query;
    query.prepare("update personnel set  nom=:nom,prenom=:prenom,adresse=:adresse,grade=:grade,salaire=:salaire,num=:num where id_personnel=:id_personnel");

    qDebug()<<id_personnel<<nom<<prenom<<adresse<<grade<<salaire<<num;
    query.bindValue(":id_personnel",id_personnel);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":grade",grade);
    query.bindValue(":salaire",salaire);
    query.bindValue(":num",num);

    return query.exec();




}

QSqlQueryModel * personnel:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from personnel order by id_personnel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_personnel"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr(" nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr(" grade"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("num"));

    return model;
}

bool personnel::verifierId(int id_personnel)
{

    QSqlQuery query;
    QString n;
    QString  num = QString::number(id_personnel);
            query.exec("SELECT id_personnel from personnel");
            while (query.next())
            {
                n=query.value("id_personnel").toString();
                if (n==num)
                {
                    return true;
                }
            }
    return false;

      }
QSqlQueryModel *personnel::stats()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT salaire, grade,((salaire*100)/(select SUM(salaire) from personnel) from personnel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("grade"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("stats"));

        return model;
}
QSqlQueryModel * personnel::chercher_pers(int id_personnel)
{
    QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
query.prepare(" select * from personnel where id_personnel= ?");
query.addBindValue(id_personnel);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_personnel"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("grade"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("num"));

    return model;
}
