#include <QDebug>
#include "departement.h"
departement::departement()
{
    id_dep=0;
    nom_dep="";
    nb_emp_dep="";
}

departement::departement(int id_dep,QString nom_dep,QString nb_emp_dep)
{
    this->id_dep=id_dep;
    this->nom_dep=nom_dep;
    this->nb_emp_dep=nb_emp_dep;
}



bool departement::ajouter()
{
QSqlQuery query;


query.prepare("INSERT INTO DEPARTEMENT (ID_DEP,NOM_DEP, NB_EMP_DEP) "
                    "VALUES (:id_dep, :nom_dep, :nb_emp_dep)");
query.bindValue(":id_dep",id_dep);
query.bindValue(":nom_dep", nom_dep);
query.bindValue(":nb_emp_dep",nb_emp_dep);

return    query.exec();
}

QSqlQueryModel* departement::afficher()
{
QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from DEPARTEMENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEP"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr(" NOM_DEP"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_EMP_DEP"));
    return model;
}

bool departement::supprimer(int id_depp)
{
QSqlQuery query;
QString res= QString::number(id_depp);
query.prepare("Delete from DEPARTEMENT where ID_DEP= :id_depp ");
query.bindValue(":id_depp", res);
return    query.exec();
}
bool departement::modifier(int id_dep, QString nom_dep,QString nb_emp_dep)
{
    QSqlQuery query;
    query.prepare("update departement set  nom_dep=:nom_dep,nb_emp_dep=:nb_emp_dep where id_dep=:id_dep");

    qDebug()<<id_dep<<nom_dep<<nb_emp_dep;
    query.bindValue(":nom_dep",nom_dep);
    query.bindValue(":nb_emp_dep",nb_emp_dep);
    query.bindValue(":id_dep",id_dep);

    return query.exec();


}
QSqlQueryModel * departement::chercher_Dep(QString id_dep)
{
    QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
id_dep='%'+id_dep+'%';
query.prepare(" select * from departement where id_dep like :id_dep order by id_dep  ");
query.bindValue(":id_dep",id_dep);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID dep"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM dep "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb emp dep"));

    return model;
}
bool departement::verifierId(int id_dep)
{

    QSqlQuery query;
    QString n;
    QString  num = QString::number(id_dep);
            query.exec("SELECT id_dep from departement");
            while (query.next())
            {
                n=query.value("id_dep").toString();
                if (n==num)
                {
                    return true;
                }
            }
    return false;

      }
QSqlQueryModel * departement:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from departement order by id_dep");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID dep"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM dep "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb emp dep"));

    return model;
}

