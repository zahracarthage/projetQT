#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"

class departement
{
public:
    departement();
    departement(int id_dep,QString nom_dep,QString nb_emp_dep);


  /* int getid();

   void setremise(int remise);
   int getremise();

   void setnom(QString nom);
   QString getnom();*/

   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int id_depp);
   bool modifier(int id_dep, QString nom_dep,QString nb_emp_dep);
   QSqlQueryModel * chercher_Dep(QString id);
   bool verifierId(int  id_dep);
   QSqlQueryModel *  afficher_tri_ID();
private:
    int id_dep;
    QString nom_dep;
    QString nb_emp_dep;


};
#endif // DEPARTEMENT_H
