#ifndef DEPENSES_H
#define DEPENSES_H
#include <QString>
#include <QtMath>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <iostream>
using namespace std;
class depenses
{
    QString REF;
    QString DESCRIPTION;
    QString MONTANT;
    QString DATE;
public:
    depenses();
    depenses(QString REF_DEPENSE,QString DESCRIPTION,QString MONTANT,QString DATE);
    QSqlQueryModel *afficher();
    bool supprimer(QString id);
    void Ajouter();
    void modifier();
    QSqlQueryModel *rechercher(QString);
    QSqlQueryModel * tri1();
    QSqlQueryModel * tri2();
};

#endif // DEPENSES_H
