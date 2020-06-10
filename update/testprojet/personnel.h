#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"
class personnel
{
public:
    personnel();
    personnel(int id_personnel, QString nom,QString prenom,QString adresse,QString grade,int salaire,int num, QString dep);

  /* void setid(int id);
   int getid();

   void setremise(int remise);
   int getremise();

   void setnom(QString nom);
   QString getnom();*/

   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int id_personnell);
   bool modifier(int id_personnel, QString nom,QString prenom,QString adresse,QString grade,int salaire,int num, QString dep);
   bool verifierId(int  id_personnel);
   QSqlQueryModel * chercher_pers(int id_personnel);

   QSqlQueryModel *  afficher_tri_ID();
   QSqlQueryModel *  stats();
private:
    int id_personnel;
    QString nom;
    QString prenom;
    QString adresse;
    QString grade;
    int salaire;
    int num;
    QString dep;


};
#endif // PERSONNEL_H
