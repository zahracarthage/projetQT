#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class emplacement
{
    QString ref, id_v,nom,etat;
public:
    emplacement();
    emplacement(QString REF,QString id,QString nm,QString et);
    void Ajouter();
    bool supprimer(QString id);
    QSqlQueryModel *afficher();
    void modifier();
    QSqlQueryModel *rechercher(QString);
    QSqlQueryModel * tri1();
    QSqlQueryModel * tri2();
};

#endif // EMPLACEMENT_H
