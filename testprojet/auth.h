#ifndef AUTH_H
#define AUTH_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class auth
{
    QString nom;
    QString prenom;
    int numero;
    QString cin;
    QString role;
    QString pwd;
    QString question_secrete;
    QString rep_qs;
public:
    auth();
    auth(QString, QString, int, QString, QString, QString, QString, QString);



    QString getnom();
    QString getprenom();
    int getnumero ();
    QString getrole();
    QString getcin();
    QString getpwd();
    QString getquestion_secrete();
    QString getrep_qs();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int cin);
    QSqlQueryModel *chercher(QString cin);
    bool modifier();
    bool verifierexcin(QString cin);
    QSqlQueryModel *sortcin();



};

#endif // AUTH_H
